#ifndef VIEWER_H
#define VIEWER_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#define MAX_LENGHT 256

/**
 * @brief структуруа описывающая вершины
 * @param matrix_vert матрица вершин
 * @param amount_vert количество вершин
 * @param minmax_x минимальное и максимальное значение по оси x
 * @param minmax_y минимальное и максимальное значение по оси y
 * @param minmax_z минимальное и максимальное значение по оси z
 */
typedef struct vertex
{
    double **matrix_vert;
    unsigned long int amount_vert;
    double minmax_x[2]; // min x, max x
    double minmax_y[2];
    double minmax_z[2];
} vertex;

/**
 * @brief структуруа описывающая полигоны
 * @param polygons матрица полигонов
 * @param amount_pol количество строк для полигонов
 * @param amount_pol_on_string количество полигонов в сроке
 */
typedef struct polygon {
    double **polygons;
    unsigned long int amount_pol;
    int *amount_pol_on_string;
    
} polygon;


/// \brief распарсивает файл
/// \param filename название файла
/// \param v указатель на структуру, описывающую вершины 
/// \param p указатель на структуру, описывающую полигоны
/// \return целое число - флаг ошибки
int parser(const char *filename, vertex *v, polygon *p);

/// \brief считает количество вершин
/// \param file указатель на поток
/// \param input_d указатель на структуру, описывающую вершины 
void counter_vert(FILE *file, vertex *input_d);

/// \brief считает количество полигонов
/// \param file указатель на поток
/// \param input_d указатель на структуру, описывающую полигоны 
void counter_pol(FILE *file, polygon *input_d);

/// \brief выделяет память для матрицы вершин
/// \param input_d указатель на структуру, описывающую вершины  
void memory_vert(vertex *input_d);

/// \brief выделяет память для полигонов
/// \param input_d указатель на структуру, описывающую полигоны   
void memory_pol(polygon *input_d);

/// \brief заполняет матрицу вершин
/// \param file указатель на поток
/// \param input_d указатель на структуру, описывающую вершины 
void get_vertex(FILE *file, vertex *input_d);

/// \brief заполняет матрицу полигонов
/// \param file указатель на поток
/// \param input_d указатель на структуру, описывающую полигоны
void get_pol(FILE *file, polygon *input_d);

/// \brief проверяет число или нет
/// \param  buffer символ
int is_digit(char buffer);

/// \brief очищает память, занятую матрицами
/// \param v указатель на структуру, описывающую вершины 
/// \param p указатель на структуру, описывающую полигоны
void remove_matrix(polygon *input_d, vertex *vert_d);

/// \brief зануляет массивы 
/// \param v указатель на структуру, описывающую вершины 
/// \param p указатель на структуру, описывающую полигоны
void all_is_null(polygon *input_d, vertex *vert_d);

/// \brief отцентровывает изображение 
/// \param v указатель на структуру, описывающую вершины 
/// \param center_x центр для оси х
/// \param center_y центр для оси у
/// \param center_z центр для оси z
void centralize(vertex *v);

/// \brief уменьшает изображение 
/// \param v указатель на структуру, описывающую вершины 
/// \param value во сколько раз необходимо уменьшить изображение
void decrease(vertex *v, double value);

/// \brief поворачивает изображение по оси z
/// \param v указатель на структуру, описывающую вершины 
/// \param angle угол поворота по оси z
void rotation_z(vertex *v, double angle);

/// \brief поворачивает изображение по оси x
/// \param v указатель на структуру, описывающую вершины 
/// \param angle угол поворота по оси x
void rotation_x(vertex *v, double angle);

/// \brief поворачивает изображение по оси y
/// \param v указатель на структуру, описывающую вершины 
/// \param angle угол поворота по оси y
void rotation_y(vertex *v, double angle);

/// \brief заполняет массивы минимума и максимума по каждой оси
/// \param v указатель на структуру, описывающую вершины 
void fill_min_max(vertex *input_d);

///// \brief отцентровывает и уменьшае изображение
///// \param v указатель на структуру, описывающую вершины
//void correct_image(vertex *v);

/// \brief двигает изображение
/// \param v указатель на структуру, описывающую вершины 
/// \param value на сколько необходимо подвинуть изображение
/// \param coord название оси, по которой подвинуть
void move_matrix(vertex *v, double value, char coord);

/// \brief изменяет размер изображения
/// \param v указатель на структуру, описывающую вершины 
/// \param value во сколько раз необходимо изменить изображение
void resize_matrix(vertex *v, double value);

char *get_file_name(const char *f);

int is_obj_file(const char *f);


#endif  // INC_3D_VIEWER_PARSER_H
