#include "viewer.h"

int main() {

}

int open_obj(char *f_name, FILE **file) {
    int err_flag = 0;
    *file = fopen(f_name, "r");
    if(!file) err_flag = 1;
    return err_flag;
}

void counter_vert(FILE **file, data *input_d) {
    char *buffer = NULL;
    size_t len = MAX_LENGHT;
    while ((getline(&buffer, &len, file)) != -1) {
        if (buffer[0] == 'v' && buffer[1] == ' ') {
            input_d->amount_vert++;
        }
    }
}

void counter_pol(FILE **file, data *input_d) {
    char *buffer = NULL;
    size_t len = MAX_LENGHT;
    while ((getline(&buffer, &len, file)) != -1) {
        if (buffer[0] == 'f' && buffer[1] == ' ') {
            input_d->amount_pol++;
        }
    }
}

int memory_vert(data *input_d) {
    int err_flag = 0;
    input_d->data_v->matrix = calloc(input_d->amount_vert, sizeof(double *));
    for (int i=0; i < input_d->amount_vert; i++) {
        input_d->data_v->matrix[i] = calloc(3, sizeof(double));
    }

}

int memory_pol(data *input_d) {
    int err_flag = 0;
    input_d->data_p->polygons = calloc(input_d->amount_pol, sizeof(double *));
}

void get_vertex(FILE **file, data *input_d) {

    int i = 0;

    char *buffer = NULL;
    size_t len = MAX_LENGHT;

    while ((getline(&buffer, &len, file)) != -1) {
        if (buffer[0] == 'v' && buffer[1] == ' ') {
            sscanf(buffer, "v %f %f %f", &input_d->data_v->matrix[i][0], &input_d->data_v->matrix[i][1], &input_d->data_v->matrix[i][2]);
            i++;
        }
    }
}

void get_pol(FILE **file, data *input_d) {

}