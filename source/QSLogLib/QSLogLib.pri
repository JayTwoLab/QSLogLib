#-------------------------------------------------
# QSLogLib.pri 
#
# MIT License
# Author: j2doll
# Contacts https://github.com/j2doll/QSLogLib
# e-amil   j2doll@gmail.com
#-------------------------------------------------

QT += core
QT += network
# QT -= gui

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

isEmpty(QSLOG_PARENTPATH) {
    message( 'QSLOG_PARENTPATH is empty. use default value.' )
    QSLOG_PARENTPATH = ../../
} else {
    message( 'QSLOG_PARENTPATH is not empty.' )
    message( $${QSLOG_PARENTPATH} )
}

isEmpty(QSLOG_HEADERPATH) {
    message( 'QSLOG_HEADERPATH is empty. use default value.' )
    QSLOG_HEADERPATH = ../../QSLogLib/
} else {
    message( 'QSLOG_HEADERPATH is not empty.' )
    message( $${QSLOG_HEADERPATH} )
}

isEmpty(QSLOG_SOURCEPATH) {
    message( 'QSLOG_SOURCEPATH is empty. use default value.' )
    QSLOG_SOURCEPATH = ../../QSLogLib/
} else {
    message( 'QSLOG_SOURCEPATH is not empty.' )
    message( $${QSLOG_SOURCEPATH} )
}

INCLUDEPATH += $${QSLOG_PARENTPATH}
INCLUDEPATH += $${QSLOG_PARENTPATH}/Devices
INCLUDEPATH += $${QSLOG_PARENTPATH}/Formatters

HEADERS += \
$${QSLOG_HEADERPATH}CallInfo.h \
$${QSLOG_HEADERPATH}LoggingManager.h \
$${QSLOG_HEADERPATH}Message.h \
$${QSLOG_HEADERPATH}SLogLib.h \
$${QSLOG_HEADERPATH}SysUtils.h \
$${QSLOG_HEADERPATH}Devices/AbstractLoggingDevice.h \
$${QSLOG_HEADERPATH}Devices/ConsoleLogger.h \
$${QSLOG_HEADERPATH}Devices/FileLogger.h \
$${QSLOG_HEADERPATH}Devices/UdpLogger.h \
$${QSLOG_HEADERPATH}Formatters/AbstractFormatter.h \
$${QSLOG_HEADERPATH}Formatters/DetailedFormatter.h \
$${QSLOG_HEADERPATH}Formatters/ErrorFormatter.h \
$${QSLOG_HEADERPATH}Formatters/InfoFormatter.h \
$${QSLOG_HEADERPATH}Formatters/NullFormatter.h \
$${QSLOG_HEADERPATH}AddToCallStack.h

SOURCES += \
$${QSLOG_SOURCEPATH}LoggingManager.cpp \
$${QSLOG_SOURCEPATH}SLogLib.cpp \
$${QSLOG_SOURCEPATH}SysUtils.cpp \
$${QSLOG_SOURCEPATH}Devices/AbstractLoggingDevice.cpp \
$${QSLOG_SOURCEPATH}Devices/FileLogger.cpp \
$${QSLOG_SOURCEPATH}Devices/UdpLogger.cpp \
$${QSLOG_SOURCEPATH}AddToCallStack.cpp

