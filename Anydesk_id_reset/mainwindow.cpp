#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <anydesk.h>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCoreApplication::setApplicationName("Reset ID");
    setWindowTitle( QCoreApplication::applicationName());
    m_Anydesk = new Anydesk();

    // Connect button signal to appropriate slot
    connect(ui->confFileDetect_btn, SIGNAL(released()), this, SLOT(setConfFileDirLabel()));
    connect(ui->resetID_btn, SIGNAL(released()), this, SLOT(resetAnyDeskID()));


}

void MainWindow::setConfFileDirLabel(){
    m_conf_file_dir = m_Anydesk->find_conf_file();
    QString Conf_file_set_text = "Conf file found at->\n" + m_conf_file_dir ;
    ui->confFileDetectLabel->setText(Conf_file_set_text);
}


void MainWindow::resetAnyDeskID(){
    int is_reset_succeed = m_Anydesk->reset_ID();
    if (is_reset_succeed == m_Anydesk->CONF_FILE_FOUND_ERROR){
        qDebug() << "False" ;
        ui->idResetResult_label->setStyleSheet("color: #000000");
        ui->idResetResult_label->setText("Reset operation failed.\nPlease restart AnyDesk.\n(This needs for create conf file.)");

    }
    else if(is_reset_succeed == m_Anydesk->NO_ERROR){
        qDebug() << "True" ;
        ui->idResetResult_label->setStyleSheet("color: #DAF7A6");
        ui->idResetResult_label->setText("Reset operation successful.\nID resetted to new one.");
    }
    else if(is_reset_succeed == m_Anydesk->ADMIN_ERROR){
        qDebug() << "True" ;
        ui->idResetResult_label->setStyleSheet("color: #000000");
        ui->idResetResult_label->setText("Reset operation failed.\nPlease re-run the program in administrator mode.");
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}

