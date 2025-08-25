#ifndef _TESTER_H_
#define _TESTER_H_

#include <math.h>
#include <stdio.h>
#include <float.h>

#include "typcon.h"
#include "io_functions.h"
#include "solver.h"

int solve_tester();
int one_case(struct coefficients test_coef, struct answers refans);
int number_rows(FILE* tests_file);
int check_roots(double x1, double x2, double x1ref, double x2ref);

#endif
