//linux_SerialPort.cpp
//Serial Port classes in a Juce stylee, by graffiti
//see SerialPort.h for details
//
// Updated for current Juce API 8/1/13 Marc Lindahl
//

#include "../JuceLibraryCode/JuceHeader.h"

#if JUCE_LINUX

#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>

#include "Serial.h"

StringPairArray SerialPort::getSerialPortPaths()
{
	StringPairArray SerialPortPaths;
	return SerialPortPaths;
}

bool SerialPort::exists()
{
	return (-1!=portDescriptor);
}
void SerialPort::close()
{
}
bool SerialPort::open(const String & portPath)
{
    return false;
}
bool SerialPort::setConfig(const SerialPortConfig & config)
{
	return false;
}
bool SerialPort::getConfig(SerialPortConfig & config)
{
	return false;
}
/////////////////////////////////
// SerialPortInputStream
/////////////////////////////////
void SerialPortInputStream::run()
{
}
int SerialPortInputStream::read(void *destBuffer, int maxBytesToRead)
{
	return 0;
}
/////////////////////////////////
// SerialPortOutputStream
/////////////////////////////////
void SerialPortOutputStream::run()
{
}
bool SerialPortOutputStream::write(const void *dataToWrite, size_t howManyBytes)
{
	return false;
}

#endif // JUCE_LINUX
