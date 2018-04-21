
// DetailedFormatter.h

#ifndef _SLOGLIB_DETAILEDFORMATTER_H_
#define _SLOGLIB_DETAILEDFORMATTER_H_

#include "QSLogLib/Formatters/AbstractFormatter.h"
#include <sstream>
#include <iomanip>

#include <QDateTime>
#include <QDate>
#include <QTime>

namespace SLogLib {
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
		size_t _size = msg.mCallStack->size();
		CallInfo _callInfo;
		_callInfo = (*msg.mCallStack)[_size-1];
		
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
		_stream << "FileName   : " << _callInfo.mFileName         << std::endl;
		_stream << "FuncName   : " << _callInfo.mFuncName         << std::endl;
		_stream << "Line No.   : " << _callInfo.mLineNumber       << std::endl;
		_stream << "CallStack  : ";
		
		for(size_t i=0 ; i<msg.mCallStack->size() ; ++i)
		{
			CallInfo _callInfo = (*msg.mCallStack)[i];
			
			if(i==0)
			{
				_stream << _callInfo.mFileName;
			}
			else
			{
				_stream << "             " << _callInfo.mFileName;
			}
			_stream << " : " << _callInfo.mFuncName;
			_stream << " [" << _callInfo.mLineNumber << "]" << std::endl;
		}
		
		_stream << "Message    : " << msg.mUserMessage << std::endl << std::endl;
		return _stream.str();
	}
};

};	// End namespace SLogLib.

#endif // _SLOGLIB_DETAILEDFORMATTER_H_
