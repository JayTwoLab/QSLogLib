
#include "SLogLib.h"

namespace SLogLib {
;

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void addLoggingDevice(AbstractLoggingDevice* device)
{
	LoggingManager::Instance().AddDevice(device);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void removeLoggingDevice(const std::string& deviceName)
{
	LoggingManager::Instance().RemoveDevice(deviceName);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void removeLoggingDevice(AbstractLoggingDevice* device)
{
	LoggingManager::Instance().RemoveDevice(device);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
AbstractLoggingDevice* queryLoggingDevice(const std::string& deviceName)
{
	return LoggingManager::Instance().QueryDevice(deviceName);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void writeMessage(const std::string& fileName,
	              const std::string& funcName,
				  unsigned int       lineNo,
				  unsigned int       level,
				  const std::string& msg)
{
	LoggingManager::Instance().WriteMessage(fileName, funcName, lineNo, level, msg);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void disableLogging()
{
	LoggingManager::Instance().setIsDisabled(true);
}
void enableLogging()
{
	LoggingManager::Instance().setIsDisabled(false);
}
bool isLoggingEnabled()
{
	return LoggingManager::Instance().isDisabled();
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

};	// End namespace SLogLib.
