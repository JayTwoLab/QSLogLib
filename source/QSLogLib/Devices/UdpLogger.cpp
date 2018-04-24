// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

//
// UdpLogger.cpp
//

#include "QSLogLib/Devices/UdpLogger.h"
#include "QSLogLib/SysUtils.h"

#include <QtGlobal>
#include <QString>
#include <QUdpSocket>
#include <QHostAddress>
#include <QByteArray>

namespace SLogLib { 

//------------------------------------------------------------------------
UdpLogger::UdpLogger(std::string destAddress, unsigned short port,
	AbstractFormatter* formatter)
	: AbstractLoggingDevice(formatter)
{
	_Initialize(destAddress, port);
}

//------------------------------------------------------------------------
UdpLogger::UdpLogger(std::string destAddress, unsigned short port,
	AbstractFormatter* formatter, const std::string& name)
	: AbstractLoggingDevice(formatter, name)
{
	_Initialize(destAddress, port);
}

//------------------------------------------------------------------------
UdpLogger::UdpLogger(std::string destAddress, unsigned short port,
	AbstractFormatter* formatter, const std::string& name, bool isEnabled, bool isBuffered, size_t numBufferedMessages)
	: AbstractLoggingDevice(formatter, name, isEnabled, isBuffered, numBufferedMessages)
{
	_Initialize(destAddress, port);
}

//------------------------------------------------------------------------
UdpLogger::~UdpLogger()
{
}

//------------------------------------------------------------------------
void UdpLogger::_Initialize(std::string destAddress, unsigned short port)
{
    QString strAddr = QString::fromStdString( destAddress );
    DestAddress.setAddress( strAddr );

    usDestPort = port;
}

//------------------------------------------------------------------------
void UdpLogger::_WriteMessage(const std::string& message)
{
    QByteArray ba = QByteArray::fromStdString(message);
    qint64 ret = udpSocket.writeDatagram( ba, DestAddress, usDestPort );
    qDebug() << " retuen value of udp socket : "<< ret ;
}

//------------------------------------------------------------------------
void UdpLogger::_WriteMessages(const std::vector<std::string>& messages)
{
    for(size_t i=0 ; i<messages.size() ; ++i)
    {
        std::string strMsg = messages[i];

        QByteArray ba = QByteArray::fromStdString(strMsg);
        qint64 ret = udpSocket.writeDatagram( ba, DestAddress, usDestPort );
    }
}

//------------------------------------------------------------------------
void UdpLogger::_FlushBufferedMessages()
{
}

//------------------------------------------------------------------------
} // end of namespace SLogLib
