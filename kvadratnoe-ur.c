#include <stdio.h>
#include <float.h>
#include <math.h>
#include <assert.h>

struct coefficients {
	double a;
	double b;
	double c;
};

struct answers {
	double x1;
	double x2;
	int n_roots;
};

int enter_coef(struct coefficients* enter_values);
int check_enter(double* double_number);
int clean_buffer();
int solve(struct coefficients coef, struct answers* roots);
int linear_case(struct coefficients coef, struct answers* roots);
int square_case(struct coefficients coef, struct answers* roots);
int compare_doubles(double ch1, double ch2);
int print_answer(struct answers roots);
int continue_solve();
int solve_tester();
int one_case(struct coefficients test_coef, struct answers refans);
int print_test_error(struct answers roots);

const double PREDEL = pow(10, -DBL_DIG);

const int standart_return = 1;
enum number_of_roots {
	inf_roots = -1,
	no_roots,
	one_root,
	two_roots,
	no_calculate_err
};

enum compare {
	less = -1,
	equal,
	more,
	no_compare_err = 3
};
enum continue_sol {
	no=0,
	yes=1
};

int main(void)
{
	struct coefficients coef = {.a = NAN, .b = NAN, .c = NAN};
	struct answers roots = {.x1 = NAN, .x2 = NAN, .n_roots = no_calculate_err};
	printf("Эта программа предназначена для решения квадратных уравнений\n");
	printf("представленных в виде a*x^2+b*x+c=0.\n");
	if(solve_tester())
	{
		printf("Аварийная остановка. Ошибка проверки программы.\n");
		return 0;
	}
	do
	{
		enter_coef(&coef);
		assert(solve(coef, &roots) != 3);
		print_answer(roots);
		printf("Хотите ли вы решаить ещё одно уравнение? [y/n]: ");
	} while (continue_solve());
	return 0;
}

int solve(struct coefficients coef, struct answers* roots)
{

	assert(!isnan(coef.a));
	assert(!isnan(coef.b));
	assert(!isnan(coef.c));
	assert(roots);

	if (compare_doubles(coef.a, 0) == equal)		 // разбор случаев
		return linear_case(coef, roots);
	else if (compare_doubles(coef.b, 0) == equal && compare_doubles(coef.c, 0) == equal)
	{
		roots->x1 = 0;
		roots->n_roots = one_root;
		return one_root;
	}
	else if (compare_doubles(coef.c, 0) == equal)
	{
		roots->x2 = -coef.b/coef.a;
		roots->x1 = 0;
		roots->n_roots = two_roots;
		return two_roots;
	}
	else
		return square_case(coef, roots);
	return no_calculate_err;       // возвращаем ошибку(нет расчётов)
}

int linear_case(struct coefficients coef, struct answers* roots)
{
	if (compare_doubles(coef.b, 0) == equal)
	{
		if (compare_doubles(coef.c, 0) == equal)
		{
			roots->n_roots = inf_roots;
			return inf_roots;		// 0*x^2 + 0*x + 0 = 0 бесконечное множество решений, возвращаем -1
		}
		else
		{
			roots->n_roots = no_roots;
			return no_roots;		// 0*x^2 + 0*x + c = 0 нет корней, возвращаем 0
		}
	}
	else
	{
		if (compare_doubles(coef.c, 0) == equal)// 0*x^2 + b*x + 0 = 0 единственный корень, возвращаем 1
			roots->x1 = 0;
		else
			roots->x1 = -coef.c/coef.b;	// 0*x^2 + b*x + с = 0 единственный корень, возвращаем 1
		roots->n_roots = one_root;
		return one_root;
	}
	
	return no_calculate_err; // код ошибки
}

int square_case(struct coefficients coef, struct answers* roots)
{
	double d = coef.b * coef.b - 4 * coef.a * coef.c;       // считаем дискриминант
	double sqrt_d = sqrt(d);				// и корень из него
	
	if (compare_doubles(d, 0) == more)			// a*x^2 + b*x + c = 0
	{
		roots->x1 = (-coef.b + sqrt_d) / (2*coef.a);
		roots->x2 = (-coef.b - sqrt_d) / (2*coef.a);
		if (compare_doubles(roots->x1, roots->x2) == equal)
		{
			roots->n_roots = one_root;
			return one_root;
		}
		else
		{
			roots->n_roots = two_roots;
			return two_roots;
		}
	}
	
	if (compare_doubles(d, 0) == equal)
	{
		if(compare_doubles(coef.b, 0) == equal)
			roots->x1 = 0;
		else
			roots->x1 = -coef.b/(2 * coef.a);
		roots->n_roots = one_root;
		return one_root;
	}
	
	if(compare_doubles(d, 0) == less)
	{
		roots->n_roots = no_roots;
		return no_roots;
	}
	
	return no_calculate_err; // код ошибки
}

int compare_doubles(double ch1, double ch2)	     // 0 - ch1 == ch2 1 - ch1 > ch2 -1 - ch1 < ch2
{
	if(isnan(ch1) && isnan(ch2))
		return equal;
	if (fabs(ch1 - ch2) < PREDEL)   // ==
		return equal;
	else if (ch1 - ch2 > 0)	 // ch1 > ch2
		return more;
	else if (ch1 - ch2 < 0)	 // ch1 < ch2
		return less;
	return no_compare_err;	  // код ошибки
}

int enter_coef(struct coefficients* enter_values)
{
	assert(enter_values);
	printf("Введите коэффициент a:\n");
	check_enter(&(enter_values->a));
	printf("Введите коэффициент b:\n");
	check_enter(&(enter_values->b));
	printf("Введите коэффициент c:\n");
	check_enter(&(enter_values->c));
	return standart_return;
}

int check_enter(double* double_number)
{
	bool no_input = 1;
	while (no_input == 1)
	{
		if (scanf("%lg", double_number))
			no_input = 0;
		if (clean_buffer())
			no_input = 1;
		if (compare_doubles(*double_number, NAN) == 0)
			no_input = 1;
		if (no_input)
			printf("Ошибка ввода. Попробуйте ещё раз:\n");
	}
	return standart_return;
}

int clean_buffer()
{
	int quantity_sim = 0;
	while (getchar() != '\n')
		quantity_sim++;
	return quantity_sim;
}

int print_answer(struct answers roots)
{
        switch(roots.n_roots)
        {
                case inf_roots:
                        printf("x - любое число\n");
                        return standart_return;
                case no_roots:
                        printf("Уравнение не имеет корней\n");
                        return standart_return;
                case one_root:
                        printf("Уравнение имеет один корень:\nx = %g\n", roots.x1);
                        return standart_return;
                case two_roots:
                        printf("Уравнение имеет два корня:\nx1 = %g\nx2 = %g\n", roots.x1, roots.x2);
                        return standart_return;
                default:
                        printf("При выполнении произошла ошибка!\n");
                        return standart_return;
        }
}

int continue_solve()
{
	int ch = getchar(); // scanf("%s", enter[2]); ?clean_buffer();
	if (ch == 'y')
		return yes;
	if (ch == 'n')
		return no;
	return no;
}

int solve_tester()
{
	int fail_tests = 0;
	
	struct coefficients test_coef = {.a = 1, .b = 2, .c = 1};
	struct answers refans = {.x1 = -1, .x2 = NAN, .n_roots = one_root};
	fail_tests += one_case(test_coef, refans);

        test_coef.a = 0; test_coef.b = 0; test_coef.c = 0;
	refans.x1 = NAN, refans.x2 = NAN, refans.n_roots = inf_roots;
	fail_tests += one_case(test_coef, refans);

	test_coef.a = 1; test_coef.b = 4; test_coef.c = 5;
        refans.x1 = NAN, refans.x2 = NAN, refans.n_roots = no_roots;
        fail_tests += one_case(test_coef, refans);

	test_coef.a = 1; test_coef.b = 5; test_coef.c = 4;
        refans.x1 = -1, refans.x2 = -4, refans.n_roots = two_roots;
        fail_tests += one_case(test_coef, refans);

	test_coef.a = 1; test_coef.b = 5; test_coef.c = 0;
        refans.x1 = 0, refans.x2 = -5, refans.n_roots = two_roots;
        fail_tests += one_case(test_coef, refans);
	
	test_coef.a = 3; test_coef.b = 0; test_coef.c = 0;
        refans.x1 = 0, refans.x2 = NAN, refans.n_roots = one_root;
        fail_tests += one_case(test_coef, refans);

	return fail_tests;
}

int one_case(struct coefficients test_coef, struct answers refans)
{
	struct answers test_roots = {.x1 = NAN, .x2 = NAN, .n_roots = no_calculate_err};
	solve(test_coef, &test_roots);
	
	if(!(compare_doubles(test_roots.x1, refans.x1) == equal && compare_doubles(test_roots.x2, refans.x2) == equal && test_roots.n_roots == refans.n_roots))
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

int print_test_error(struct answers roots)
{
	switch(roots.n_roots)
	{
		case inf_roots:
			printf("бесконечность корней");
			return standart_return;
		case no_roots:
			printf("Уравнение не имеет корней\n");
			return standart_return;
		case one_root:
			printf("Уравнение имеет один корень:\nx = %g\n", roots.x1);
			return standart_return;
		case two_roots:
			printf("Уравнение имеет два корня:\nx1 = %g\nx2 = %g\n", roots.x1, roots.x2);
			return standart_return;
		default:
			printf("Уравнение имеет %d корней.\nx1 = %g\nx2 = %g\n", roots.n_roots, roots.x1, roots.x2);
			return standart_return;
	}
}
