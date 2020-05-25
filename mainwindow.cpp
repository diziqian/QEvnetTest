#include <QKeyEvent>
#include <QApplication>
#include <QDebug>


#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    switch (event->type())
    {
    case QEvent::KeyPress:
        event->ignore();
        return true;

    default:
        qDebug() << event->type();
        break;
    }

    return QObject::eventFilter(object, event);
}

void MainWindow::on_pushButton_clicked()
{
    int key = Qt::Key_Delete;

     QKeyEvent EventPress(QEvent::KeyPress, key, Qt::NoModifier);
     QApplication::sendEvent(ui->textEdit, &EventPress);   //发送键盘按下事件

     QKeyEvent EventRelease(QEvent::KeyRelease, key, Qt::NoModifier);
     QApplication::sendEvent(ui->textEdit, &EventRelease); //发送键盘松开事件
}
