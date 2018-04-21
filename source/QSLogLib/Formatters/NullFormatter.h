
#ifndef _SLOGLIB_NULLFORMATTER_H_
#define _SLOGLIB_NULLFORMATTER_H_

#include "QSLogLib/Formatters/AbstractFormatter.h"

#include <sstream>

namespace SLogLib {
;

// The NullFormatter class simply returns the user message and ignores all other fields in the 
// message.
// By default NullFormatter doest insert new line after the message. To insert new lines after
// each message pass true to the constructor.
class NullFormatter : public AbstractFormatter
{
public:
	
	NullFormatter(NewLineFlag newLineFlag = DoNotAppendNewLine) : AbstractFormatter(newLineFlag)
	{}

	inline std::string FormatMessage(const Message& msg) const
	{
		if(mNewLineFlag == AppendNewLine)
		{
			std::ostringstream _stream;
			_stream << msg.mUserMessage << std::endl;
			return _stream.str();
		}
		else
		{
			return msg.mUserMessage;
		}
	}
};

};	// End namespace SLogLib.

#endif // _SLOGLIB_NULLFORMATTER_H_
