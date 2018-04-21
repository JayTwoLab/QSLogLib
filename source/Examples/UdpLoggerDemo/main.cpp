
// main.cpp

#include <QtGlobal>
#include <QCoreApplication>

#include "QSLogLib/SLogLib.h"
#include "QSLogLib/Devices/AbstractLoggingDevice.h"
#include "QSLogLib/Devices/ConsoleLogger.h"
#include "QSLogLib/Devices/FileLogger.h"
#include "QSLogLib/Devices/UdpLogger.h"
#include "QSLogLib/Formatters/AbstractFormatter.h"
#include "QSLogLib/Formatters/DetailedFormatter.h"
#include "QSLogLib/Formatters/ErrorFormatter.h"
#include "QSLogLib/Formatters/InfoFormatter.h"
#include "QSLogLib/Formatters/NullFormatter.h"

int main()
{
	// Add these lines at the beginning of your program.
	// The devices and formatters are automatically deleted by SLogLib.
	using namespace SLogLib;

    std::string strDestAddress = "192.168.137.1";
    unsigned short destPort = 5000;
	addLoggingDevice(new UdpLogger(strDestAddress, destPort, new NullFormatter));

	// The following line writes the message to both console and file.
	int a = 10;
	double b = 15.3;
	const char* c = "Success";
	SLOGLIB_LOG_MSG_INFO("a = " << a << " b = " << b);
	SLOGLIB_LOG_MSG_INFO(c);

	return 0;
}
