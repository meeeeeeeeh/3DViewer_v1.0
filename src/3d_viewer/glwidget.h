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

    int R;
    float x, y, z;
    bool wired;

    int error;


    vertex vert_struct;
    polygon pol_struct;

};

#endif // GLWIDGET_H
