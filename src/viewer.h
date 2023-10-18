#ifndef VIEWER_H
#define VIEWER_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#define MAX_LENGHT 256

typedef struct vertex
{
    double **matrix_vert;
    unsigned long int amount_vert;
    double minmax_x[2]; // min x, max x
    double minmax_y[2];
    double minmax_z[2];
} vertex;

typedef struct polygon {
    double **polygons;
    unsigned long int amount_pol;
    double *amount_pol_on_string;
    //polygon *next_struct;
} polygon;

// typedef struct data
// {
    
    
//     vertex *data_v;
//     polygon *data_p;
// } data;

int parser(char *filename, vertex *v, polygon *p);

//int open_obj(char *f_name, FILE *file);
void counter_vert(FILE *file, vertex *input_d);
void counter_pol(FILE *file, polygon *input_d);
void memory_vert(vertex *input_d);
void memory_pol(polygon *input_d);
void get_vertex(FILE *file, vertex *input_d);
void get_pol(FILE *file, polygon *input_d);
int is_digit(char buffer);
void remove_matrix(polygon *input_d, vertex *vert_d);
void all_is_null(polygon *input_d, vertex *vert_d);
double centralize(vertex *v, double *center_x, double *center_y, double *center_z);
void decrease(vertex *v, double value, double max);
void rotation_z(vertex *v, double angle);
void rotation_x(vertex *v, double angle);
void rotation_y(vertex *v, double angle);
void fill_min_max(vertex *input_d);
void correct_image(vertex *v);
void move(vertex *v, double value, char coord);
void resize(vertex *v, double value);


#endif  // INC_3D_VIEWER_PARSER_H