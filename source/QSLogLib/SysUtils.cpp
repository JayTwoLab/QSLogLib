// QSLogLib
// 
// Authors
//   SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
//   QSLogLib : j2doll https://github.com/j2doll/QSLogLib
//
// MIT License
//

#include "SysUtils.h"

#include <QProcess>
#include <QThread>
#include <QCoreApplication>
#include <QDateTime>
#include <QDate>
#include <QTime>

namespace SLogLib {

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
void sleep(unsigned int msec)
{
   QThread::usleep( msec * 1000 );
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
int64_t getCurrentProcessID()
{
   int64_t ret = QCoreApplication::applicationPid();
   return ret;
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
uint64_t getCurrentThreadID()
{
     uint64_t ret = (uint64_t) QThread::currentThreadId();
     return ret;
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
QDateTime getLocalDateTime()
{
     QDateTime ret = QDateTime::currentDateTime();
     return ret;
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

}; // namespace SLogLib {
