/*!
\file
*/
#include <assert.h>
#include <math.h>
#include <float.h>
#include "solver.h"

int solve(struct coefficients coef, struct answers* roots)
{

        assert(!isnan(coef.a));
        assert(!isnan(coef.b));
        assert(!isnan(coef.c));
        assert(roots);

        if (compare_doubles(coef.a, 0) == equal)                 // разбор случаев
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
                        return inf_roots;               // 0*x^2 + 0*x + 0 = 0 бесконечное множество решений, возвращаем -1
                }
                else
                {
                        roots->n_roots = no_roots;
                        return no_roots;                // 0*x^2 + 0*x + c = 0 нет корней, возвращаем 0
                }
        }
        else
        {
                if (compare_doubles(coef.c, 0) == equal)// 0*x^2 + b*x + 0 = 0 единственный корень, возвращаем 1
                        roots->x1 = 0;
                else
                        roots->x1 = -coef.c/coef.b;     // 0*x^2 + b*x + с = 0 единственный корень, возвращаем 1
                roots->n_roots = one_root;
                return one_root;
        }

        return no_calculate_err; // код ошибки
}

int square_case(struct coefficients coef, struct answers* roots)
{
        double d = coef.b * coef.b - 4 * coef.a * coef.c;       // считаем дискриминант
        double sqrt_d = sqrt(d);                                // и корень из него

        if (compare_doubles(d, 0) == more)                      // a*x^2 + b*x + c = 0
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

int compare_doubles(double ch1, double ch2)          // 0 - ch1 == ch2 1 - ch1 > ch2 -1 - ch1 < ch2
{
        if(isnan(ch1) && isnan(ch2))
                return equal;
        if (fabs(ch1 - ch2) < PREDEL)   // ==
                return equal;
        else if (ch1 - ch2 > 0)  // ch1 > ch2
                return more;
        else if (ch1 - ch2 < 0)  // ch1 < ch2
                return less;
        return no_compare_err;    // код ошибки
}
