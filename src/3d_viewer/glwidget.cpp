#include "glwidget.h"
#include "../viewer.h"
#include <QDebug>

GLWidget::GLWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    this->R = 1;
    this->wired = false;
    this->v_color_ = QColor(0, 1, 0, 1);
    this->l_color_ = QColor(1, 0, 0, 1);
    this->size_v_= 5;
    this->size_l_ = 1;

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
    if (!error) {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glColor3d(1, 0, 0);





        glPointSize(size_v_);

        glLineWidth(size_l_);

       //glColor3d(v_color_.redF(), v_color_.greenF(), v_color_.blueF());

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


        glColor3d(v_color_.redF(), v_color_.greenF(), v_color_.blueF());


        glBegin(GL_POINTS);
        for (unsigned long int i = 0; i < vert_struct.amount_vert; i++) {
            glEnable(GL_BLEND);
            glVertex3d(vert_struct.matrix_vert[i][0], vert_struct.matrix_vert[i][1], vert_struct.matrix_vert[i][2]);
        }
        glEnd();
    }



}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void GLWidget::change_vert_color(QColor c) {
    v_color_ = c;
    update();
}

//void GLWidget::change_line_color(QColor c) {
//    l_color_ = c;
//    update();
//}

void GLWidget::change_size_vert(int size_v) {
    size_v_ = size_v;
    update();
}

void GLWidget::change_size_line(int size_l) {
    size_l_ = size_l;
    update();
}
