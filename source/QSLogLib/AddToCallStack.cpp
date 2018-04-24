// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

#include "AddToCallStack.h"
#include "LoggingManager.h"

namespace SLogLib {
;

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
AddToCallStack::AddToCallStack(const std::string& fileName, 
							   const std::string& funcName, 
							   unsigned int       lineNumber)
{
	LoggingManager::Instance().PushFunction(fileName, funcName, lineNumber);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
AddToCallStack::~AddToCallStack()
{
	LoggingManager::Instance().PopFunction();
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

};	// End namespace SLogLib.
