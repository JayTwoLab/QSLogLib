// QWidgetLogger.h 

#ifndef QWIDGETLOGGER_H
#define QWIDGETLOGGER_H

#include <QtGlobal>
#include <QWidget>
#include <QTextEdit>

#include "QSLogLib/Devices/AbstractLoggingDevice.h"

class QWidgetLogger : public QWidget, public QSLogLib::AbstractLoggingDevice
{
	Q_OBJECT
	
public:
	
    QWidgetLogger(QSLogLib::AbstractFormatter* formatter);
    QWidgetLogger(QSLogLib::AbstractFormatter* formatter, const std::string& name);
    QWidgetLogger(QSLogLib::AbstractFormatter* formatter, const std::string& name, bool isEnabled, bool isBuffered, size_t numBufferedMessages);
	~QWidgetLogger();
	
private:
	
	// Write a single message to the logging device.
	void _WriteMessage(const std::string& message);

	void _Initialize();
	
private:
	
	QTextEdit* mTextEdit;
};

#endif // QWIDGETLOGGER_H
