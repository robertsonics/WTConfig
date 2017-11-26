// **************************************************************************
//     Filename: COMMUNICATOR.CPP
// Date Created: 9/10/2017
//      Version: 0.01
//
//
//  COPYRIGHT (c) Robertsonics 2017. All Rights Reserved
//
// **************************************************************************

#include "Communicator.h"
#include "Serial.h"
#include "Commands.h"


// **************************************************************************
// run
// **************************************************************************
void Communicator::run() {

int i;
unsigned char rxDat;

	// Clear out our receive buffer
	for (i = 0; i < 1024; i++)
		m_rxBuff[i] = 0;
	m_rxPtr = 0;

	m_State = COMM_STARTED;

	// Receive thread main loop
	while (!threadShouldExit()) {

		// Parse the input stream one byte at a time
		while (pInStream->getTotalLength() > 0) {
			pInStream->read((unsigned char *)&rxDat, 1);

			// If we're waiting for the header
			if ((m_rxPtr == 0) && (!m_msgReadyFlag)) {
				if (rxDat == 0xf0)
					m_rxPtr = 1;
			}
			else if (m_rxPtr == 1) {
				if (rxDat == 0xaa)
					m_rxPtr = 2;
				else
					m_rxPtr = 0;
			}

			// If this is the length
			else if (m_rxPtr == 2) {
				if ((rxDat > 0) && (rxDat < MAX_MESSAGE_LENGTH)) {
					m_rxLen = rxDat - 1;
					m_rxBuff[0] = (unsigned char)rxDat - 2;
					m_rxPtr = 3;
				}
				else
					m_rxPtr = 0;
			}

			// Otherwise save in local buffer until last byte
			else if (m_rxPtr > 2) {
				if (m_rxPtr == m_rxLen) {
					if (rxDat == 0x55) {
						m_msgReadyFlag = true;
						sendChangeMessage();
					}
					m_rxPtr = 0;
				}
				else {
					m_rxBuff[m_rxPtr - 2] = rxDat;
					if (++m_rxPtr >= MAX_MESSAGE_LENGTH)
						m_rxPtr = 0;
				}
			}
		}
		sleep(1);

	}

	m_State = COMM_STOPPED;
	return;
}

// **************************************************************************
// openPort
// **************************************************************************
bool Communicator::openPort( String portName )
{

#if WIN32

String portID = "\\\\.\\";

	int i = portName.indexOf("COM");
	if (i >= 0) {
		portID += portName.substring(i, i+5);
		if (portID.contains(")"))
			portID = portID.substring(0, 8);
	}
	pSP = new SerialPort(portID, SerialPortConfig(57600, 8, SerialPortConfig::SERIALPORT_PARITY_NONE, SerialPortConfig::STOPBITS_1, SerialPortConfig::FLOWCONTROL_NONE));

#else

	pSP = new SerialPort(portName, SerialPortConfig(57600, 8, SerialPortConfig::SERIALPORT_PARITY_NONE, SerialPortConfig::STOPBITS_1, SerialPortConfig::FLOWCONTROL_NONE));

#endif

	if (pSP->exists())
	{
		// Create streams for reading/writing
		pOutStream = new SerialPortOutputStream(pSP);
		pInStream = new SerialPortInputStream(pSP);
		m_portOpenFlag = true;
		this->startThread();
		return true;
	}
	else {
		pOutStream = nullptr;
		pInStream = nullptr;
		m_portOpenFlag = false;
		return false;
	}
}

// **************************************************************************
// closePort
// **************************************************************************
void Communicator::closePort(void)
{

	this->stopThread(2000);

	if (pOutStream != nullptr) {
		delete pOutStream;
		pOutStream = nullptr;
	}
	if (pInStream != nullptr) {
		delete pInStream;
		pInStream = nullptr;
	}
	if (pSP != nullptr) {
		pSP->close();
		pSP = nullptr;
	}
	m_portOpenFlag = false;
}

// **************************************************************************
// getDeviceInfo
// **************************************************************************
bool Communicator::getDeviceInfo(void) {

unsigned char xbuf[8];

	if (pSP == nullptr)
		return false;

	// First, send the get version command
	xbuf[0] = 0xF0;
	xbuf[1] = 0xaa;
	xbuf[2] = 0x05;
	xbuf[3] = GET_VERSION;
	xbuf[4] = 0x55;
	pOutStream->write(xbuf, 5);

	// Wait a bit...
	sleep(200);

	// Then send the get info command
	xbuf[3] = GET_SYS_INFO;
	pOutStream->write(xbuf, 5);
	return true;
}

// **************************************************************************
// stopAll
// **************************************************************************
bool Communicator::stopAll(void) {

unsigned char xbuf[8];

	if (pSP == nullptr)
		return false;

	// First, send the get version command
	xbuf[0] = 0xF0;
	xbuf[1] = 0xaa;
	xbuf[2] = 0x05;
	xbuf[3] = STOP_ALL;
	xbuf[4] = 0x55;
	pOutStream->write(xbuf, 5);

	return true;
}

// **************************************************************************
// setInputMix
// **************************************************************************
bool Communicator::setInputMix(int mix) {

	unsigned char xbuf[8];

	if (pSP == nullptr)
		return false;

	if (m_mode == MODE_WAV_TRIGGER)
		return false;

	xbuf[0] = 0xF0;
	xbuf[1] = 0xaa;
	xbuf[2] = 0x06;
	xbuf[3] = CMD_SET_INPUT_MIX;
	xbuf[4] = (unsigned char)(mix & 0x0f);
	xbuf[5] = 0x55;
	pOutStream->write(xbuf, 6);

	return true;
}

// **************************************************************************
// setInputMix
// **************************************************************************
bool Communicator::setAmpEnable(bool ena) {

	unsigned char xbuf[8];

	if (pSP == nullptr)
		return false;

	if (m_mode != MODE_WAV_TRIGGER)
		return false;

	xbuf[0] = 0xF0;
	xbuf[1] = 0xaa;
	xbuf[2] = 0x06;
	xbuf[3] = CMD_AMP_POWER;
	if (ena)
		xbuf[4] = 0x01;
	else
		xbuf[4] = 0x00;
	xbuf[5] = 0x55;
	pOutStream->write(xbuf, 6);

	return true;
}

// **************************************************************************
// volume
// **************************************************************************
bool Communicator::volume(int iVol, int iOut) {

unsigned char xbuf[8];
unsigned short uVal;

	if (pSP == nullptr)
		return false;

	xbuf[0] = 0xF0;
	xbuf[1] = 0xaa;
	xbuf[3] = VOLUME;

	uVal = (unsigned short)iVol;

	if (m_mode == MODE_WAV_TRIGGER) {
		xbuf[2] = 0x07;
		xbuf[4] = (unsigned char)uVal;
		xbuf[5] = (unsigned short)(uVal >> 8);
		xbuf[6] = 0x55;
		pOutStream->write(xbuf, 7);
	}
	else {
		xbuf[2] = 0x08;
		xbuf[4] = (unsigned char)(iOut & 0x0f);
		xbuf[5] = (unsigned char)uVal;
		xbuf[6] = (unsigned short)(uVal >> 8);
		xbuf[7] = 0x55;
		pOutStream->write(xbuf, 8);
	}

	return true;
}

// **************************************************************************
// controlTrack
// **************************************************************************
bool Communicator::controlTrack(int mode, int trackNum) {

unsigned char xbuf[8];

	if (pSP == nullptr)
		return false;

	if (trackNum > 999)
		return false;

	// First, 
	xbuf[0] = 0xF0;
	xbuf[1] = 0xaa;
	xbuf[2] = 0x08;
	xbuf[3] = CONTROL_TRACK;
	xbuf[4] = (unsigned char)mode;
	xbuf[5] = (unsigned char)trackNum;
	xbuf[6] = (unsigned char)(trackNum >> 8);
	xbuf[7] = 0x55;
	pOutStream->write(xbuf, 8);
	return true;
}

// **************************************************************************
// SetTrigger
// **************************************************************************
bool Communicator::setTrigger(TRIGGER_STRUCTURE *pTrig) {

unsigned char xbuf[24];

	if ((pTrig->num < 1) || (pTrig->num > 16))
		return false;

	if (m_mode != MODE_WAV_TRIGGER) {
		xbuf[0] = 0xF0;
		xbuf[1] = 0xaa;
		xbuf[2] = 14;
		xbuf[3] = TRIGGER_SET;
		xbuf[4] = (unsigned char)pTrig->num - 1;
		xbuf[5] = (unsigned char)pTrig->flags;
		xbuf[6] = (unsigned char)pTrig->gain;
		xbuf[7] = (unsigned char)pTrig->output;
		xbuf[8] = (unsigned char)pTrig->function;
		xbuf[9] = (unsigned char)pTrig->low;
		xbuf[10] = (unsigned char)(pTrig->low >> 8);
		xbuf[11] = (unsigned char)pTrig->high;
		xbuf[12] = (unsigned char)(pTrig->high >> 8);
		xbuf[13] = 0x55;
		pOutStream->write(xbuf, 14);
	}
	else {
		xbuf[0] = 0xF0;
		xbuf[1] = 0xaa;
		xbuf[2] = 17;
		xbuf[3] = TRIGGER_SET;
		xbuf[4] = (unsigned char)pTrig->num - 1;

		//xbuf[5] = (unsigned char)tsPtr->hardware;
		if (pTrig->flags & TRIG_FLAGS_INTERFACE)
			xbuf[5] = 0x01;
		else
			xbuf[5] = 0x00;

		//xbuf[6] = (unsigned char)tsPtr->invert;
		if (pTrig->flags & TRIG_FLAGS_INVERT)
			xbuf[6] = 0x01;
		else
			xbuf[6] = 0x00;

		//xbuf[7] = (unsigned char)tsPtr->type;
		xbuf[7] = (unsigned char)((pTrig->flags & 0x03) + 1);

		//xbuf[8] = (unsigned char)tsPtr->retrigger;
		if (pTrig->flags & TRIG_FLAGS_RETRIGGER)
			xbuf[8] = 0x01;
		else
			xbuf[8] = 0x00;
		if (pTrig->flags & TRIG_FLAGS_LOOP)
			xbuf[8] |= 0x02;
		if (pTrig->flags & TRIG_FLAGS_LOCK)
			xbuf[8] |= 0x04;

		//xbuf[9] = (unsigned char)tsPtr->polyphonic;
		if (pTrig->flags & TRIG_FLAGS_POLY)
			xbuf[9] = 0x01;
		else
			xbuf[9] = 0x00;

		xbuf[10] = (unsigned char)pTrig->function;
		xbuf[11] = (unsigned char)pTrig->gain;
		xbuf[12] = (unsigned char)pTrig->low;
		xbuf[13] = (unsigned char)(pTrig->low >> 8);
		xbuf[14] = (unsigned char)pTrig->high;
		xbuf[15] = (unsigned char)(pTrig->high >> 8);
		xbuf[16] = 0x55;
		pOutStream->write(xbuf, 17);
	}
	return true;
}

// **************************************************************************
// getMessage
// **************************************************************************
int Communicator::getMessage(unsigned char * pDest) {

int dLen;

	dLen = (int)m_rxBuff[0];
	if (dLen >= MAX_MESSAGE_LENGTH)
		return 0;
	memcpy(pDest, &m_rxBuff[1], dLen);
	return dLen;
}

// **************************************************************************
// Free state
// **************************************************************************
Communicator::~Communicator()
{
	stopThread (2000);	
} // end Communicator::~Communicator()



