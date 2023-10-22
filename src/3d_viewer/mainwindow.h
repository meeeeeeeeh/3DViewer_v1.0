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
    void on_X_valueChanged(double arg1);

    void on_Y_valueChanged(double arg1);

    void on_Z_valueChanged(double arg1);

    void on_R_valueChanged(double arg1);

    void on_checkBox_clicked(bool checked);

    void on_file_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
