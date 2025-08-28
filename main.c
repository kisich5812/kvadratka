#include <stdio.h>
#include <float.h>
#include <math.h>
#include <assert.h>
#include "main.h"

int main(int argc, char* argv[])
{
	bool pranc_script = 0;
	switch(processing_flags(argc, argv))
	{
		case stop_prog:
			return 0;
		case norm_version:
			break;
		case pranc_version:
			pranc_script = 1;
			break;
		default:
			break;
	}

	if(pranc_script && cat_sleep_stop_prog())
		return 0;

	struct coefficients coef = {.a = NAN, .b = NAN, .c = NAN};
	struct answers roots = {.x1 = NAN, .x2 = NAN, .n_roots = no_calculate_err};
	
	poltorashka_standard_2005(pranc_script);
	
	printf("Эта программа предназначена для решения квадратных уравнений\n");
	printf("представленных в виде a*x^2+b*x+c=0.\n");
	//printf("Провалено тестов: %d\n", solve_tester());
	if(solve_tester())
	{
		printf("Аварийная остановка. Ошибка проверки программы.\n");
		return 0;
	}
	
	if (pranc_script)
	{
		do
                {
                        enter_coef(&coef);
                       	int out_solution = pranc_coef(coef);
			if (out_solution)
			{
				assert(solve(coef, &roots) != 3);
                        	print_answer(roots);
			}
			printf("Хотите ли вы решаить ещё одно уравнение? [y/n]: ");
                } while (continue_solve());
	}
	else
	{
		do
		{
			enter_coef(&coef);
			assert(solve(coef, &roots) != 3);
			print_answer(roots);
			printf("Хотите ли вы решаить ещё одно уравнение? [y/n]: ");
		} while (continue_solve());
	}

	printf("\nCOMMIT TO GITHUB\n");

	return 0;
}
