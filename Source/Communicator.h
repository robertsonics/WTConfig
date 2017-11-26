// **************************************************************************
//     Filename: COMMUNICATOR.H
// Date Created: 9/10/2017
//      Version: 0.01
//
//
//  COPYRIGHT (c) Robertsonics 2017. All Rights Reserved
//
// **************************************************************************

#ifndef __COMM_H_3000605__
#define __COMM_H_3000605__

#include "../JuceLibraryCode/JuceHeader.h"
//#include "../../../../juce/modules/juce_core/time/juce_Time.h"
#include "Serial.h"
#include "config.h"

#define MAX_MESSAGE_LENGTH	32

#define COMM_STOPPED		0
#define COMM_STARTED		1

class Communicator : public Thread, public ChangeBroadcaster {

public:
	Communicator() : Thread ("Communicator Thread") {
		m_State = COMM_STOPPED;
		m_portOpenFlag = false;
		pSP = nullptr;
		pInStream = nullptr;
		pOutStream = nullptr;
		m_msgReadyFlag = false;
		m_mode = MODE_TSUNAMI_STEREO;
	}
	~Communicator();
	void run();
	bool openPort(String portName);
	void closePort(void);
	bool getDeviceInfo();
	bool controlTrack(int mode, int trackNum);
	bool volume(int iVol, int iOut);
	bool stopAll(void);
	bool setTrigger(TRIGGER_STRUCTURE *pTrig);
	bool setInputMix(int mix);
	bool setAmpEnable(bool ena);
	int getState()				{ return m_State; }
	bool isPortOpen()			{ return m_portOpenFlag; }
	bool isMsgReady()			{ return m_msgReadyFlag; }
	void clearMsgReady()		{ m_msgReadyFlag = false; }
	void setMode(int m)		    { m_mode = m; }
	int getMessage(unsigned char * pDest);
			
private:

	SerialPort *pSP;
	SerialPortOutputStream *pOutStream;
	SerialPortInputStream *pInStream;

	Time *pTime;

	int m_mode;
	int m_State;
	bool m_portOpenFlag;

	bool m_msgReadyFlag;
	unsigned char m_rxBuff[1024];
	int m_rxPtr;
	int m_rxLen;

}; // end class Communicator

#endif
