#ifndef _SOLVER_H_
#define _SOLVER_H_

#include <assert.h>
#include <math.h>
#include <float.h>

#include "typcon.h"

int solve(struct coefficients coef, struct answers* roots);
int linear_case(struct coefficients coef, struct answers* roots);
int square_case(struct coefficients coef, struct answers* roots);
int compare_doubles(double ch1, double ch2);

#endif /* _SOLVER_h_ */
