#include "glwidget.h"
#include "../viewer.h"
#include <QDebug>

GLWidget::GLWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    this->size_v_= 1;
    this->size_l_ = 1;

    this->d_n = false;
    this->d_s = false;
    this->d_r = false;

    this->l_s = false;
    this->l_d = false;

    this->p_proj = false;
    this->c_proj = false;

    this->v_color_ = QColor(204, 204, 255);
    this->l_color_ = QColor(255, 255, 255);
    this->b_color_ = QColor(0, 0, 0);
}

void GLWidget::initializeDL()
{
    glEnable(GL_DEPTH_TEST);
}

void GLWidget::paintGL()
{
    if (!error) {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        if(p_proj) {
           glOrtho(-1, 1, -1, 1, -1, 99999);
           glTranslated(0,0,0);
           p_proj = false;
        }
        if(c_proj) {
            glFrustum(-1, 1, -1, 1, 1, 99999);
            glTranslated(0,0,-1.5);
            c_proj = false;
        }

        glClearColor(b_color_.redF(), b_color_.greenF(), b_color_.blueF(), b_color_.alphaF());
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPointSize(size_v_);
        glLineWidth(size_l_);

        if (l_d) {
           glEnable(GL_LINE_STIPPLE);
           glLineStipple(1,5);
        }
        if (l_s) glDisable(GL_LINE_STIPPLE);

        glColor3d(l_color_.redF(), l_color_.greenF(), l_color_.blueF());

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
        if(l_s) l_s = false;
        if(l_d) l_d = false;
        glEnd();

        glColor3d(v_color_.redF(), v_color_.greenF(), v_color_.blueF());

        if (!d_n) {
            if(d_r) glEnable(GL_POINT_SMOOTH);
            if (d_s) glDisable(GL_POINT_SMOOTH);

            glBegin(GL_POINTS);
            for (unsigned long int i = 0; i < vert_struct.amount_vert; i++) {
                glEnable(GL_BLEND);
                glVertex3d(vert_struct.matrix_vert[i][0], vert_struct.matrix_vert[i][1], vert_struct.matrix_vert[i][2]);
            }
            glEnd();
        }
        if(d_n) d_n = false;
        if(d_s) d_s = false;
        if(d_r) d_r = false;
    }
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void GLWidget::change_size_vert(int size_v) {
    size_v_ = size_v;
    update();
}

void GLWidget::change_size_line(int size_l) {
    size_l_ = size_l;
    update();
}
