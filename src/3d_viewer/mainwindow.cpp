#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"
#include "../viewer.h"
#include <QFileDialog>
#include <QColorDialog>

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

    ui->GLwidget->error = 1;  //  путь не найден
    ui->GLwidget->error = parser(path_str, &(ui->GLwidget->vert_struct), &(ui->GLwidget->pol_struct));

    file_output(path_str);

    if (!ui->GLwidget->error) {
        fill_min_max(&(ui->GLwidget->vert_struct));
        decrease(&(ui->GLwidget->vert_struct), 0.5);
        centralize(&(ui->GLwidget->vert_struct)); //incorrect image with skulll and cub_r
    }


    qDebug() << ui->GLwidget->error;

}

void MainWindow::file_output(const char * path_str)
{
    if (!ui->GLwidget->error) {
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
}



void MainWindow::on_move_clicked()
{
    double x_m = ui->X->value();
    double y_m = ui->Y->value();
    double z_m = ui->Z->value();

    if (!ui->GLwidget->error) {
        if(x_m != 0) {
            x_m /= 100;
            move_matrix(&(ui->GLwidget->vert_struct), x_m, 'x');
        }

        if(y_m != 0) {
            y_m /= 100;
            move_matrix(&(ui->GLwidget->vert_struct), y_m, 'y');
        }

        if(z_m != 0) {
            z_m /= 100;
            move_matrix(&(ui->GLwidget->vert_struct), z_m, 'z');
        }

        ui->GLwidget->update();
    }
}


void MainWindow::on_rotate_clicked()
{
    double x = ui->R_X->value();
    double y = ui->R_Y->value();
    double z = ui->R_Z->value();

    if (!ui->GLwidget->error) {
        if(x != 0) {
            rotation_x(&(ui->GLwidget->vert_struct), x);
        }

        if(y != 0) {
           rotation_y(&(ui->GLwidget->vert_struct), y);
        }

        if(z != 0) {
            rotation_z(&(ui->GLwidget->vert_struct), z);
        }

        ui->GLwidget->update();
    }
}


void MainWindow::on_resize_clicked()
{
    double val = (double)ui->recize_val->value();
    if (val != 0) {

        if (val > 0) val = (val + 1) / 1.5;
        if(val < 0) {
            val = (10 + val) / 10;
        }

        resize_matrix(&(ui->GLwidget->vert_struct), val);
    }

    qDebug() << val;
}


void MainWindow::on_color_vert_clicked()
{
    QColorDialog colorDialog(this);
    auto new_color = colorDialog.getColor(Qt::white, this);
    if (new_color.isValid()) {
        ui->GLwidget->change_vert_color(new_color);
    }
}


//void MainWindow::on_color_lines_clicked()
//{
//    QColorDialog colorDialog(this);
//    auto new_color = colorDialog.getColor(Qt::white, this);
//    if (new_color.isValid()) {
//        ui->GLwidget->change_line_color(new_color);
//    }
//}


//void MainWindow::on_color_back_clicked()
//{

//}

