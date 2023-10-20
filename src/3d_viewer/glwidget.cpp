#include "glwidget.h"
#include "../viewer.h"

GLWidget::GLWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    this->R = 1;
    this->wired = false;

//    initializeDL();
//    paintGL();

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


    vertex *v = NULL;
    polygon *p = NULL;
    char f_name[20] = "cube.obj";

    parser(f_name, v, p);

//    for (unsigned long int i = 0; i < p->amount_pol; i++) {
//        for (unsigned long int j = 0; j < p->amount_pol_on_string; j++) {
//            glBegin(GL_LINE_LOOP);
//            glVertex3d(x, y, z);
//        }
//    }
//    glEnd();

    for (unsigned long int i = 0; i < v->amount_vert; i++) {
        printf("%ld", v->amount_vert);
        glEnable(GL_BLEND);
        glBegin(GL_POINTS);
        glVertex3d(v->matrix_vert[i][0], v->matrix_vert[i][1], v->matrix_vert[i][2]);

    }
    glEnd();

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
