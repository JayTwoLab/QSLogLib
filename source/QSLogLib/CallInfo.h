// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

#ifndef _SLOGLIB_CALLINFO_H_
#define _SLOGLIB_CALLINFO_H_

#include <string>
#include <vector>

namespace SLogLib {
;

// The CallInfo structure stores the information of a single function call.
struct CallInfo
{
	std::string  mFileName;    // The name of the file containing the function.
	std::string  mFuncName;    // The name of the function.
	unsigned int mLineNumber;  // The line number at which SLOGLIB_ADD_TO_CALLSTACK macro was 
	                           // inserted in the function.
	
	CallInfo()
		: mLineNumber(0)
	{}
	CallInfo(const std::string& fileName, const std::string& funcName, unsigned int lineNumber)
		: mFileName(fileName), mFuncName(funcName), mLineNumber(lineNumber)
	{}
	
	bool operator != (const CallInfo& B)
	{
		return !(B.mFileName==mFileName && B.mFuncName==mFuncName && B.mLineNumber==mLineNumber);
	}
};

// Define a type for storing array of CallInfo's forming a CallStack.
typedef std::vector<CallInfo> CallStack;

};	// End namespace SLogLib.

#endif // _SLOGLIB_CALLINFO_H_
