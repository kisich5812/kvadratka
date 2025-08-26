#ifndef _IO_FUNCTIONS_H_
#define _IO_FUNCTIONS_H_

#include "solver.h"
#include "typcon.h"

int enter_coef(struct coefficients* enter_values);
int check_enter(double* double_number);
int clean_buffer();
int print_answer(struct answers roots);
int continue_solve();
int print_test_error(struct answers roots);
int poltorashka_standard_2005();

#endif
