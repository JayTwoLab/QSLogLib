// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

#ifndef SLOGLIB_SYSUTILS_H_
#define SLOGLIB_SYSUTILS_H_

#include <string>
#include <sstream>

#include <QProcess>
#include <QDateTime>

namespace QSLogLib {

// Sleep the current thread for specified milliseconds.
 void sleep(unsigned int msec);

// Get the ID of the current process.
int64_t getCurrentProcessID();

// Get the ID of the current thread.
uint64_t getCurrentThreadID();

// Get the current local date and time.
QDateTime getLocalDateTime();

std::string getLocalDateTimeStdString();

// Convert a type to string; the type must support std::ostringstream operator.
template<class T>
inline std::string toString(const T& x)
{
	std::ostringstream _stream;
	_stream << x;
	return _stream.str();
}

};	// End namespace

#endif // SLOGLIB_SYSUTILS_H_
