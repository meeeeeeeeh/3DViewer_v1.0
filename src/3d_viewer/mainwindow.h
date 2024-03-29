#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qtgifimage/src/gifimage/qgifimage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#ifdef __cplusplus

extern "C" {
#endif

#include "../viewer.h"

#ifdef __cplusplus
}
#endif

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_file_path_clicked();

    void on_move_clicked();

    void on_rotate_clicked();

    void file_output(const char * path_str);

    void on_resize_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_line_size_valueChanged(int arg1);

    void on_dot_none_clicked();

    void on_dot_square_clicked();

    void on_dot_round_clicked();

    void on_line_dashed_clicked();

    void on_line_solid_clicked();

    void on_color_vert_clicked();

    void on_color_lines_clicked();

    void on_color_back_clicked();

    void on_parallel_clicked();

    void on_central_clicked();

    void on_image_clicked();

    void on_gif_clicked();

    void recordSlot();


private:
    Ui::MainWindow *ui;
    QGifImage *gifka;
    QTimer *timerGif;
    QString gifFilePath;
};
#endif // MAINWINDOW_H
