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
    void change_size_vert(int size_v);
    void change_size_line(int size_l);

    float x, y, z;

    int error;
    bool d_n;
    bool d_s;
    bool d_r;
    bool p_proj;
    bool c_proj;

    bool l_s;
    bool l_d;
    QColor v_color_;
    QColor l_color_;
    QColor b_color_;

    int size_v_;
    int size_l_;
    vertex vert_struct;
    polygon pol_struct;
};

#endif // GLWIDGET_H
