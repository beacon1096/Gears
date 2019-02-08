#ifndef BF_PLATFORMINFO
#define BF_PLATFORMINFO

#define BF_PLATFORMINFOVERSION "1.0.0"

#include <QSysInfo>
#include <QString>

class BeaconPlatformInfo : public QObject
{
    Q_OBJECT
public:
    explicit BeaconPlatformInfo(QObject *parent = nullptr){}
    static bool isWindows(){
        if(QGuiApplication::platformName()=="windows")
            return true;
        #ifdef Q_OS_WIN64
            return true;
        #endif
        #ifdef Q_OS_WIN32
            return true;
        #endif
        #ifdef Q_OS_WINRT
            return true;
        #endif
        #ifdef Q_OS_WIN
            return true;
        #endif
        #ifdef Q_OS_WIN
            return true;
        #endif
        return false;
    }
    static bool isLinux(){
        if(QGuiApplication::platformName()=="xcb")
            return true;
        #ifdef Q_OS_LINUX
            return true;
        #endif
    }
    static bool isMacos(){
        #ifdef Q_OS_MACOS
            return true;
        #endif
    }
    static QString BuildABI(){return QSysInfo::buildAbi();}
    static QString BuildCPUArch(){return QSysInfo::buildCpuArchitecture();}
    static QString CuCPUArch(){return QSysInfo::currentCpuArchitecture();}
    static QString Kernel(){return QSysInfo::kernelType();}
    static QString KernelVersion(){return QSysInfo::kernelVersion();}
    static QString HostName(){return QSysInfo::machineHostName();}
    static QString OSFormattedProductName(){return QSysInfo::prettyProductName();}
    static QString OSProductName(){return QSysInfo::productType();}
    static QString OSProductVersion(){return QSysInfo::productVersion();}
};

#endif // BF_PLATFORMINFO
