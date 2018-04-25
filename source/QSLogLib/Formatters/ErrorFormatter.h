// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

#ifndef _SLOGLIB_ERRORFORMATTER_H_
#define _SLOGLIB_ERRORFORMATTER_H_

#include "QSLogLib/Formatters/AbstractFormatter.h"

#include <sstream>
#include <iomanip>

#include <QDateTime>
#include <QDate>
#include <QTime>

namespace QSLogLib {
;

// The ErrorFormatter class formats only error messages and ignores all other messages.
// A message is formatted as: 
// Time       : Year-Month-Day Hour:Minutes:Seconds:Millisecond
// FileName   : 
// FuncName   : 
// Line No.   : 
// Message    : message line 1
//              message line 2
//              .
//              .
class ErrorFormatter : public AbstractFormatter
{
public:
	
	inline std::string FormatMessage(const Message& msg) const
	{
		if(msg.mLevel != MESSAGE_LEVEL_ERROR)
		{
			return "";
		}
		
		std::ostringstream _stream;
		_stream.fill('0');
		_stream.width(2);
		
		if(msg.mUserMessage == "\n")
		{
			_stream << std::endl;
		}
		else
		{
            _stream << "Time       : " << msg.mDateTime.date().year()         << "-"
                                       << msg.mDateTime.date().month()        << "-"
                                       << msg.mDateTime.date().day()          << " "
                                       << msg.mDateTime.time().hour()         << ":"
                                       << msg.mDateTime.time().minute()       << ":"
                                       << msg.mDateTime.time().second()       << ":"
                                       << msg.mDateTime.time().msec()
                                       << std::endl;

            _stream << "File Name  : " << msg.fileName               << std::endl;
            _stream << "Func Name  : " << msg.funcName               << std::endl;
            _stream << "Line No.   : " << msg.lineNumber              << std::endl;

			std::string _temp = msg.mUserMessage;
			size_t      _loc   = _temp.find("\n");
			while(_loc != std::string::npos)
			{
				_temp.insert(_loc+1, "          ");
				_loc = _temp.find("\n", _loc + 10);
			}
			
			_stream << "Message    : " << _temp << std::endl << std::endl;
		}
		
		return _stream.str();
	}
};

};	// End namespace

#endif // _SLOGLIB_ERRORFORMATTER_H_
