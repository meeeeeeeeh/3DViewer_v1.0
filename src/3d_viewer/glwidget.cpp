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
//    glEnable(GL_LIGHT0);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1, 0, 0);


    //correct_image(&vert_struct);

    //decrease(&vert_struct, 0.5);




    glPointSize(0.1);
    //glLineWidth(10);

   glBegin(GL_LINES);
    for (unsigned long int i = 0; i < pol_struct.amount_pol; i++) {
        for (int j = 0; j < pol_struct.amount_pol_on_string[i]; j++) {

            int index = pol_struct.polygons[i][j];

            if (j == 0 || j + 1 == pol_struct.amount_pol_on_string[i]) {

                glVertex3d(vert_struct.matrix_vert[index][0], vert_struct.matrix_vert[index][1], vert_struct.matrix_vert[index][2]);
            }
            else {
                glVertex3d(vert_struct.matrix_vert[index][0], vert_struct.matrix_vert[index][1], vert_struct.matrix_vert[index][2]);
                glVertex3d(vert_struct.matrix_vert[index][0], vert_struct.matrix_vert[index][1], vert_struct.matrix_vert[index][2]);
            }

        }
    }
    glEnd();




    glBegin(GL_POINTS);
    for (unsigned long int i = 0; i < vert_struct.amount_vert; i++) {
        glEnable(GL_BLEND);
        glVertex3d(vert_struct.matrix_vert[i][0], vert_struct.matrix_vert[i][1], vert_struct.matrix_vert[i][2]);
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
