# QSLogLib

> *Read this in other languages: [English](README.md), [한국어](README.ko.md)*

## Introduction
- QSLogLib is a library of SLogLibs ported to Qt5.
- It is ported to Qt with improved devices and function.

## Note
- Cmake is not any more supported. 
- Use Qt. instead of complicated cross-platform code.
- UDP client logger has been added. 

## Example
### LoggingDemo
- First, include pri file on youq Qt project file(*.pro).
```
# Define QSLogLib relative path. You can fix this directory
#   QSLOG_PARENTPATH = ../../
#   QSLOG_HEADERPATH = ../../QSLogLib/
#   QSLOG_SOURCEPATH = ../../QSLogLib/
include(../../QSLogLib/QSLogLib.pri)
```
- Code of main.cpp
```cpp
#include <QtGlobal>
#include <QCoreApplication>

#include "QSLogLib/SLogLib.h"
#include "QSLogLib/Devices/AbstractLoggingDevice.h"
#include "QSLogLib/Devices/ConsoleLogger.h"
#include "QSLogLib/Devices/FileLogger.h"
#include "QSLogLib/Devices/UdpLogger.h"
#include "QSLogLib/Formatters/AbstractFormatter.h"
#include "QSLogLib/Formatters/DetailedFormatter.h"
#include "QSLogLib/Formatters/ErrorFormatter.h"
#include "QSLogLib/Formatters/InfoFormatter.h"
#include "QSLogLib/Formatters/NullFormatter.h"

int main(int argc, char *argv[])
{
    QCoreApplication mainApp(argc, argv);

    // Add these lines at the beginning of your program.
    // The devices and formatters are automatically deleted by SLogLib.
    using namespace SLogLib;

    addLoggingDevice( new ConsoleLogger(new NullFormatter) );
    addLoggingDevice( new FileLogger("foo.log", new DetailedFormatter) );

    // The following line writes the message to both console and file.
    int a = 10;
    double b = 15.3;
    const char* c = "Success";
    SLOGLIB_LOG_MSG_INFO("a = " << a << " b = " << b);
    SLOGLIB_LOG_MSG_INFO(c);

    return 0;
    // return a.exec();
}
```

## Test Environment
- Qt 5.10.1 (MingW, Windows 32bit)
- Qt 5.6.2 (Linux 64bit)

## Authors
- SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
- QSLogLib : j2doll https://github.com/j2doll/QSLogLib
	
## License
- MIT Licensse