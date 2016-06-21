#include "eccloud.h"
#include "ui_eccloud.h"
#include "server.h"

Server *New_Server= new Server("");
eccloud::eccloud(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eccloud)
{
    ui->setupUi(this);


    ui->Connection->setText("qemu://www.dravigon.noip.me/system");
    ui->Connection_progress->hide();//hide progress bar
    ui->Disconnect_button->hide();//initially hide disconnect button
    //connect return(aka enter button) pressed in line edit to connect button
    QObject::connect(ui->Connection,SIGNAL(returnPressed()),ui->Connect_button,SLOT(click()));

}

eccloud::~eccloud()
{
    delete ui;
}

//on pressing connect button connect to server hide connect button and show disconnect button only if connection is established sucessfully
void eccloud::on_Connect_button_clicked()
{
    int count=0;
    ui->Connection_progress->show();
    ui->Connect_button->hide();
    ui->Connection_progress->reset();
    New_Server->update_server_name(ui->Connection->text());

    //try to connect to server five time at a delay of one second each
    while((New_Server->connect_server())&&(count<5)){
        count++;
        delay(1);
        ui->Connection_progress->setValue(count*20);

    }

    //if connection not possible show error
    if(count==5){
        QMessageBox::information(this,"Connection Error","Connection cant be established with Server");
         ui->Connect_button->show();
    }
    //else if connected change connect button to disconnect button
    else {
       ui->Disconnect_button->show();
       ui->Connection->setDisabled(true);
    }

    ui->Connection_progress->hide();

}

//delay function for giving a delay of 'a' seconds
void eccloud::delay(int a)
{
    QTime dieTime= QTime::currentTime().addSecs(a);
    while (QTime::currentTime() < dieTime)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

//on pressing disconnect button disconnect to server hide disconnect button and show connect button
void eccloud::on_Disconnect_button_clicked()
{
    QMessageBox::information(this,"Connection terminated","Connection with the Server was terminated");
    New_Server->disconnect_server();
    ui->Connect_button->show();
    ui->Connection->setEnabled(true);
    ui->Disconnect_button->hide();
}
