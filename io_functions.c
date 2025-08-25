#include "io_functions.h"

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
