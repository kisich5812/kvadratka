#include <stdio.h>
#include <math.h>
#include <float.h>

int solve(double a, double b, double c, double* x1, double* x2);	// функция решает уравнение и считает количество корней, возвращает количество корней, -1 если корней бесконечность, 3 если произошла ошибка
int printanswer(double x1, double x2, int nRoot);			// вывод ответов
int compare_double(double ch1, double ch2);				// проверка равны ли числа; возвращает 1 если равны, 0 если не равны
int input_check(double a, double b, double c);				// проверка ввода коэффициентов; возвращает 1 если успешно, 0 если произошла ошибка
 
int main(void)
{
	double a = NAN,		// коэффициенты для уравнения
	       b = NAN,
	       c = NAN;
	double x1 = NAN,	// ответы
	       x2 = NAN;
	
	printf("Эта программа преднахначена для решения квадратных уравнений\n");
        printf("представленных в виде a*x^2+b*x+c=0. Введите коэффициенты через пробел:\n");
        
	scanf("%lg %lg %lg", &a, &b, &c);       // считываем коэффициенты
	if (input_check(a, b, c) == 0)
	{
		printf("Ошибка ввода\n");
		return 0;
	}

	int nRoots = solve(a, b, c, &x1, &x2);
	printanswer(x1, x2, nRoots);
	return 0;
}

int solve(double a, double b, double c, double* x1, double* x2)
{
	if (compare_double(a, 0) == 1)			// разбор случаев
	{
		if (compare_double(b, 0) == 1)
		{
			if (compare_double(c, 0) == 1)
				return -1;		// 0*x^2 + 0*x + 0 = 0 бесконечное множество решений, возвращаем -1
			else
				return 0;		// 0*x^2 + 0*x + c = 0 нет корней, возвращаем 0
		}
		else
		{
			if (compare_double(c, 0) == 1)	// 0*x^2 + b*x + 0 = 0 единственный корень, возвращаем 1
				*x1 = 0;
			else
				*x1 = -c/b;		// 0*x^2 + b*x + с = 0 единственный корень, возвращаем 1
			return 1;
		}
	}
	else
	{
		if (compare_double(b, 0) == 1 && compare_double(c, 0) == 1)
		{
			*x1 = 0;			// a*x^2 + 0*x + 0 = 0 единственный корень, возвращаем 1
			return 1;
		}
		else
		{
			double d = b*b - 4*a*c;		// считаем дискриминант
			double sqrt_d = sqrt(d);	// и корень из него
                        if (compare_double(d, 0) == 0 && d > 0)	// a*x^2 + b*x + c = 0
                        {
                                *x1 = (-b + sqrt_d) / (2*a);
                                *x2 = (-b - sqrt_d) / (2*a);
				if (compare_double(*x1, *x2) == 1)
					return 1;
				else
					return 2;
                        }
                        if (compare_double(d, 0) == 1)
                        {
                                if(compare_double(b, 0) == 1)
					*x1 = 0;
                                else
                                        *x1 = -b/(2 * a);
				return 1;
                        }
                        if(compare_double(d, 0) == 0 && d < 0)
                                return 0;
		}
	}
	return 3;	// возвращаем тройку как сигнал об ошибке
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

int compare_double(double ch1, double ch2)
{
	const double predel = pow(10, -DBL_DIG);
	if (isnan(ch1) || isnan(ch2))
		return 0;
	if (fabs(ch1 - ch2) < predel)
		return 1;
	else
		return 0;
}

int input_check(double a, double b, double c)
{
	if (isnan(a) != 0 || isnan(b) != 0 || isnan(c) != 0)
		return 0;
	else
		return 1;
}
