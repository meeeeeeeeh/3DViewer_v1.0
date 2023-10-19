#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include "mainwindow.h"

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    void initializeDL();
    void paintGL();
    void resizeGL(int w, int h);
};

#endif // GLWIDGET_H
