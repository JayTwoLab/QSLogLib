// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

#ifndef _SLOGLIB_ADDTOCALLSTACK_H_
#define _SLOGLIB_ADDTOCALLSTACK_H_

#include <string>

namespace SLogLib {
;

// The AddToCallStack structure is a used to automatically add and remove function calls to 
// the call stack. The constructor adds the function call and destructor removes it.
struct AddToCallStack
{
    AddToCallStack(const std::string& fileName,
                   const std::string& funcName,
                   unsigned int lineNumber);
	~AddToCallStack();
};

};	// End namespace SLogLib.

#endif // _SLOGLIB_ADDTOCALLSTACK_H_
