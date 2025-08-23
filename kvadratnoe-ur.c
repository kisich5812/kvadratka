#include <stdio.h>
#include <math.h>
#include <float.h>
#include <assert.h>

int enter_coef(struct coefficients* enter_values);
int check_enter(double* double_number);
int clean_buffer();
int solve(struct coefficients coef, struct answers* roots);
int linear_case(struct coefficients coef, struct answers* roots);
int square_case(struct coefficients coef, struct answers* roots);
int compare_doubles(double ch1, double ch2);
int print_answer(struct answers roots, int nRoots);
int continue_solve();

struct coefficients {
	double a;
	double b;
	double c;
};

struct answers {
	double x1;
	double x2;
};

const double PREDEL = pow(10, -DBL_DIG);

int main(void)
{
	struct coefficients coef = {NAN, NAN, NAN};
	struct answers roots = {NAN, NAN};
	
	printf("Эта программа предназначена для решения квадратных уравнений\n");
        printf("представленных в виде a*x^2+b*x+c=0.\n");
	do
        {
                enter_coef(&coef);
                int nRoots = solve(coef, &roots);
                print_answer(roots, nRoots);
                printf("Хотите ли вы решаить ещё одно уравнение? [y/n]: ");
        } while (continue_solve());
	//printf("a = %lg, b = %lg, c = %lg\n", coef.a, coef.b, coef.c);
	return 0;
}

int solve(struct coefficients coef, struct answers* roots)
{

        assert(!isnan(coef.a));
        assert(!isnan(coef.b));
        assert(!isnan(coef.c));
        assert(&(roots -> x1));
        assert(&(roots -> x2));

        if (compare_doubles(coef.a, 0) == 0)                 // разбор случаев
                return linear_case(coef, roots);
        else
                return square_case(coef, roots);    // TODO: загнать коды возврата в enum
        return 3;       // возвращаем тройку как сигнал об ошибке
}

int linear_case(struct coefficients coef, struct answers* roots)
{
        if (compare_doubles(coef.b, 0) == 0)
        {
                if (compare_doubles(coef.c, 0) == 0)
                        return -1;              // 0*x^2 + 0*x + 0 = 0 бесконечное множество решений, возвращаем -1
                else
                        return 0;               // 0*x^2 + 0*x + c = 0 нет корней, возвращаем 0
        }
        else
        {
                if (compare_doubles(coef.c, 0) == 0) // 0*x^2 + b*x + 0 = 0 единственный корень, возвращаем 1
                        roots -> x1 = 0;
                else
                        roots -> x1 = -coef.c/coef.b;             // 0*x^2 + b*x + с = 0 единственный корень, возвращаем 1
                return 1;
        }
        return 3; // код ошибки
}

int square_case(struct coefficients coef, struct answers* roots)
{
        double d = coef.b * coef.b - 4 * coef.a * coef.c;         // считаем дискриминант
        double sqrt_d = sqrt(d);        // и корень из него
        if (compare_doubles(d, 0) == 1) // a*x^2 + b*x + c = 0
        {
                roots -> x1 = (-coef.b + sqrt_d) / (2*coef.a); // TODO: добавить случай c = 0
                roots -> x2 = (-coef.b - sqrt_d) / (2*coef.a);
                if (compare_doubles(roots -> x1, roots -> x2) == 0)
                        return 1;
                else
                        return 2;
        }
        if (compare_doubles(d, 0) == 0)
        {
                if(compare_doubles(coef.b, 0) == 0)
                        roots -> x1 = 0;
                else
                        roots -> x1 = -coef.b/(2 * coef.a);
                return 1;
        }
        if(compare_doubles(d, 0) == -1)
                return 0;
        return 3; // код ошибки
}

int compare_doubles(double ch1, double ch2)             // 0 - ch1 == ch2 1 - ch1 > ch2 -1 - ch1 < ch2
{
        assert(!isnan(ch1));
        assert(!isnan(ch2));

        if (fabs(ch1 - ch2) < PREDEL)   // ==
                return 0;
        else if (ch1 - ch2 > 0)         // ch1 > ch2
                return 1;
        else if (ch1 - ch2 < 0)         // ch1 < ch2
                return -1;
        return 3;                       // код ошибки
}

int enter_coef(struct coefficients* enter_values)
{
        assert(&(enter_values -> a));
        assert(&(enter_values -> b));
        assert(&(enter_values -> c));
        printf("Введите коэффициент a:\n");
        check_enter(&(enter_values -> a));
        printf("Введите коэффициент b:\n");
        check_enter(&(enter_values -> b));
        printf("Введите коэффициент c:\n");
        check_enter(&(enter_values -> c));
        return 1;
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
                if (no_input)
                        printf("Ошибка ввода. Попробуйте ещё раз:\n");
        }
        return 1;
}

int clean_buffer()
{
        int quantity_sim = 0;
        while (getchar() != '\n')
                quantity_sim++;
        return quantity_sim;
}

int print_answer(struct answers roots, int nRoots)
{
        if (nRoots == -1)
                printf("х - любое число\n");
        else if (nRoots == 0)
                printf("Уравнение не имеет корней\n");
        else if (nRoots == 1)
        {
                printf("Уравнение имеет один корень:\n");
                printf("x = %g\n", roots.x1);
        }
        else if (nRoots == 2)
        {
                printf("Уравнение имеет два корня:\n");
                printf("x1 = %g\nx2 = %g\n", roots.x1, roots.x2);
        }
        else
                printf("При выполнении произошла ошибка!\n");
        return 1;
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
