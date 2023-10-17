#include "viewer.h"

int main() {
    FILE *file = NULL;
    //data *input = NULL;
    vertex v;
    polygon p;
    //data input;

    all_is_null(&p, &v);
    int err_flag = 0;
    file = fopen("abc.obj", "r");
    if(!file) err_flag = 1;

    else {
        counter_vert(file, &v);
        counter_pol(file, &p);
        memory_vert(&v);
        memory_pol(&p);

        get_vertex(file, &v);
        get_pol(file, &p);

        printf("%ld\n", v.amount_vert);
        printf("%ld\n", p.amount_pol);
        for(long unsigned int i =0; i < v.amount_vert; i++) {
            for(int j = 0; j < 3; j++) {
                printf("%f ", v.matrix_vert[i][j]);
            }
            printf("\n");
        }

        //remove_matrix(&p, &v);
    }
    
    fclose(file);

    printf("\n\n\n");

    fill_min_max(&v);

    printf("x: %f %f\n", v.minmax_x[0], v.minmax_x[1]);
    printf("y: %f %f\n", v.minmax_y[0], v.minmax_y[1]);
    printf("z: %f %f\n", v.minmax_z[0], v.minmax_z[1]);

    
    printf("\nerrors - %d",err_flag);
    return err_flag;
}


void counter_vert(FILE *file, vertex *input_d) {
    rewind(file);
    char *buffer = NULL;
    size_t len = MAX_LENGHT;
    //input_d->amount_vert = 0;
    while ((getline(&buffer, &len, file)) != -1) {
        if (buffer[0] == 'v' && buffer[1] == ' ') {
            input_d->amount_vert++;
        }
    }
    free(buffer);
}

void counter_pol(FILE *file, polygon *input_d) {
    rewind(file);
    char *buffer = NULL;
    size_t len = MAX_LENGHT;
    while ((getline(&buffer, &len, file)) != -1) {
        if (buffer[0] == 'f' && buffer[1] == ' ') {
            input_d->amount_pol++;
        }
    }
    free(buffer);
}

int memory_vert(vertex *input_d) {
    //int err_flag = 0;
    input_d->matrix_vert = calloc(input_d->amount_vert, sizeof(double *));
    for (unsigned long int i=0; i < input_d->amount_vert; i++) {
        input_d->matrix_vert[i] = calloc(3, sizeof(double));
    }
    return 0;
}

int memory_pol(polygon *input_d) {
    //int err_flag = 0;
    input_d->polygons = calloc(input_d->amount_pol, sizeof(double *));
    input_d->amount_pol_on_string = calloc(input_d->amount_pol, sizeof(double *));
    return 0;
}

void get_vertex(FILE *file, vertex *input_d) {
    rewind(file);
    int i = 0;

    char *buffer = NULL;
    size_t len = MAX_LENGHT;

    while ((getline(&buffer, &len, file)) != -1) {
        if (buffer[0] == 'v' && buffer[1] == ' ') {
            sscanf(buffer, "v %lf %lf %lf", &input_d->matrix_vert[i][0], &input_d->matrix_vert[i][1], &input_d->matrix_vert[i][2]);
            i++;
        }
    }
    free(buffer);
}

void get_pol(FILE *file, polygon *input_d) {
    rewind(file);
    //int i = 0;
    int k = 0;
    int amount_in_pol = 0;
    int count_memory = 0;
    int line = 0;
    

    char *buffer = NULL;
    //char new_buf[MAX_LENGHT] = {};
    size_t len = MAX_LENGHT;

    while ((getline(&buffer, &len, file)) != -1) {
        if (buffer[0] == 'f' && buffer[1] == ' ') {

            for (int i = 1; buffer[i] != '\0'; i++) {
                if (is_digit(buffer[i]) && buffer[i - 1] == ' ') {
                    count_memory++;
                }
            }

            input_d->polygons[line] = calloc(count_memory, sizeof(double));
            
            for (int i = 1; buffer[i] != '\0'; i++) {
                if (is_digit(buffer[i]) && buffer[i - 1] == ' ') {
                    char new_buf[MAX_LENGHT] = "\0";

                    while (is_digit(buffer[i])) {
                
                        new_buf[k] = buffer[i];
                        k++;
                        i++;
                    } 
                    //new_buf[k] = '\0';
                    input_d->polygons[line][amount_in_pol] = atof(new_buf);
                    printf("%f ", input_d->polygons[line][amount_in_pol]);
                    amount_in_pol++;
                    k = 0;
                }
                
            }
            printf("\n");
            
            count_memory = 0;
            input_d->amount_pol_on_string[line] = amount_in_pol+1;
            line++;
            amount_in_pol = 0;
        }

    }
    free(buffer);
}

int is_digit(char buffer) { return (buffer >= '0' && buffer <= '9'); }


void remove_matrix(polygon *input_d, vertex *vert_d) {
  if (input_d->polygons) {
    for (long unsigned int i = 0; i < input_d->amount_pol; i++) {
      if (input_d->polygons[i]) {
        free(input_d->polygons[i]);
      }
    }
    free(input_d->polygons);
    input_d->polygons= NULL;
  }
  if (input_d->amount_pol_on_string) {
    free(input_d->amount_pol_on_string);
  }

  if (vert_d->matrix_vert) {
    for (long unsigned int i = 0; i < vert_d->amount_vert; i++) {
      if (vert_d->matrix_vert[i]) {
        free(vert_d->matrix_vert[i]);
      }
    }
    free(vert_d->matrix_vert);
    vert_d->matrix_vert= NULL;
  }
}

void all_is_null(polygon *input_d, vertex *vert_d) {
    
    vert_d->minmax_x[0] = 0;
    vert_d->minmax_x[1] = 0;
    
    
    vert_d->minmax_y[0] = 0;
    vert_d->minmax_y[1] = 0;
    
    
    vert_d->minmax_z[0] = 0;
    vert_d->minmax_z[1] = 0;


    vert_d->amount_vert = 0;


    input_d->amount_pol = 0;

    input_d->polygons = NULL;
    vert_d->matrix_vert = NULL;
}