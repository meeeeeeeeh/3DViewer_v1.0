#ifndef VIEWER_H
#define VIEWER_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#define MAX_LENGHT 256

typedef struct data
{
    unsigned long int amount_vert;
    unsigned long int amount_pol;
    vertex *data_v;
    polygon *data_p;
} data;


typedef struct vertex
{
    double **matrix;
    double minmax_x[2] = {0}; // min x, max x
    double minmax_y[2] = {0};
    double minmax_z[2] = {0};
} vertex;


typedef struct polygon {
    double **polygons;
    //polygon *next_struct;
} polygon;

int open_obj(char *f_name, FILE **file);
void counter_vert(FILE *file, data *input_d);
void counter_pol(FILE **file, data *input_d);
int memory_vert(data *input_d);
int memory_pol(data *input_d);
void get_vertex(FILE **file, data *input_d);
void get_pol(FILE **file, data *input_d);
int is_digit(char buffer);
void fill_min_max(data *input_d);

#endif  // INC_3D_VIEWER_PARSER_H