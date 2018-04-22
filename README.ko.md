# QSLogLib

> *Read this in other languages: [English](README.md), [한국어](README.ko.md)*

## 소개
- QSLogLib는 SLogLib를 Qt5로 이식한 라이브러리 입니다. 
- 향상된 장치와 기능으로 Qt로 포팅되었습니다.

## 노트
- Cmake는 더 이상 지원하지 않습니다.
- 크로스 플랫폼 지원을 위한 복잡한 코드 대신에 Qt를 사용합니다.  
- UDP 클라이언트 로거가 추가되었습니다.

## 예제

### 설정 방법
- 처음에 Qt 프로젝트 파일(*.pro)에 pri 파일을 추가합니다.
```
# Define QSLogLib relative path. You can fix this directory
#   QSLOG_PARENTPATH = ../../
#   QSLOG_HEADERPATH = ../../QSLogLib/
#   QSLOG_SOURCEPATH = ../../QSLogLib/
include(../../QSLogLib/QSLogLib.pri)
```

### 표준 출력/파일 로깅 예제
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

### UDP 송신 예제
```cpp
int main()
{
	// Add these lines at the beginning of your program.
	// The devices and formatters are automatically deleted by SLogLib.
	using namespace SLogLib;

    std::string strDestAddress = "192.168.137.1";
    unsigned short destPort = 5000;
	addLoggingDevice(new UdpLogger(strDestAddress, destPort, new NullFormatter));

	// The following line writes the message to both console and file.
	int a = 10;
	double b = 15.3;
	const char* c = "Success";
	SLOGLIB_LOG_MSG_INFO("a = " << a << " b = " << b);
	SLOGLIB_LOG_MSG_INFO(c);

	return 0;
}

## 테스트 환경
- Qt 5.10.1 (MingW, Windows 32bit)
- Qt 5.6.2 (Linux 64bit)

## 저자
- SLogLib : Saurabh Garg https://github.com/saurabhg17/SLogLib
- QSLogLib : j2doll https://github.com/j2doll/QSLogLib
	
## 라이선스
- MIT 라이선스