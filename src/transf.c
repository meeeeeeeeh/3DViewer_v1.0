#include "viewer.h"

void fill_min_max(vertex *input_d) {
    input_d->minmax_x[0] = input_d->matrix_vert[0][0];
    input_d->minmax_x[1] = input_d->matrix_vert[0][0];

    input_d->minmax_y[0] = input_d->matrix_vert[0][1];
    input_d->minmax_y[1] = input_d->matrix_vert[0][1];

    input_d->minmax_z[0] = input_d->matrix_vert[0][2];
    input_d->minmax_z[1] = input_d->matrix_vert[0][2];

    for (unsigned long int i = 0; i < input_d->amount_vert; i++) {
        if (input_d->matrix_vert[i][0] < input_d->minmax_x[0]) {
            input_d->minmax_x[0] = input_d->matrix_vert[i][0];
        } else if (input_d->matrix_vert[i][0] > input_d->minmax_x[1]) {
            input_d->minmax_x[1] = input_d->matrix_vert[i][0];
        }
        if (input_d->matrix_vert[i][1] < input_d->minmax_y[0]) {
            input_d->minmax_y[0] = input_d->matrix_vert[i][1];
        } else if (input_d->matrix_vert[i][1] > input_d->minmax_y[1]) {
            input_d->minmax_y[1] = input_d->matrix_vert[i][1];
        }
        if (input_d->matrix_vert[i][2] < input_d->minmax_z[0]) {
            input_d->minmax_z[0] = input_d->matrix_vert[i][2];
        } else if (input_d->matrix_vert[i][2] > input_d->minmax_z[1]) {
            input_d->minmax_z[1] = input_d->matrix_vert[i][2];
        }
    }
}

// возвращает самый большой максимум (нужно для ресайза)
void centralize(vertex *v, double *center_x, double *center_y, double *center_z) {
    *center_x = v->minmax_x[0] + (v->minmax_x[1] - v->minmax_x[0]) / 2.0;
    *center_y = v->minmax_y[0] + (v->minmax_y[1] - v->minmax_y[0]) / 2.0;
    *center_z = v->minmax_z[0] + (v->minmax_z[1] - v->minmax_z[0]) / 2.0;

    for (long unsigned int i = 0; i < v->amount_vert; i++) {
        v->matrix_vert[i][0] -= *(center_x); 
        v->matrix_vert[i][1] -= *(center_y); 
        v->matrix_vert[i][2] -= *(center_z); 
    }
}


void decrease(vertex *v, double value) {
    double dif_x = v->minmax_x[1] - v->minmax_x[0];
    double dif_y = v->minmax_y[1] - v->minmax_y[0];
    double dif_z = v->minmax_z[1] - v->minmax_z[0]; 

    double max = dif_x;
    if (max < dif_y) max = dif_y;
    if (max < dif_z) max = dif_z;   

    double k = (value - (value * (-1))) / max;
    resize(v, k);
}

// уменьшает и централрует изначальное изображение, запускается вначале работы
void correct_image(vertex *v) {
    double center_x = 0;
    double center_y = 0;
    double center_z = 0;
    //double max = 0;
    
    fill_min_max(v);
    centralize(v, &center_x, &center_y, &center_z);
    decrease(v, 0.5);
}


void move(vertex *v, double value, char coord) {
    for (long unsigned int i = 0; i < v->amount_vert; i++) {
        if (coord == 'x') {
            v->matrix_vert[i][0] += value;
        }
        else if (coord == 'y') {
            v->matrix_vert[i][1] += value;
        }
        else if (coord == 'z') {
            v->matrix_vert[i][2] += value;
        }
    }
}

void resize(vertex *v, double value) {
    for (long unsigned int i = 0; i < v->amount_vert; i++) {
        for (int j = 0; j < 3; j++) {
            v->matrix_vert[i][j] *= value;
        }
    }
}

void rotation_z(vertex *v, double angle) {
    for (long unsigned int i = 0; i < v->amount_vert; i++) {
        double temp_x = v->matrix_vert[i][0];
        double temp_y = v->matrix_vert[i][1];

        v->matrix_vert[i][0] = cos(angle) *temp_x - sin(angle) * temp_y;
        v->matrix_vert[i][1] = sin(angle) * temp_x + cos(angle) * temp_y;
    }
}

void rotation_x(vertex *v, double angle) {
    for (long unsigned int i = 0; i < v->amount_vert; i++) {
        double temp_y = v->matrix_vert[i][1];
        double temp_z = v->matrix_vert[i][2];
        
        v->matrix_vert[i][1] = cos(angle) *temp_y - sin(angle) * temp_z;
        v->matrix_vert[i][2] = sin(angle) * temp_y + cos(angle) * temp_z;
    }
}

void rotation_y(vertex *v, double angle) {
    for (long unsigned int i = 0; i < v->amount_vert; i++) {
        double temp_x = v->matrix_vert[i][0];
        double temp_z = v->matrix_vert[i][2];
        
        v->matrix_vert[i][0] = cos(angle) *temp_x - sin(angle) * temp_z;
        v->matrix_vert[i][2] = sin(angle) * temp_x + cos(angle) * temp_z;
    }
}