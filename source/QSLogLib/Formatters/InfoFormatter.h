
#ifndef _SLOGLIB_INFOFORMATTER_H_
#define _SLOGLIB_INFOFORMATTER_H_

#include "QSLogLib/Formatters/AbstractFormatter.h"
#include <sstream>
#include <iomanip>

namespace SLogLib {
;

// The InfoFormatter class formats only informational messages and ignores all other messages.
// A message is formatted as: 
// Hour:Minutes:Seconds:Millisecond    message line 1
//                                     message line 2
//                                     .
//                                     .
class InfoFormatter : public AbstractFormatter
{
public:
	
	inline std::string FormatMessage(const Message& msg) const
	{
		if(msg.mLevel != MESSAGE_LEVEL_INFO)
		{
			return "";
		}
		
		std::ostringstream _stream;
		_stream.fill('0');
		_stream.width(2);
		
		// Newlines are written as new lines without date time.
		if(msg.mUserMessage == "\n")
		{
			_stream << std::endl;
		}
		else
		{
			_stream.fill('0');
            _stream << std::setw(2) << msg.mDateTime.time().hour()         << ":"
                    << std::setw(2) << msg.mDateTime.time().minute()       << ":"
                    << std::setw(2) << msg.mDateTime.time().second()       << ":"
                    << std::setw(3) << msg.mDateTime.time().msec()
                    << "    ";
			
			size_t      _padSize = 16;
			std::string _temp    = msg.mUserMessage;
			size_t      _loc     = _temp.find("\n");
			while(_loc != std::string::npos)
			{
				_temp.insert(_loc+1, _padSize, ' ');
				_loc = _temp.find("\n", _loc + _padSize);
			}
			_stream << _temp << std::endl;
		}
		
		return _stream.str();
	}
};

};	// End namespace SLogLib.

#endif // _SLOGLIB_INFOFORMATTER_H_
