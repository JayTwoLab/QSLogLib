// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

#ifndef _SLOGLIB_LOGGING_H_
#define _SLOGLIB_LOGGING_H_

#include <sstream>
#include <string>

#include "QSLogLib/LoggingManager.h"
#include "QSLogLib/Devices/AbstractLoggingDevice.h"

#if !defined(SLOGLIB_DISABLE_LOGGING)
	// The macro to write the message to all logging devices.
	// level is the message level.
	// msg is the message to write to logging devices.
	#define SLOGLIB_LOG_MESSAGE(level, msg)         \
	{                                                    \
		unsigned int _lineNo = __LINE__;                 \
		std::ostringstream __stream__unique__;           \
		__stream__unique__ << msg;                       \
        QSLogLib::writeMessage(__FILE__,                  \
                              __FUNCTION__,              \
							  _lineNo,                   \
							  level,                     \
							  __stream__unique__.str()); \
	}
	
	// Convenience macros to write the message at various levels.
    #define SLOGLIB_LOG_MSG_INFO(msg)   SLOGLIB_LOG_MESSAGE(QSLogLib::MESSAGE_LEVEL_INFO   , msg);
    #define SLOGLIB_LOG_MSG_WARN(msg)   SLOGLIB_LOG_MESSAGE(QSLogLib::MESSAGE_LEVEL_WARNING, msg);
    #define SLOGLIB_LOG_MSG_ERROR(msg)  SLOGLIB_LOG_MESSAGE(QSLogLib::MESSAGE_LEVEL_ERROR  , msg);
    #define SLOGLIB_LOG_MSG_DEBUG(msg)  SLOGLIB_LOG_MESSAGE(QSLogLib::MESSAGE_LEVEL_DEBUG  , msg);
    #define SLOGLIB_LOG_MSG_DETAIL(msg) SLOGLIB_LOG_MESSAGE(QSLogLib::MESSAGE_LEVEL_DEBUG  , msg);
	
	// The macro to add the current function to the call stack.
	#define SLOGLIB_ADD_TO_CALLSTACK SLogLib::AddToCallStack \
	logger_unique_var_name##__LINE__(__FILE__, __FUNCTION__, __LINE__);
#else
	#define SLOGLIB_LOG_MESSAGE(traceLevel, msg)
	#define SLOGLIB_LOG_MSG_INFO(msg)
	#define SLOGLIB_LOG_MSG_WARN(msg)
	#define SLOGLIB_LOG_MSG_ERROR(msg)
	#define SLOGLIB_LOG_MSG_DEBUG(msg)
	#define SLOGLIB_LOG_MSG_DETAIL(msg)
	#define SLOGLIB_ADD_TO_CALLSTACK
#endif

namespace QSLogLib {

// Add a new logging device.
 void addLoggingDevice(AbstractLoggingDevice* device);

// Remove a logging device.
 void removeLoggingDevice(AbstractLoggingDevice* device);
 void removeLoggingDevice(const std::string& name);

// Get a pointer to the logging device from name.
// Returned pointer must not be deleted or changed.
 AbstractLoggingDevice* queryLoggingDevice(const std::string& name);

// Write a message to all active logging devices.
 void writeMessage(const std::string& fileName,
	                              const std::string& funcName,
								  unsigned int       lineNo,
								  unsigned int       level,
								  const std::string& msg);

// Disable and enable logging. These functions are useful when logging has to
// be enabled or disabled at runtime.
 void disableLogging();
 void enableLogging();
 bool isLoggingEnabled();

};	// End namespace

#endif // _SLOGLIB_LOGGINGMANAGER_H_
