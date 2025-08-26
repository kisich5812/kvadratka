#include <math.h>
#include <stdio.h>
#include <float.h>

#include "tester.h"

int solve_tester()
{
	int fail_tests = 0;

	FILE *tests_file = NULL;
	tests_file = fopen("tests.txt", "r");
	if(tests_file == NULL)
	{
		printf("Неудалось открыть файл\n");
		return 1;
	}

	unsigned long num_rows = number_rows(tests_file);
	struct equation_parametrs* test_params;
	test_params = (struct equation_parametrs*) calloc(num_rows, sizeof(struct equation_parametrs));
	
	for (unsigned long i = 0; i < num_rows; i++)
	{
		fscanf(tests_file, "%lg", &test_params[i].coef.a);
		fscanf(tests_file, "%lg", &test_params[i].coef.b);
		fscanf(tests_file, "%lg", &test_params[i].coef.c);
		fscanf(tests_file, "%d", &test_params[i].ans.n_roots);
		fscanf(tests_file, "%lg", &test_params[i].ans.x1);
		fscanf(tests_file, "%lg", &test_params[i].ans.x2);
		fail_tests += one_case(test_params[i].coef, test_params[i].ans);
	}
	
	free(test_params);
	fclose(tests_file);

	return fail_tests;
}

unsigned long number_rows(FILE* tests_file)
{
	char ch = 0;
	unsigned long num_rows = 0;
	while(fscanf(tests_file, "%c", &ch) == 1 && ch != EOF)
		if(ch == '\n')
			num_rows++;
	rewind(tests_file);
	return num_rows;
}


int one_case(struct coefficients test_coef, struct answers refans)
{
	struct answers test_roots = {.x1 = NAN, .x2 = NAN, .n_roots = no_calculate_err};
	solve(test_coef, &test_roots);

	if (!(check_roots(test_roots.x1, test_roots.x2, refans.x1, refans.x2) && test_roots.n_roots == refans.n_roots))
	{
		if (refans.n_roots != inf_roots)
		{
			printf("При вводимых коэффициентах a = %lg, b = %lg, c = %lg ожидается %d корнь(-я):\n", test_coef.a, test_coef.b, test_coef.c, refans.n_roots);
			printf("Ожидаемый вывод: \n");
			print_answer(refans);
		}
		else
			printf("При вводимых коэффициентах a = %lg, b = %lg, c = %lg ожидается бесконечность корней\n", test_coef.a, test_coef.b, test_coef.c);
		printf("Реальный вывод:\n");
		print_test_error(test_roots);
		return 1;
	}
	return 0;
}

int check_roots(double x1, double x2, double x1ref, double x2ref) // вернёт 1 если корни равны иначе 0
{
	if ((compare_doubles(x1, x1ref) == equal && compare_doubles(x2, x2ref) == equal))
		return 1;
	if ((compare_doubles(x1, x2ref) == equal && compare_doubles(x2, x1ref) == equal))
		return 1;
	else
		return 0;
}
