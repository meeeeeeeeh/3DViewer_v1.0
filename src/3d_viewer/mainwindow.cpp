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


void MainWindow::on_file_path_clicked()
{
    QString filter = "All files (*.*) ;; OBJ Files (*.obj)";
    QString path = QFileDialog::getOpenFileName(this, "Open file...", "", filter);

    std::string str = path.toStdString();
    const char* path_str = str.c_str();

    int err = 0;  //  путь не найден
    err = parser(path_str, &(ui->GLwidget->vert_struct), &(ui->GLwidget->pol_struct));

    if (!err) {
        this->ui->label_file->setText(get_file_name(path_str));
    }
    else {
        this->ui->label_file->setText("No such file");
    }

    QString str_v = QString::number(ui->GLwidget->vert_struct.amount_vert);
    this->ui->label_vert->setText(str_v);

    int ed_num;
    if (ui->GLwidget->pol_struct.amount_pol % 2 == 0) {
        ed_num = ui->GLwidget->pol_struct.amount_pol / 2;
    } else {
        ed_num = ((ui->GLwidget->pol_struct.amount_pol) + 1) / 2;
    }
    QString str_p = QString::number(ed_num);
    this->ui->label_edges->setText(str_p);



    fill_min_max(&(ui->GLwidget->vert_struct));
    decrease(&(ui->GLwidget->vert_struct), 0.5);

    qDebug() << err;


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



void MainWindow::on_move_clicked()
{



}


void MainWindow::on_R_X_valueChanged(double arg1)
{

}


void MainWindow::on_R_Y_valueChanged(double arg1)
{

}


void MainWindow::on_R_Z_textChanged(const QString &arg1)
{

}


void MainWindow::on_rotate_clicked()
{

}


void MainWindow::on_resize_clicked()
{

}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{

}


void MainWindow::on_checkBox_clicked(bool checked)
{
    this->ui->GLwidget->wired = checked;
}
