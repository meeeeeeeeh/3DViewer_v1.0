#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"
#include "../viewer.h"
#include <QFileDialog>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_X_valueChanged(double arg1)
{
    this->ui->GLwidget->x = arg1;
}


void MainWindow::on_Y_valueChanged(double arg1)
{
    this->ui->GLwidget->y = arg1;
}


void MainWindow::on_Z_valueChanged(double arg1)
{
    this->ui->GLwidget->z = arg1;
}




void MainWindow::on_checkBox_clicked(bool checked)
{
    this->ui->GLwidget->wired = checked;
}


void MainWindow::on_file_path_clicked()
{
    QString filter = "All files (*.*) ;; OBJ Files (*.obj)";
    QString path = QFileDialog::getOpenFileName(this, "Open file...", "", filter);

    //qDebug() << path;



    std::string str = path.toStdString();
    const char* ppp = str.c_str();

    int err = 0;

    //qDebug() << ppp;

    err = parser(ppp, &(ui->GLwidget->vert_struct), &(ui->GLwidget->pol_struct));

    fill_min_max(&(ui->GLwidget->vert_struct));
    decrease(&(ui->GLwidget->vert_struct), 0.5);

//    double center_x = 0;
//    double center_y = 0;
//    double center_z = 0;

//    centralize( &(ui->GLwidget->vert_struct), &center_x, &center_y, &center_z);


    qDebug() << err;


    //qDebug() << this->ui->GLwidget->vert_struct.amount_vert;

}

