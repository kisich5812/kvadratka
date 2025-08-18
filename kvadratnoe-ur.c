#include <stdio.h>
#include <math.h>
#include <float.h>

const double predel = pow(10, -DBL_DIG);	// значение для проверки равно ли число с плавающей точкой нулю

bool ravnnul(double a);				// функция для проверки равно ли число с плавающей точкой нулю, возвращает 1 если равно 0, 0 в ином случае
int main(void)
{
	double a, b, c; 			// коэффициенты
	double d; 				// дискриминант
	double x1, x2; 				// ответы
	int toch; 				// точность(количество знаков после запятой)
	
	printf("Эта программа преднахначена для решения квадратных уравнений\n");
	printf("представленных в виде a*x^2+b*x+c=0. Введите коэффициенты через пробел:\n");
	scanf("%lg %lg %lg", &a, &b, &c);	// считываем коэффициенты
	
	if (ravnnul(a) && ravnnul(b) && ravnnul(c))
	{
		printf("0 действительно равен нулю\n");
	}
	else if (ravnnul(a) && ravnnul(b))
	{
                printf("Выражение %g = 0 не имеет смысла\n", c);
	}
	else
	{
		printf("Введите желаемую точность ответа(количество знаков после запятой):\n");
		scanf("%d", &toch);
		if (ravnnul(a))
		{
			if(ravnnul(c))
				x1 = 0;
			else
				x1 = -c/b;
			printf("Уравнение является линейным и имеет одно решение\n");
			printf("x = %.*g\n", toch, x1);
		}
		else
		{
			d = b*b - 4*a*c;
			if(ravnnul(d) == 0 && d > 0)
			{
				x1 = (-b+sqrt(d))/(2*a);
				x2 = (-b-sqrt(d))/(2*a);
				printf("Уравнение имеет следующие корни:\n");
				printf("x1 = %.*g\nx2 = %.*g\n", toch, x1, toch, x2);
			}
			if(ravnnul(d))
			{
				if(ravnnul(b))
					x1 = 0;
				else
					x1 = -b/(2 * a);
				printf("Корни уравнения совпадают и равны:\n");
				//printf("x1 = x2 = %.*lf\n", toch, x1);
				printf("x1 = x2 = %.*g\n", toch, x1);
			}
			if(ravnnul(d) == 0 && d < 0)
			{
				printf("Уравнение не имеет действительных корней\n");
			}
		}
	}
	return 0;
}

bool ravnnul(double a)
{
	if (fabs(a) < predel)
		return 1;
	else
		return 0;
}
