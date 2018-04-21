

#include "AbstractLoggingDevice.h"
#include "QSLogLib/SysUtils.h"
#include <cassert>

namespace SLogLib {
;

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
AbstractLoggingDevice::AbstractLoggingDevice(AbstractFormatter* formatter)
	: mFormatter(formatter), mIsEnabled(true), mIsBuffered(false), mNumBufferedMessages(1000)
{
	static int _deviceID = 1;
	mName = "LoggingDevice" + SLogLib::toString(_deviceID++);
	mBufferedMessages.reserve(mNumBufferedMessages);
}
AbstractLoggingDevice::AbstractLoggingDevice(AbstractFormatter* formatter, const std::string& name)
	: mFormatter(formatter), mName(name), mIsEnabled(true), mIsBuffered(false), mNumBufferedMessages(1000)
{
	mBufferedMessages.reserve(mNumBufferedMessages);
}
AbstractLoggingDevice::AbstractLoggingDevice(AbstractFormatter* formatter, const std::string& name, bool isEnabled, bool isBuffered, size_t numBufferedMessages)
	: mFormatter(formatter), mName(name), mIsEnabled(isEnabled), mIsBuffered(isBuffered), mNumBufferedMessages(numBufferedMessages)
{
	mBufferedMessages.reserve(mNumBufferedMessages);
}
AbstractLoggingDevice::~AbstractLoggingDevice()
{
	delete mFormatter;
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void AbstractLoggingDevice::WriteMessage(const Message& message)
{
	if(mIsEnabled && mFormatter!=0)
	{
		if(mIsBuffered)
		{
			if(mBufferedMessages.size() < mNumBufferedMessages)
			{
				mBufferedMessages.push_back(mFormatter->FormatMessage(message));
			}
			if(mBufferedMessages.size() == mNumBufferedMessages)
			{
				_FlushBufferedMessages();
			}
		}
		else
		{
			_WriteMessage(mFormatter->FormatMessage(message));
		}
	}
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void AbstractLoggingDevice::SetIsEnabled(bool x)
{
	mIsEnabled = x;
	
	// If a buffered device is disabled then existing messages should be written.
	if(mIsBuffered && !mIsEnabled)
	{
		_FlushBufferedMessages();
	}
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void AbstractLoggingDevice::SetIsBuffered(bool x)
{
	mIsBuffered = x;
	
	// If buffering is disabled then existing messages should be written.
	if(!mIsBuffered)
	{
		_FlushBufferedMessages();
	}
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void AbstractLoggingDevice::SetNumBufferedMessages(size_t x)
{
	if(x > mNumBufferedMessages)
	{
		mBufferedMessages.reserve(x);
	}
	mNumBufferedMessages = x;
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void AbstractLoggingDevice::_WriteMessages(const std::vector<std::string>& messages)
{
	for(size_t i=0 ; i<messages.size() ; ++i)
	{
		_WriteMessage(messages[i]);
	}
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void AbstractLoggingDevice::_FlushBufferedMessages()
{
	_WriteMessages(mBufferedMessages);
	mBufferedMessages.clear();
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

};	// End namespace SLogLib.
