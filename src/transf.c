#include <stdio.h>
#include "viewer.h"


// int main() {
//     // double m[3][3] = {{30, 36, 42}, 
//     // {84, 108, 132}, {138, 180, 222}};


    
//     return 0;
// }


// нужно занулить значения вначале
void fill_min_max(vertex *input_d) {
    for (unsigned long int i = 0; i < input_d->amount_vert; i++) {
        if (input_d->matrix_vert[i][0] < input_d->minmax_x[0]) {
            input_d->minmax_x[0] = input_d->matrix_vert[i][0];
        } else if (input_d->matrix_vert[i][0] < input_d->minmax_x[1]) {
            input_d->minmax_x[1] = input_d->matrix_vert[i][0];
        }
        if (input_d->matrix_vert[i][1] < input_d->minmax_y[0]) {
            input_d->minmax_y[0] = input_d->matrix_vert[i][1];
        } else if (input_d->matrix_vert[i][1] < input_d->minmax_y[1]) {
            input_d->minmax_y[1] = input_d->matrix_vert[i][1];
        }
        if (input_d->matrix_vert[i][2] < input_d->minmax_z[0]) {
            input_d->minmax_x[0] = input_d->matrix_vert[i][2];
        } else if (input_d->matrix_vert[i][2] < input_d->minmax_z[1]) {
            input_d->minmax_z[1] = input_d->matrix_vert[i][2];
        }
    }
}

// возвращает самый большой максимум (нужно для ресайза)
double find_center(vertex *v, double *center_x, double *center_y, double *center_z) {
    *center_x = v->minmax_x[0] + (v->minmax_x[1] - v->minmax_x[0]) / 2;
    *center_y = v->minmax_y[0] + (v->minmax_y[1] - v->minmax_y[0]) / 2;
    *center_z = v->minmax_z[0] + (v->minmax_z[1] - v->minmax_z[0]) / 2;

    double max = *(center_x);
    if (max < *(center_y)) max = *(center_y);
    if (max < *(center_z)) max = *(center_z);

    return max;
}

void centralize(vertex *v, double *center_x, double *center_y, double *center_z) {
    for (int i = 0; i < v->amount_vert; i++) {
        v->matrix_vert[i][0] -= *(center_x); 
        v->matrix_vert[i][1] -= *(center_y); 
        v->matrix_vert[i][2] -= *(center_z); 
    }
}

double decrease_k(vertex *v, double value, double max) {
    double k = (value - (value * (-1))) / max;
    return k;
}

int matrix_value_operations(vertex *v, double value, char op) {
    int err = 0;
    for (int i = 0; i < v->amount_vert; i++) {
        for (int j = 0; j < 3; j++) {
            if (op == '*') v->matrix_vert[i][j] *= value;
            else if (op == '+') v->matrix_vert[i][j] += value;
            else if (op == '/') { // тут надо чет поменять и сделать проверку на ноль(!!)
                v->matrix_vert[i][j] += value;
            }
            else err = 1;
        }
    }
    return err;
}

//void rotation_z(vertex *v, )