// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

#ifndef _SLOGLIB_MESSAGE_H_
#define _SLOGLIB_MESSAGE_H_

#include <string>
#include <stdint.h>
#include <inttypes.h>

#include <QDateTime>
#include <QDate>
#include <QTime>

#include "QSLogLib/SysUtils.h"

namespace QSLogLib {

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

    int64_t mProcessId;
    uint64_t mThreadId;

    std::string fileName;
    std::string funcName;
    unsigned int lineNumber;
	
	Message()
        : mLevel(MESSAGE_LEVEL_INFO), mProcessId(0), mThreadId(0), lineNumber(0)
	{}
};

};	// End namespace

#endif // _SLOGLIB_MESSAGE_H_
