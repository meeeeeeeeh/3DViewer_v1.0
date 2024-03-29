#include "parser_tests.h"
START_TEST(s21_test_0) {
  vertex v;
  polygon p;
  char *test_file = "cube.obj";
  parser(test_file, &v, &p);
  ck_assert_uint_eq(v.amount_vert, 8);
  ck_assert_uint_eq(p.amount_pol, 12);

  remove_matrix(&p, &v);
}
END_TEST

START_TEST(s21_test_1) {
  vertex v;
  polygon p;
  char *test_file = "cheburashka.obj";
  parser(test_file, &v, &p);
  ck_assert_uint_eq(v.amount_vert, 6669);
  ck_assert_uint_eq(p.amount_pol, 13334);

  remove_matrix(&p, &v);
}
END_TEST

START_TEST(s21_test_2) {
  double **data = calloc(3, sizeof(double *));
  for (int i = 0; i < 3; i++) {
    data[i] = calloc(3, sizeof(double));
  }

  data[0][0] = -1.42;
  data[0][1] = -1.5;
  data[0][2] = 1.42;

  data[1][0] = -0.58;
  data[1][1] = -1.5;
  data[1][2] = 1.42;

  data[2][0] = -0.58;
  data[2][1] = -1.5;
  data[2][2] = 0.58;

  vertex v;
  polygon p;
  char *test_file = "abc.obj";
  parser(test_file, &v, &p);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(v.matrix_vert[i][j], data[i][j]);
    }
  }
  int *pol = calloc(5, sizeof(int));
  pol[0] = 4;
  pol[1] = 4;
  pol[2] = 3;
  pol[3] = 3;
  pol[4] = 4;

  for (int i = 0; i < 5; i++) {
    ck_assert_int_eq(p.amount_pol_on_string[i], pol[i]);
  }

  for (int i = 0; i < 3; i++) {
    free(data[i]);
  }
  free(data);
  free(pol);
  remove_matrix(&p, &v);
}
END_TEST

START_TEST(resize_test) {
  double **data = calloc(3, sizeof(double *));
  for (int i = 0; i < 3; i++) {
    data[i] = calloc(3, sizeof(double));
  }

  data[0][0] = -4.26;
  data[0][1] = -4.5;
  data[0][2] = 4.26;

  data[1][0] = -1.74;
  data[1][1] = -4.5;
  data[1][2] = 4.26;

  data[2][0] = -1.74;
  data[2][1] = -4.5;
  data[2][2] = 1.74;

  vertex v;
  polygon p;
  char *test_file = "abc.obj";
  parser(test_file, &v, &p);

  resize_matrix(&v, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(v.matrix_vert[i][j], data[i][j], 2);
    }
  }

  remove_matrix(&p, &v);

  for (int i = 0; i < 3; i++) free(data[i]);

  free(data);
}
END_TEST

START_TEST(rotation_test_z) {
  double **data = calloc(3, sizeof(double *));
  for (int i = 0; i < 3; i++) {
    data[i] = calloc(3, sizeof(double));
  }

  data[0][0] = -1.13795;
  data[0][1] = 2.031117;
  data[0][2] = 1.420000;

  data[1][0] = -0.329370;
  data[1][1] = 1.574140;
  data[1][2] = 1.420000;

  data[2][0] = -0.329370;
  data[2][1] = 1.574140;
  data[2][2] = 0.580000;

  vertex v;
  polygon p;
  char *test_file = "abc.obj";
  parser(test_file, &v, &p);
  // v -1.42 -1.5 1.42
  // v -0.58 -1.5 1.42
  // v -0.58 -1.5 0.58

  // 0.375450 2.031117 1.420000
  // -0.329370 1.574140 1.420000
  // -0.329370 1.574140 0.580000
  rotation_z(&v, 10);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(v.matrix_vert[i][j], data[i][j], 5);
    }
  }

  remove_matrix(&p, &v);
  for (int i = 0; i < 3; i++) {
    free(data[i]);
  }
  free(data);
}
END_TEST

START_TEST(rotation_test_y) {
  double **data = calloc(3, sizeof(double *));
  for (int i = 0; i < 3; i++) {
    data[i] = calloc(3, sizeof(double));
  }

  data[0][0] = -1.64501;
  data[0][1] = -1.500000;
  data[0][2] = -0.418972;

  data[1][0] = 1.259171;
  data[1][1] = -1.500000;
  data[1][2] = -0.875949;

  data[2][0] = 0.802194;
  data[2][1] = -1.500000;
  data[2][2] = -0.171129;

  vertex v;
  polygon p;
  char *test_file = "abc.obj";
  parser(test_file, &v, &p);
  // v -1.42 -1.5 1.42
  // v -0.58 -1.5 1.42
  // v -0.58 -1.5 0.58

  // 1.963992 -1.500000 -0.418972
  // 1.259171 -1.500000 -0.875949
  // 0.802194 -1.500000 -0.171129

  rotation_y(&v, 10);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(v.matrix_vert[i][j], data[i][j], 5);
    }
  }

  remove_matrix(&p, &v);
  for (int i = 0; i < 3; i++) {
    free(data[i]);
  }
  free(data);
}
END_TEST

START_TEST(rotation_test_x) {
  double **data = calloc(3, sizeof(double *));
  for (int i = 0; i < 3; i++) {
    data[i] = calloc(3, sizeof(double));
  }

  data[0][0] = -1.42;
  data[0][1] = -1.72379;
  data[0][2] = -0.375450;

  data[1][0] = -0.580000;
  data[1][1] = 2.031117;
  data[1][2] = -0.375450;

  data[2][0] = -0.580000;
  data[2][1] = 1.574140;
  data[2][2] = 0.329370;

  vertex v;
  polygon p;
  char *test_file = "abc.obj";
  parser(test_file, &v, &p);

  // v -1.42 -1.5 1.42
  // v -0.58 -1.5 1.42
  // v -0.58 -1.5 0.58

  //-1.420000 2.031117 -0.375450
  //-0.580000 2.031117 -0.375450
  //-0.580000 1.574140 0.329370

  rotation_x(&v, 10);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(v.matrix_vert[i][j], data[i][j], 5);
    }
  }

  remove_matrix(&p, &v);
  for (int i = 0; i < 3; i++) {
    free(data[i]);
  }
  free(data);
}
END_TEST

START_TEST(move_test_x) {
  double **data = calloc(3, sizeof(double *));
  for (int i = 0; i < 3; i++) {
    data[i] = calloc(3, sizeof(double));
  }

  data[0][0] = 8.580000;
  data[0][1] = -1.500000;
  data[0][2] = 1.420000;

  data[1][0] = 9.420000;
  data[1][1] = -1.500000;
  data[1][2] = 1.420000;

  data[2][0] = 9.420000;
  data[2][1] = -1.500000;
  data[2][2] = 0.580000;

  vertex v;
  polygon p;
  char *test_file = "abc.obj";
  parser(test_file, &v, &p);

  // v -1.42 -1.5 1.42
  // v -0.58 -1.5 1.42
  // v -0.58 -1.5 0.58

  // 8.580000 -1.500000 1.420000
  // 9.420000 -1.500000 1.420000
  // 9.420000 -1.500000 0.580000

  move_matrix(&v, 10, 'x');
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(v.matrix_vert[i][j], data[i][j]);
    }
  }

  remove_matrix(&p, &v);
  for (int i = 0; i < 3; i++) {
    free(data[i]);
  }
  free(data);
}
END_TEST

START_TEST(move_test_y) {
  double **data = calloc(3, sizeof(double *));
  for (int i = 0; i < 3; i++) {
    data[i] = calloc(3, sizeof(double));
  }

  data[0][0] = -1.420000;
  data[0][1] = 8.500000;
  data[0][2] = 1.420000;

  data[1][0] = -0.580000;
  data[1][1] = 8.500000;
  data[1][2] = 1.420000;

  data[2][0] = -0.580000;
  data[2][1] = 8.500000;
  data[2][2] = 0.580000;

  vertex v;
  polygon p;
  char *test_file = "abc.obj";
  parser(test_file, &v, &p);

  // v -1.42 -1.5 1.42
  // v -0.58 -1.5 1.42
  // v -0.58 -1.5 0.58

  //-1.420000 8.500000 1.420000
  //-0.580000 8.500000 1.420000
  //-0.580000 8.500000 0.580000

  move_matrix(&v, 10, 'y');
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(v.matrix_vert[i][j], data[i][j]);
    }
  }

  remove_matrix(&p, &v);
  for (int i = 0; i < 3; i++) {
    free(data[i]);
  }
  free(data);
}
END_TEST

START_TEST(move_test_z) {
  double **data = calloc(3, sizeof(double *));
  for (int i = 0; i < 3; i++) {
    data[i] = calloc(3, sizeof(double));
  }

  data[0][0] = -1.420000;
  data[0][1] = -1.500000;
  data[0][2] = 11.420000;

  data[1][0] = -0.580000;
  data[1][1] = -1.500000;
  data[1][2] = 11.420000;

  data[2][0] = -0.580000;
  data[2][1] = -1.500000;
  data[2][2] = 10.580000;

  vertex v;
  polygon p;
  char *test_file = "abc.obj";
  parser(test_file, &v, &p);

  // v -1.42 -1.5 1.42
  // v -0.58 -1.5 1.42
  // v -0.58 -1.5 0.58

  //-1.420000 -1.500000 11.420000
  //-0.580000 -1.500000 11.420000
  //-0.580000 -1.500000 10.580000

  move_matrix(&v, 10, 'z');
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(v.matrix_vert[i][j], data[i][j]);
    }
  }

  remove_matrix(&p, &v);
  for (int i = 0; i < 3; i++) {
    free(data[i]);
  }
  free(data);
}
END_TEST

START_TEST(centr_test) {
  double **data = calloc(3, sizeof(double *));
  for (int i = 0; i < 3; i++) {
    data[i] = calloc(3, sizeof(double));
  }

  data[0][0] = -0.500000;
  data[0][1] = 0.000000;
  data[0][2] = 0.500000;

  data[1][0] = 0.500000;
  data[1][1] = 0.000000;
  data[1][2] = 0.500000;

  data[2][0] = 0.500000;
  data[2][1] = 0.000000;
  data[2][2] = -0.500000;

  vertex v;
  polygon p;
  char *test_file = "abc.obj";
  parser(test_file, &v, &p);

  // v -1.42 -1.5 1.42
  // v -0.58 -1.5 1.42
  // v -0.58 -1.5 0.58

  //-0.500000 0.000000 0.500000
  // 0.500000 0.000000 0.500000
  // 0.500000 0.000000 -0.500000

  correct_image(&v);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(v.matrix_vert[i][j], data[i][j], 2);
    }
  }

  remove_matrix(&p, &v);
  for (int i = 0; i < 3; i++) {
    free(data[i]);
  }
  free(data);
}
END_TEST

Suite *suite_viewer(void) {
  Suite *s = suite_create("suite_3d_view");

  TCase *tc = tcase_create("suite_viewer");
  TCase *affine = tcase_create("affine tests");

  tcase_add_test(tc, s21_test_0);
  tcase_add_test(tc, s21_test_1);
  tcase_add_test(tc, s21_test_2);
  tcase_add_test(affine, resize_test);
  tcase_add_test(affine, rotation_test_z);
  tcase_add_test(affine, rotation_test_y);
  tcase_add_test(affine, rotation_test_x);

  tcase_add_test(affine, move_test_x);
  tcase_add_test(affine, move_test_y);
  tcase_add_test(affine, move_test_z);
  tcase_add_test(affine, centr_test);

  suite_add_tcase(s, tc);
  suite_add_tcase(s, affine);
  return s;
}
