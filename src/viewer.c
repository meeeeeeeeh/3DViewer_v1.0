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
    rewind(file);
    char *buffer = NULL;
    size_t len = MAX_LENGHT;
    while ((getline(&buffer, &len, file)) != -1) {
        if (buffer[0] == 'v' && buffer[1] == ' ') {
            input_d->amount_vert++;
        }
    }
}

void counter_pol(FILE **file, data *input_d) {
    rewind(file);
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
    rewind(file);
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

// void fill_min_max(data *input_d) {
//     for (int i = 0; i < input_d->amount_vert; i++) {
//         if (input_d->data_v->matrix[i][0] < input_d->data_v->minmax_x[0]) {
//             input_d->data_v->minmax_x[0] = input_d->data_v->matrix[i][0];
//         }
//         else if (input_d->data_v->matrix[i][0] < input_d->data_v->minmax_x[1]) {
//             input_d->data_v->minmax_x[1] = input_d->data_v->matrix[i][0];
//         }
        
//         if (input_d->data_v->matrix[i][1] < input_d->data_v->minmax_y[0]) {
//             input_d->data_v->minmax_y[0] = input_d->data_v->matrix[i][1];
//         }
//         else if (input_d->data_v->matrix[i][1] < input_d->data_v->minmax_y[1]) {
//             input_d->data_v->minmax_y[1] = input_d->data_v->matrix[i][1];
//         }

//         if (input_d->data_v->matrix[i][2] < input_d->data_v->minmax_z[0]) {
//             input_d->data_v->minmax_x[0] = input_d->data_v->matrix[i][2];
//         }
//         else if (input_d->data_v->matrix[i][2] < input_d->data_v->minmax_z[1]) {
//             input_d->data_v->minmax_z[1] = input_d->data_v->matrix[i][2];
//         }
//     }
// }

void get_pol(FILE **file, data *input_d) {
    rewind(file);
    int i = 0;
    int k = 0;
    int amount_in_pol = 0;
    int count_memory = 0;
    int line = 0;
    

    char *buffer = NULL;
    char new_buf[MAX_LENGHT] = {};
    size_t len = MAX_LENGHT;

    while ((getline(&buffer, &len, file)) != -1) {
        if (buffer[0] == 'f' && buffer[1] == ' ') {

            for (int i = 1; buffer[i] != '\0'; i++) {
                if (is_digit(buffer[i]) && buffer[i - 1] == ' ') {
                    count_memory++;
                }
            }

            input_d->data_p->polygons[line] = calloc(count_memory, sizeof(double));
            line++;

            for (int i = 1; buffer[i] != '\0'; i++) {
                if (is_digit(buffer[i]) && buffer[i - 1] == ' ') {

                    while (is_digit(buffer[i])) {
                
                        new_buf[k] = buffer[i];
                        k++;
                        i++;
                    } 
                    new_buf[k] = '\0';
                    input_d->data_p->polygons[line][amount_in_pol] = atof(new_buf);
                    amount_in_pol++;
                    *new_buf = "\0";
                }
            }
            count_memory = 0;
            amount_in_pol = 0;
        }

    }
}

int is_digit(char buffer) { return (buffer >= '0' && buffer <= '9'); }