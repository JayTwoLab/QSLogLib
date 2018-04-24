// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

#ifndef _SLOGLIB_LOGGINGMANAGER_H_
#define _SLOGLIB_LOGGINGMANAGER_H_

// #include <QMutex>

#include "QSLogLib/AddToCallStack.h"
#include "QSLogLib/Devices/AbstractLoggingDevice.h"

namespace SLogLib {

// WARN: LoggingManager is not thread-safe!
// TODO: make it thread-safe.
class  LoggingManager
{
public:
	
	// Return the only instance of LoggingManager.
	static LoggingManager& Instance()
	{
		static LoggingManager _singleton;
		return _singleton;
	}

	// Add a new logging device. The device is owned by the logging manager and is automatically 
	// deleted when LoggingManager is destructed.
	void AddDevice(AbstractLoggingDevice* device);
	
	// Remove an existing logging device.
	void RemoveDevice(AbstractLoggingDevice* device);
	void RemoveDevice(const std::string& deviceName);
	
	// Get a pointer to the logging device from name.
	AbstractLoggingDevice* QueryDevice(const std::string& deviceName);

    /*
	// Push a function to the current call stack.
	void PushFunction(const std::string& fileName, 
		              const std::string& funcName,  
					  unsigned int       lineNumber);
	
	// Pop the topmost function from the call stack.
	void PopFunction();
    */

// LogThread
	// Write the message to all enabled logging devices.
	void WriteMessage(const std::string& fileName, 
		              const std::string& funcName, 
					  unsigned int       lineNumber,
					  unsigned int       level,
					  const std::string& message);

// LogThread::WriteMessage() : TO-MAKE
// LoggingManager::WriteMessage()
	
	// Destruct the logger.
	~LoggingManager();
	
public:
	
	inline void EnableLogging() {mIsDisabled = false;}
	inline void DisableLogging() {mIsDisabled = true;}
	inline void setIsDisabled(bool d) {mIsDisabled = d;}
	inline bool isDisabled() const  {return mIsDisabled;}
	
private:
	
	// Disable construction and copying of LoggingManager instances in the client code.
	// This makes sure there is only one instance of the logger.
	LoggingManager();
	LoggingManager(const LoggingManager&);
	LoggingManager& operator=(const LoggingManager&);
	
private:
	
	// For storing the list of logging devices.
	LoggingDeviceList mLoggingDevices;

    // If true then disable logging.
    bool mIsDisabled;

// LogThread
	// For storing the current call stack.
    CallStack mCallStack; // NOTE: call stack is needed for every thread!!

// vector of LogThread

};

};	// End namespace SLogLib.

#endif // _SLOGLIB_LOGGINGMANAGER_H_
