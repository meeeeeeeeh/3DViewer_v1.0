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


void MainWindow::on_R_valueChanged(double arg1)
{
    this->ui->GLwidget->R = arg1;
}


void MainWindow::on_checkBox_clicked(bool checked)
{
    this->ui->GLwidget->wired = checked;
}


void MainWindow::on_file_clicked()
{
    QString filter = "All files (*.*) ;; OBJ Files (*.obj)";
    QString path = QFileDialog::getOpenFileName(this, "Open file...", "", filter);

   qDebug() << path;

    vertex *v = (vertex *)calloc(1, sizeof(vertex));

    polygon *p = (polygon *)calloc(1, sizeof(polygon));


    std::string str = path.toStdString();
    const char* ppp = str.c_str();

    int err = 0;

    qDebug() << ppp;

    err = parser(ppp, v, p);

    qDebug() << err;

    qDebug() << v->amount_vert;

    this->ui->GLwidget->vert_struct = v;
    this->ui->GLwidget->pol_struct = p;

    qDebug() << this->ui->GLwidget->vert_struct->amount_vert;

}

