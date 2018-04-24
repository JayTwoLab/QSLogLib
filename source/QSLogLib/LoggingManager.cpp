// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

#include "LoggingManager.h"
#include "SysUtils.h"
#include "SysUtils.h"

namespace SLogLib {
;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
LoggingManager::LoggingManager()
{
	mIsDisabled = false;
}

LoggingManager::~LoggingManager()
{
	// Delete all LoggingDevices.
	LoggingDeviceList::iterator iter = mLoggingDevices.begin();
	for( ; iter!=mLoggingDevices.end() ; ++iter)
	{
		AbstractLoggingDevice* _device = *iter;
		delete _device;
	}
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void LoggingManager::AddDevice(AbstractLoggingDevice* device)
{
	if(!mIsDisabled && device != NULL)
	{
		mLoggingDevices.push_back(device);
	}
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void LoggingManager::RemoveDevice(AbstractLoggingDevice* device)
{
	if(!mIsDisabled)
	{
		// We don't have to worry about iter becoming invalid 
		// since we exit from loop immediately after erasing.
		LoggingDeviceList::iterator _iter = mLoggingDevices.begin();
		for( ; _iter!=mLoggingDevices.end() ; ++_iter)
		{
			AbstractLoggingDevice* _device = *_iter;
			if(device == _device)
			{
				mLoggingDevices.erase(_iter);
				delete _device;
				return;
			}
		}
	}
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void LoggingManager::RemoveDevice(const std::string& deviceName)
{
	if(!mIsDisabled)
	{
		// We don't have to worry about iterator becoming invalid 
		// since we exit from loop immediately after erasing.
		LoggingDeviceList::iterator _iter = mLoggingDevices.begin();
		for( ; _iter!=mLoggingDevices.end() ; ++_iter)
		{
			AbstractLoggingDevice* _device = *_iter;
			if(deviceName == _device->Name())
			{
				mLoggingDevices.erase(_iter);
				delete _device;
				return;
			}
		}
	}
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
AbstractLoggingDevice* LoggingManager::QueryDevice(const std::string& deviceName)
{
	LoggingDeviceList::iterator _iter = mLoggingDevices.begin();
	for(; _iter!=mLoggingDevices.end() ; ++_iter)
	{
		if(deviceName == (*_iter)->Name())
		{
			return *_iter;
		}
	}
	return NULL;
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void LoggingManager::PushFunction(const std::string& fileName,
	                              const std::string& funcName, 
								  unsigned int       lineNumber)
{
	if(!mIsDisabled)
	{
		mCallStack.push_back(CallInfo(fileName, funcName, lineNumber));
	}
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void LoggingManager::PopFunction()
{
	if(!mIsDisabled)
	{
		mCallStack.pop_back();
	}
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void LoggingManager::WriteMessage(const std::string& fileName, 
	                              const std::string& funcName,
								  unsigned int       lineNumber,
								  unsigned int       level,
								  const std::string& message)
{
	if(!mIsDisabled)
	{
		// Update the call stack.
		mCallStack.push_back(CallInfo(fileName, funcName, lineNumber));
		
		// Generate the message.
		Message _message;
		_message.mUserMessage = message;
		_message.mDateTime    = SLogLib::getLocalDateTime();
		_message.mLevel       = level;
		_message.mCallStack   = &mCallStack;
		_message.mProcessId   = SLogLib::getCurrentProcessID();
		_message.mThreadId    = SLogLib::getCurrentThreadID();
		
		// Iterate over all LoggingDevices and write the message
		// to the enabled devices.
		LoggingDeviceList::iterator iter = mLoggingDevices.begin();
		for( ; iter!=mLoggingDevices.end() ; ++iter)
		{
			AbstractLoggingDevice* _device = *iter;
			if(_device->IsEnabled())
			{
                mMutex.lock(); // lock the mutex

				_device->WriteMessage(_message);

                mMutex.unlock(); // unlock the mutex
			}
		}
		
		// Update the call stack.
		mCallStack.erase(--mCallStack.end());
	}
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

};	// End namespace SLogLib.
