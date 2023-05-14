// anydesk.h
#ifndef ANYDESK_H
#define ANYDESK_H

#include <QCoreApplication>
#include <QDir>
#include <QProcess>
#include <QObject>

class Anydesk: public QObject
{
    Q_OBJECT

public:
    explicit Anydesk();
    ~Anydesk();
    //virtual ~Anydesk(){};

    QString find_conf_file();
    void remove_conf_file(const QString& loc_of_file);
    void kill_open_anydesk_exes();
    QString checkOS();
    bool isConfFileRemoved();

    enum FaultType{
        NO_ERROR,
        ADMIN_ERROR,
        CONF_FILE_FOUND_ERROR
    };

public slots:
    int reset_ID();


signals:
    QString conf_file_dir_created();

private:

};

#endif // ANYDESK_H
