#include "glwidget.h"
#include "../viewer.h"
#include <QDebug>

GLWidget::GLWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    this->R = 1;
    this->wired = false;

}

void GLWidget::initializeDL()
{
    glClearColor(0.2, 0.2, 0.2, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1, 0, 0);



//   glBegin(GL_LINE_LOOP);
//    for (unsigned long int i = 0; i < p->amount_pol; i++) {
//        for (int j = 0; j < p->amount_pol_on_string; j++) {
//
//            int index = p->polygons[i][j];
//            glVertex3d(v->matrix_vert[index][0], v->matrix_vert[index][1], v->matrix_vert[index][2]);
//        }
//    }
//    glEnd();


    qInfo() << vert_struct->amount_vert;

//    glBegin(GL_POINTS);
//    for (unsigned long int i = 0; i < vert_struct->amount_vert; i++) {

//        printf("%ld", vert_struct->amount_vert);
//        glEnable(GL_BLEND);
//        glVertex3d(vert_struct->matrix_vert[i][0], vert_struct->matrix_vert[i][1], vert_struct->matrix_vert[i][2]);

//    }
//    glEnd();

//    if(wired)
//        glutWireSphere(1, 20, 20);
//    else
//        glutSolidSphere(1, 20, 20);
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}
