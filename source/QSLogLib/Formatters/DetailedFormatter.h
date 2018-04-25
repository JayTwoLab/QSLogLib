// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

// DetailedFormatter.h

#ifndef _SLOGLIB_DETAILEDFORMATTER_H_
#define _SLOGLIB_DETAILEDFORMATTER_H_

#include "QSLogLib/Formatters/AbstractFormatter.h"
#include <sstream>
#include <iomanip>

#include <QDateTime>
#include <QDate>
#include <QTime>

namespace QSLogLib {
;

// The DetailedFormatter class formats all messages. A message is formatted as: 
// Msg Level  : 
// Time       : Year-Month-Day Hour:Minutes:Seconds:Millisecond
// Process ID : 
// Thread ID  : 
// FileName   : 
// FuncName   : 
// Line No.   : 
// CallStack  : FileName : FunctionName [Line number]
//              FileName : FunctionName [Line number]
//              .
//              .
// Message    : message line 1
//              message line 2
//              .
//              .
class DetailedFormatter : public AbstractFormatter
{
public:
	
	inline std::string FormatMessage(const Message& msg) const
	{
		std::ostringstream _stream;

		_stream << "Msg Level  : " << msg.mLevel                  << std::endl;

        _stream << "Time       : " << msg.mDateTime.date().year()         << "-"
                                   << msg.mDateTime.date().month()        << "-"
                                   << msg.mDateTime.date().day()          << " "
                                   << msg.mDateTime.time().hour()         << ":"
                                   << msg.mDateTime.time().minute()       << ":"
                                   << msg.mDateTime.time().second()       << ":"
                                   << msg.mDateTime.time().msec()
                                   << std::endl;

		_stream << "Process ID : " << msg.mProcessId              << std::endl;
		_stream << "Thread ID  : " << msg.mThreadId               << std::endl;

        _stream << "File Name  : " << msg.fileName               << std::endl;
        _stream << "Func Name  : " << msg.funcName               << std::endl;
        _stream << "Line No.   : " << msg.lineNumber               << std::endl;
		
		_stream << "Message    : " << msg.mUserMessage << std::endl << std::endl;

		return _stream.str();
	}
};

};	// End namespace

#endif // _SLOGLIB_DETAILEDFORMATTER_H_
