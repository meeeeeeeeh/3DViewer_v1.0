#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include "mainwindow.h"
#include "../viewer.h"

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT


public:
    explicit GLWidget(QWidget *parent = 0);
    void initializeDL();
    void paintGL();
    void resizeGL(int w, int h);
    void change_vert_color(QColor c);
    void change_line_color(QColor c);
    void change_back_color(QColor c);

    int R;
    float x, y, z;
    bool wired;
    int error;
    QColor v_color_;
    QColor l_color_;
    //QColor b_color_;

    vertex vert_struct;
    polygon pol_struct;
};

#endif // GLWIDGET_H
