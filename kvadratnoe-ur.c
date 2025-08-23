#include <stdio.h>
#include <math.h>
#include <float.h>
#include <assert.h>

int solve(double a, double b, double c, double* x1, double* x2);	// функция решает уравнение и считает количество корней, возвращает количество корней, -1 если корней бесконечность, 3 если произошла ошибка
int printanswer(double x1, double x2, int nRoots);			// вывод ответов
int compare_doubles(double ch1, double ch2);				// проверка равны ли числа; возвращает 1 если равны, 0 если не равны
int input_check(double a, double b, double c);				// проверка ввода коэффициентов; возвращает 1 если успешно, 0 если произошла ошибка
int entercoef(double* a, double* b, double* c);				// ввод коэффициентов
int linear_case(double b, double c, double* x1);			// решает случай линейного уравнения
int square_case(double a, double b, double c, double* x1, double* x2);	// решает случай квадратного уравнения
int continue_solve();							// продолжать ли решать уравнения
int cleanbuffer();							// очищает входной буфер для корректной работы scanf
int checkenter(double* a);						// проверяет корректность введённого коэффициента

int main(void)
{
	double a = NAN,		// коэффициенты для уравнения
	       b = NAN,
	       c = NAN;
	double x1 = NAN,	// ответы
	       x2 = NAN;
	printf("Эта программа преднахначена для решения квадратных уравнений\n");
        printf("представленных в виде a*x^2+b*x+c=0.\n");
	do
	{
		entercoef(&a, &b, &c);
		int nRoots = solve(a, b, c, &x1, &x2);
		printanswer(x1, x2, nRoots);
		printf("Хотите ли вы решаить ещё одно уравнение? [y/n]: ");
	} while (continue_solve());
	return 0;
}

int solve(double a, double b, double c, double* x1, double* x2)
{

	assert(!isnan(a));
	assert(!isnan(b));
	assert(!isnan(c));
	assert(x1);
	assert(x2);
	if (compare_doubles(a, 0) == 0)			// разбор случаев
	{
		return linear_case(b, c, x1);
	}
	else
	{
		return square_case(a, b, c, x1, x2);
	}
	return 3;	// возвращаем тройку как сигнал об ошибке
}

int linear_case(double b, double c, double* x1)
{
 	if (compare_doubles(b, 0) == 0)
        {
                if (compare_doubles(c, 0) == 0)
                        return -1;              // 0*x^2 + 0*x + 0 = 0 бесконечное множество решений, возвращаем -1
                else
                        return 0;               // 0*x^2 + 0*x + c = 0 нет корней, возвращаем 0
        }
        else
        {
                if (compare_doubles(c, 0) == 0) // 0*x^2 + b*x + 0 = 0 единственный корень, возвращаем 1
                        *x1 = 0;
                else
                        *x1 = -c/b;             // 0*x^2 + b*x + с = 0 единственный корень, возвращаем 1
                return 1;
        }
	return 3; // код ошибки
}

int square_case(double a, double b, double c, double* x1, double* x2)
{
	double d = b*b - 4*a*c;         // считаем дискриминант
        double sqrt_d = sqrt(d);        // и корень из него
        if (compare_doubles(d, 0) == 1) // a*x^2 + b*x + c = 0
        {
        	*x1 = (-b + sqrt_d) / (2*a);
                *x2 = (-b - sqrt_d) / (2*a);
                if (compare_doubles(*x1, *x2) == 0)
                	return 1;
                else
                        return 2;
        }
        if (compare_doubles(d, 0) == 0)
        {
                if(compare_doubles(b, 0) == 0)
                        *x1 = 0;
                else
                        *x1 = -b/(2 * a);
                return 1;
        }
        if(compare_doubles(d, 0) == -1)
                return 0;
	return 3; // код ошибки
}

int printanswer(double x1, double x2, int nRoots)
{
	if (nRoots == -1)
		printf("х - любое число\n");
	else if (nRoots == 0)
		printf("Уравнение не имеет корней\n");
	else if (nRoots == 1)
	{
		printf("Уравнение имеет один корень:\n");
                printf("x = %g\n", x1);
	}
	else if (nRoots == 2)
	{
		printf("Уравнение имеет два корня:\n");
                printf("x1 = %g\nx2 = %g\n", x1, x2);
	}
	else
		printf("При выполнении произошла ошибка!\n");
	return 1;
}

int compare_doubles(double ch1, double ch2)		// 0 - ch1 == ch2 1 - ch1 > ch2 -1 - ch1 < ch2
{
	assert(!isnan(ch1));
	assert(!isnan(ch2));
	const double PREDEL = pow(10, -DBL_DIG);
	if (fabs(ch1 - ch2) < PREDEL) 	// ==
		return 0;
	else if (ch1 - ch2 > 0)		// ch1 > ch2
		return 1;
	else if (ch1 - ch2 < 0)		// ch1 < ch2
		return -1;
	return 3; 			// код ошибки
}

int entercoef(double* a, double* b, double* c)
{
	assert(a);
	assert(b);
	assert(c);
	printf("Введите коэффициент a:\n");
	checkenter(a);
	printf("Введите коэффициент b:\n");
        checkenter(b);
	printf("Введите коэффициент c:\n");
        checkenter(c);
	return 1;
}

int checkenter(double* a)
{
	bool status = 1;
        while (status == 1)
        {
                if (scanf("%lg", a))
                        status = 0;
		if (cleanbuffer())
                        status = 1;
                if (status)
                        printf("Ошибка ввода. Попробуйте ещё раз:\n");
        }
	return 1;
}

int cleanbuffer()
{
	int quantity_sim = 0;
	while (getchar() != '\n')
		quantity_sim++;
	return quantity_sim;
}

int continue_solve()
{
	int ch = getchar();
        if (ch == 'y')
                return 1;
        if (ch == 'n')
                return 0;
	return 0;
}
