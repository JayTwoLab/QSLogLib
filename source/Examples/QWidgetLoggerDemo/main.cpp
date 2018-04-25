
// main.cpp

#include <QtGlobal>
#include <QApplication>

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

#include "QWidgetLogger.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
    QWidgetLogger* _logger = new QWidgetLogger(new QSLogLib::DetailedFormatter());
	_logger->show();
    QSLogLib::addLoggingDevice(_logger);
	
	SLOGLIB_LOG_MSG_INFO("Testing 1");
	SLOGLIB_LOG_MSG_INFO("Testing 2");
	SLOGLIB_LOG_MSG_INFO("Testing 3");
	
	return a.exec();
}
