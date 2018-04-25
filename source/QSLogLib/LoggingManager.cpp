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

namespace QSLogLib {


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
void LoggingManager::WriteMessage(const std::string& fileName, 
	                              const std::string& funcName,
								  unsigned int       lineNumber,
								  unsigned int       level,
								  const std::string& message)
{
	if(!mIsDisabled)
	{
		// Update the call stack.
        // mCallStack.push_back(CallInfo(fileName, funcName, lineNumber));
		
		// Generate the message.
		Message _message;
		_message.mUserMessage = message;
        _message.mDateTime    = QSLogLib::getLocalDateTime();
		_message.mLevel       = level;
        _message.mProcessId   = QSLogLib::getCurrentProcessID();
        _message.mThreadId    = QSLogLib::getCurrentThreadID();

        _message.fileName = fileName;
        _message.funcName = funcName;
        _message.lineNumber = lineNumber;
		
		// Iterate over all LoggingDevices and write the message
		// to the enabled devices.
		LoggingDeviceList::iterator iter = mLoggingDevices.begin();
		for( ; iter!=mLoggingDevices.end() ; ++iter)
		{
			AbstractLoggingDevice* _device = *iter;
            if ( NULL == _device )
                continue;

            if ( _device->IsEnabled() )
			{
                mMutex.lock();
				_device->WriteMessage(_message);
                mMutex.unlock();
			}
		}


	}
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

};	// End namespace
