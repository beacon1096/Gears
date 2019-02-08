#ifndef BF_FILEIO
#define BF_FILEIO

#define BF_FILEIOVERSION "1.0.0"

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QUrl>
#include <QDebug>
#include <QFileDialog>
#include <QString>

class BeaconFileIO : public QObject
{
    Q_OBJECT
public:
    explicit BeaconFileIO(QObject *parent = nullptr){}
    static bool openFile(QFile& file,QString name,QChar IOMode){
        bool res=false;
        file.setFileName(name);
        if(IOMode=='r'){
            res=file.open(QIODevice::ReadOnly | QIODevice::Text);
        }
        if(IOMode=='w'){
            res=file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
        }
        return res;
    }
    static void bundleIO(QFile& file,QTextStream& str){
        str.setDevice(&file);
    }
    const static QString readFileContent(QString fileName){
        qDebug() << "BeaconFileIO::readFileContent:"<< fileName;
        QFile file(fileName);
        if(!openFile(file,fileName,'r'))return QStringLiteral("*/*Beacon File General Error: Cannot open target file*/*");
        QTextStream inputStream(&file);
        QString res;
        while(!inputStream.atEnd()){
            res.append(inputStream.readAll());
        }
        return res;
    }
    static QString readFileContent(QUrl target){
        QString fileName = target.toLocalFile();
        return readFileContent(fileName);
    }
    static bool saveFileContent(QString fileName,QString content){
        QFile file(fileName);
        if(!openFile(file,fileName,'w'))return false;
        QTextStream outputStram(&file);
        outputStram<<content;
        return true;
    }
    static bool fileExist(QString fileName){
        QFile file(fileName);
        qDebug() << "[BF-FileIO]Checking Existance:" << fileName;
        return file.exists();
    }
    static bool fileExist(QUrl fileName){
        QFile file(fileName.toLocalFile());
        return file.exists();
    }
    static QUrl selectOpenFile(const QString &type,const QString &filter){
        return QFileDialog::getOpenFileUrl(nullptr,QString(),QUrl(),QString("%1 (%2)").arg(type).arg(filter));
    }
    static QUrl selectOpenFile(const QString &type,const QStringList &filter){
        return selectOpenFile(type,filter.join(","));
    }
    static QUrl selectOpenDir(){
        return QFileDialog::getExistingDirectoryUrl();
    }
};

#endif // BF_FILEIO
