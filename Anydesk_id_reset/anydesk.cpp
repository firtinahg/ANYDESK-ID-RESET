// anydesk.cpp
#include <anydesk.h>
#include <QCoreApplication>
#include <QDir>
#include <QProcess>
#include <QDebug>
#include <QObject>


Anydesk::Anydesk()
{
   qDebug() << "started...";
   checkOS();
}

QString Anydesk::find_conf_file()
{
    if(checkOS() == "windows"){
    qDebug() <<  "windows device" ;
    QStringList disknames = {"A:\\", "B:\\", "C:\\", "D:\\", "E:\\", "F:\\", "H:\\", "G:\\", "I:\\", "J:\\", "K:\\", "L:\\", "M:\\", "N:\\"};
    QString location_of_service_conf = "ProgramData\\AnyDesk\\service.conf";
    }
    //TODO: will be added the Linux and MACOS based devices
    QStringList disknames = {"A:\\", "B:\\", "C:\\", "D:\\", "E:\\", "F:\\", "H:\\", "G:\\", "I:\\", "J:\\", "K:\\", "L:\\", "M:\\", "N:\\"};
    QString location_of_service_conf = "ProgramData\\AnyDesk\\service.conf";
    QString LOC = "";


    for (const auto& diskname : disknames) {
        LOC = diskname + location_of_service_conf;
        if (QFile::exists(LOC)) {
            qDebug() << "service.conf file found at-> " << diskname;
            break;
        } else {
            LOC = "CAN NOT FOUND.";
        }
    }

    emit conf_file_dir_created();
    return LOC;
}

QString Anydesk::checkOS(){

    qDebug() << "productType():" << QSysInfo::productType().toLocal8Bit();
    QString OS_type =QSysInfo::productType().toLocal8Bit();
    return OS_type;
}

void Anydesk::remove_conf_file(const QString& loc_of_file)
{
    QFile::remove(loc_of_file);
}

void Anydesk::kill_open_anydesk_exes()
{
    /*QProcess process;
        process.setReadChannel(QProcess::StandardOutput);
        process.setReadChannelMode(QProcess::MergedChannels);

        process.start("wmic.exe /OUTPUT:STDOUT PROCESS get Caption");

        process.waitForStarted(1000);
        process.waitForFinished(1000);

        QByteArray list = process.readAll();
        qDebug() << "Read" << list.length() << "bytes";
        qDebug() << list;*/

        QProcess AnydeskProcess;
        AnydeskProcess.execute("taskkill /im AnyDesk.exe /f");
        AnydeskProcess.execute("taskkill /im AnyDesk.exe /f");
        AnydeskProcess.execute("taskkill /im AnyDesk.exe /f");

}

int Anydesk::reset_ID()
{
    QString loc_of_conf_file = find_conf_file();
    if (!(loc_of_conf_file == "CAN NOT FOUND.")) {
        remove_conf_file(loc_of_conf_file);
        kill_open_anydesk_exes();
        if(isConfFileRemoved()){
            return NO_ERROR;
        }
        return ADMIN_ERROR;
    }
    return CONF_FILE_FOUND_ERROR;
}

bool Anydesk::isConfFileRemoved(){
    QString loc_of_conf_file = find_conf_file();
    if (!(loc_of_conf_file == "CAN NOT FOUND.")) {
        return false;
    }
    return true;

}

Anydesk::~Anydesk(){

}
