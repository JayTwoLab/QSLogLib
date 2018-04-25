//
// main.cpp
//
// LoggingDemo for QSLogLib

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

int main(int argc, char *argv[])
{
    QCoreApplication mainApp(argc, argv);

    // Add these lines at the beginning of your program.
    // The devices and formatters are automatically deleted by SLogLib.
    using namespace QSLogLib;

    addLoggingDevice( new ConsoleLogger(new NullFormatter) );
    addLoggingDevice( new FileLogger("foo.log", new DetailedFormatter) );

    // The following line writes the message to both console and file.
    int a = 10;
    double b = 15.3;
    const char* c = "Success";
    SLOGLIB_LOG_MSG_INFO("a = " << a << " b = " << b);
    SLOGLIB_LOG_MSG_INFO(c);

    return 0;
}
