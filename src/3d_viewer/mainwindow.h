#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_color_vert_clicked();

    //void on_color_lines_clicked();

    //void on_color_back_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_line_size_valueChanged(int arg1);

    void on_dot_none_clicked();

    void on_dot_square_clicked();

    void on_dot_round_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
