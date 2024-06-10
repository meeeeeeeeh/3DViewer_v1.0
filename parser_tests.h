#ifndef PARSER_TESTS_H_
#define PARSER_TESTS_H_

#include <check.h>
#include <unistd.h>

#include "viewer.h"

Suite *suite_viewer(void);

void run_tests(void);
void run_testcase(Suite *testcase);
double get_rand(double min, double max);
#endif
