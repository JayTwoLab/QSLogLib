// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

#include "QSLogLib/Devices/FileLogger.h"
#include "QSLogLib/SysUtils.h"

namespace SLogLib {
;

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
FileLogger::FileLogger(const std::string& fileName, AbstractFormatter* formatter)
	: AbstractLoggingDevice(formatter)
{
	_Initialize(fileName);
}
FileLogger::FileLogger(const std::string& fileName, AbstractFormatter* formatter, const std::string& name) 
		: AbstractLoggingDevice(formatter, name)
{
	_Initialize(fileName);
}
FileLogger::FileLogger(const std::string& fileName, AbstractFormatter* formatter, const std::string& name, bool isEnabled, bool isBuffered, size_t numBufferedMessages)
	: AbstractLoggingDevice(formatter, name, isEnabled, isBuffered, numBufferedMessages)
{
	_Initialize(fileName);
}
void FileLogger::_Initialize(const std::string& fileName)
{
	mFileHandle.open(fileName.c_str());
	mHasAutoFlush = false;
	mHasDelay     = false;
	mDelayAmount  = 10; // ms.
}
FileLogger::~FileLogger()
{
	_FlushBufferedMessages();
	mFileHandle.close();
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void FileLogger::FlushDevice()
{
	mFileHandle.flush();
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void FileLogger::_WriteMessage(const std::string& message)
{
	if(mHasDelay)
	{
		SLogLib::sleep(mDelayAmount);
	}
	
	mFileHandle << message;
	
	if(mHasAutoFlush)
	{
		FlushDevice();
	}
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void FileLogger::_WriteMessages(const std::vector<std::string>& messages)
{
	if(mHasDelay)
	{
		SLogLib::sleep(mDelayAmount);
	}
	
	for(size_t i=0 ; i<messages.size() ; ++i)
	{
		mFileHandle << messages[i];
	}
	
	if(mHasAutoFlush)
	{
		FlushDevice();
	}
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

};	// End namespace SLogLib.
