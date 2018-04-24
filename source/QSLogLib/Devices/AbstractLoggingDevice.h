// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

// AbstractLoggingDevice.h

#ifndef _SLOGLIB_ABSTRACTLOGGINGDEVICE_H_
#define _SLOGLIB_ABSTRACTLOGGINGDEVICE_H_

#include "QSLogLib/Message.h"
#include "QSLogLib/Formatters/AbstractFormatter.h"

#include <string>
#include <list>
#include <vector>

namespace SLogLib {

class  AbstractLoggingDevice
{
public:
	
	AbstractLoggingDevice(AbstractFormatter* formatter);
	AbstractLoggingDevice(AbstractFormatter* formatter, const std::string& name);
	AbstractLoggingDevice(AbstractFormatter* formatter, const std::string& name, bool isEnabled, bool isBuffered, size_t numBufferedMessages);
	virtual ~AbstractLoggingDevice();
	
	// Format the message and write it to the device.
	// For a buffered device, the message may not be immediately written to the device.
	// This function is called by the LoggingManager to write a message to the device.
	void WriteMessage(const Message& message);
	
public: // Getters and setters.
	
	inline std::string Name() const {return mName;}
	
	inline void Enable()  {SetIsEnabled(true);}
	inline void Disable() {SetIsEnabled(false);}
	inline bool IsEnabled() const {return mIsEnabled;}
	void SetIsEnabled(bool x);
	
	inline void EnableBuffering()  {SetIsBuffered(true);}
	inline void DisableBuffering() {SetIsBuffered(false);}
	inline bool IsBuffered() const {return mIsBuffered;}
	void SetIsBuffered(bool x);
	
	inline size_t numBufferedMessages() const {return mNumBufferedMessages;}
	void SetNumBufferedMessages(size_t x);
	
protected:
	
	// Write a single message to the logging device.
	virtual void _WriteMessage(const std::string& message) = 0;
	
	// Write an array of messages to the logging device.
	// The default implementation simply calls _WriteMessage() for each message.
	// If it is possible to write set of messages faster than using _WriteMessage() iteratively
	// than override this function.
	virtual void _WriteMessages(const std::vector<std::string>& messages);
	
	// Flush the currently buffered messages to the device.
	// For a buffered device, concrete class must call this in the destructor to ensure 
	// all messages are written to the device.
	void _FlushBufferedMessages();
	
private:
	
	AbstractFormatter*       mFormatter;
	std::string              mName;
	bool                     mIsEnabled; // Default: true
	bool                     mIsBuffered; // Default: false
	size_t                   mNumBufferedMessages; // Default: 1000
	std::vector<std::string> mBufferedMessages;
};

// Define a type for storing logging devices.
typedef std::list<AbstractLoggingDevice*> LoggingDeviceList;

};	// namespace SLogLib {

#endif // _SLOGLIB_ABSTRACTLOGGINGDEVICE_H_
