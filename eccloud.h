#ifndef ECCLOUD_H
#define ECCLOUD_H

#include <QMainWindow>
#include <QMessageBox>
#include <qdebug.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>
#include <libvirt/virterror.h>
#include<libvirt/libvirt-domain.h>
#include <QTime>

namespace Ui {
class eccloud;
}

class eccloud : public QMainWindow
{
    Q_OBJECT

public:
    void delay(int a);
    explicit eccloud(QWidget *parent = 0);
    ~eccloud();

private slots:
    void on_Connect_button_clicked();

    void on_Disconnect_button_clicked();

private:
    Ui::eccloud *ui;
};

#endif // ECCLOUD_H
