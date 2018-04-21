
#ifndef _SLOGLIB_MESSAGE_H_
#define _SLOGLIB_MESSAGE_H_

#include "QSLogLib/CallInfo.h"
#include "QSLogLib/SysUtils.h"

#include <string>
#include <stdint.h>
#include <inttypes.h>

#include <QDateTime>
#include <QDate>
#include <QTime>

namespace SLogLib {
;

// Levels indicating severity of message.
const int MESSAGE_LEVEL_INFO    = 1;  // For logging general information.
const int MESSAGE_LEVEL_WARNING = 2;  // For logging warnings.
const int MESSAGE_LEVEL_ERROR   = 4;  // For logging error messages.
const int MESSAGE_LEVEL_DEBUG   = 8;  // For logging debugging information.
const int MESSAGE_LEVEL_DETAIL  = 16; // For logging detailed debugging information.

// The Message structure stores a message to be logged.
struct Message
{
	std::string  mUserMessage;
    QDateTime    mDateTime;
	unsigned int mLevel;
	CallStack*   mCallStack; // Don't delete; owned by LoggingManager.
    int64_t mProcessId;
    uint64_t mThreadId;
	
	Message()
		: mLevel(MESSAGE_LEVEL_INFO), mCallStack(0), mProcessId(0), mThreadId(0)
	{}
};

};	// End namespace SLogLib.

#endif // _SLOGLIB_MESSAGE_H_
