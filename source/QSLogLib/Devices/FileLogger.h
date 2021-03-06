// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

// FileLoffer.h

#ifndef _SLOGLIB_FILELOGGER_H_
#define _SLOGLIB_FILELOGGER_H_

#include "QSLogLib/Devices/AbstractLoggingDevice.h"

#include <fstream>

namespace QSLogLib {
;

// The FileLogger class writes logging messages to a file.
// 
// The FileLogger writes to a file whose name must be specified while construction and it cannot
// be changed later. For other parameters used for construction refer to AbstractLoggingDevice 
// documentation.
// 
// ofstream uses its own buffers and sometimes string written to it takes time to update. If there
// is a need to see the messaged immediately after writing to the file (for debugging) it is 
// possible to automatically flush the device after every message. By default auto flush is disabled.
// Related functions: EnableAutoFlush(), DisableAutoFlush(), IsAutoFlushEnabled().
// 
// If messages come in too fast then sometimes std::ofstream writes messages in an arbitrary order.
// I have found  that inserting a small delay after writing message fixes this problem. If you have 
// this problem then enable the delay. By default there is no delay in writing messages. The amount
// of delay in milliseconds (default: 10ms) can be specified by SetDelayAmount().
// Related functions: EnableDelay(), DisableDelay(), and HasDelay().
class  FileLogger : public AbstractLoggingDevice
{
public:
	
	FileLogger(const std::string& fileName, AbstractFormatter* formatter);
	FileLogger(const std::string& fileName, AbstractFormatter* formatter, const std::string& name);
	FileLogger(const std::string& fileName, AbstractFormatter* formatter, const std::string& name, bool isEnabled, bool isBuffered, size_t numBufferedMessages);
	~FileLogger();
	
	// std::ofstream itself is a buffered device and string send to it are not immediately written
	// to the file. Calling FlushDevice() forces std::ofstream to write its buffer to the file.
	void FlushDevice();
	
public:
	
	inline std::string fileName() const {return mFileName;}
	
	inline void EnableAutoFlush() {mHasAutoFlush = true;}
	inline void DisableAutoFlush() {mHasAutoFlush = false;}
	inline bool IsAutoFlushEnabled() const {return mHasAutoFlush;}
	
	inline void EnableDelay() {mHasDelay = true;}
	inline void DisableDelay() {mHasDelay = false;}
	inline bool HasDelay() const {return mHasDelay;}	
	
	inline void SetDelayAmount(unsigned int d) {mDelayAmount = d;}
	inline unsigned int DelayAmount() const {return mDelayAmount;}
	
private:
	
	void _Initialize(const std::string& fileName);
	void _WriteMessage(const std::string& message);
	void _WriteMessages(const std::vector<std::string>& messages);
	
private:
	
	std::ofstream mFileHandle;
	std::string   mFileName;
	bool          mHasAutoFlush; // Default: false
	bool          mHasDelay;     // Default: false
	unsigned int  mDelayAmount;  // Default: 10 ms
};

};	// End namespace

#endif // _SLOGLIB_FILELOGGER_H_
