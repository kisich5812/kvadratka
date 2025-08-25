#include "main.h"

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
