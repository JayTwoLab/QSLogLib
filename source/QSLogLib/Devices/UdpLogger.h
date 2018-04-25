// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

// UdpLogger.h

#ifndef _SLOGLIB_UDPLOGGER_H_
#define _SLOGLIB_UDPLOGGER_H_

#include "QSLogLib/Devices/AbstractLoggingDevice.h"

#include <fstream>
#include <iostream>
#include <string>

#include <QtGlobal>
#include <QUdpSocket>
#include <QHostAddress>

namespace QSLogLib {

    class  UdpLogger : public AbstractLoggingDevice
	{
	public:
		UdpLogger(std::string destAddress, unsigned short port, 
			AbstractFormatter* formatter);
		UdpLogger(std::string destAddress, unsigned short port, 
			AbstractFormatter* formatter, const std::string& name);
		UdpLogger(std::string destAddress, unsigned short port, 
			AbstractFormatter* formatter, const std::string& name, bool isEnabled, bool isBuffered, size_t numBufferedMessages);
		~UdpLogger();

	protected:
		void _Initialize(std::string destAddress, unsigned short port);

	protected:
		void _WriteMessage(const std::string& message);
		void _WriteMessages(const std::vector<std::string>& messages); 
		void _FlushBufferedMessages(); 

	protected:
        QHostAddress DestAddress;
		unsigned short usDestPort; 
        QUdpSocket udpSocket;
	};

}
#endif
