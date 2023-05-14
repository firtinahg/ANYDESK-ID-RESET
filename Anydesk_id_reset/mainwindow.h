#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <anydesk.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Anydesk *m_Anydesk;
    QString m_conf_file_dir;


public slots:
    void setConfFileDirLabel();
    void resetAnyDeskID();

signals:



private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
