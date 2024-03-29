#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"
#include "../viewer.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QTimer>
#include <QImage>


#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerGif = new QTimer();

    connect(timerGif, SIGNAL(timeout()), this, SLOT(recordSlot()));
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
        ui->GLwidget->update();
    }

}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->GLwidget->change_size_vert(arg1);
}


void MainWindow::on_line_size_valueChanged(int arg1)
{
    ui->GLwidget->change_size_line(arg1);
}


void MainWindow::on_dot_none_clicked()
{
    ui->GLwidget->d_n = true;
    ui->GLwidget->update();
}


void MainWindow::on_dot_square_clicked()
{
    ui->GLwidget->d_s = true;
    ui->GLwidget->update();
}


void MainWindow::on_dot_round_clicked()
{
    ui->GLwidget->d_r = true;
    ui->GLwidget->update();
}


void MainWindow::on_line_dashed_clicked()
{
    ui->GLwidget->l_d = true;
    ui->GLwidget->update();
}


void MainWindow::on_line_solid_clicked()
{
    ui->GLwidget->l_s = true;
    ui->GLwidget->update();
}

void MainWindow::on_color_vert_clicked()
{
    QColorDialog colorDialog(this);
    auto new_color = colorDialog.getColor(Qt::white, this);
    if (new_color.isValid()) {
        ui->GLwidget->v_color_ = new_color;
        ui->GLwidget->update();
    }
}

void MainWindow::on_color_lines_clicked()
{
    QColorDialog colorDialog(this);
    auto new_color = colorDialog.getColor(Qt::white, this);
    if (new_color.isValid()) {
        ui->GLwidget->l_color_ = new_color;
        ui->GLwidget->update();
    }
}

void MainWindow::on_color_back_clicked()
{
    QColorDialog colorDialog(this);
    auto new_color = colorDialog.getColor(Qt::white, this);
    if (new_color.isValid()) {
        ui->GLwidget->b_color_ = new_color;
        ui->GLwidget->update();
    }
}


void MainWindow::on_parallel_clicked()
{
    ui->GLwidget->p_proj = true;
    ui->GLwidget->c_proj = false;
    ui->GLwidget->update();
}


void MainWindow::on_central_clicked()
{
    ui->GLwidget->c_proj = true;
    ui->GLwidget->p_proj = false;
    ui->GLwidget->update();

    qDebug() << ui->GLwidget->c_proj;
}

void MainWindow::on_image_clicked()
{
    const char *format = "img files (*.jpeg)";
    if (ui->bmp->isChecked()) format = "img files (*.bmp)";
    else if (ui->jpeg->isChecked()) format = "img files (*.jpeg)";

    QString imgFilePath = QFileDialog::getSaveFileName(
    this, "Specify where to save a file", "/", tr(format), 0,
    QFileDialog::DontUseNativeDialog);

    QImage image = ui->GLwidget->grabFramebuffer();
    image.save(imgFilePath);

}


void MainWindow::on_gif_clicked()
{
      gifka = new QGifImage();
      gifFilePath = QFileDialog::getSaveFileName(
          this, "Specify where to save a file", "/", tr("GIF files (*.gif)"), 0,
          QFileDialog::DontUseNativeDialog);
      timerGif->start(100);
}

    void MainWindow::recordSlot() {
      QImage modelImage = ui->GLwidget->grabFramebuffer();
      gifka->addFrame(modelImage);
      if (gifka->frameCount() == 50) {
        timerGif->stop();
        gifka->setDefaultDelay(100);
        bool saveRes = gifka->save(gifFilePath);
        QString saveAlert;
        if (saveRes) {
          saveAlert = "File saved at" + gifFilePath;
        } else {
          saveAlert = "Gif wasn't saved, something went wrong(";
        }
        qDebug() << saveAlert;
        delete gifka;
        gifka = NULL;
      }
      //qDebug() << "recordSlot";
    }


