/*!
\file
*/
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include "io_functions.h"

int poltorashka_standard_2005(bool pranc)
{
	set_color(red);
	printf("Мяу!\n");
	char poltorashka_phrases[1][100] = {"\nВкусная у тебя курица...\nбыла\n\n"};
	if (pranc)
		printf("\a%s", poltorashka_phrases[0]);
	set_color(reset);
	return 1;
}

int enter_coef(struct coefficients* enter_values)
{
        assert(enter_values);
        
	set_color(yellow);
	printf("Введите коэффициент a:\n");
        check_enter(&(enter_values->a));
        
	set_color(yellow);
	printf("Введите коэффициент b:\n");
        check_enter(&(enter_values->b));
        
	set_color(yellow);
	printf("Введите коэффициент c:\n");
        check_enter(&(enter_values->c));
        
	set_color(reset);
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
		{
			set_color(red);
                        printf("Ошибка ввода. Попробуйте ещё раз:\n");
			set_color(yellow);
		}
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
        set_color(green);
	switch(roots.n_roots)
        {
                case inf_roots:
                        printf("x - любое число\n");
                        break;
                case no_roots:
                        printf("Уравнение не имеет корней\n");
                        break;
                case one_root:
                        printf("Уравнение имеет один корень:\nx = %g\n", roots.x1);
                        break;
                case two_roots:
                        printf("Уравнение имеет два корня:\nx1 = %g\nx2 = %g\n", roots.x1, roots.x2);
                        break;
                default:
                        set_color(red);
			printf("При выполнении произошла ошибка!\n");
                        set_color(green);
			break;
        }
	set_color(reset);
	return standart_return;
}

int continue_solve()
{
	int contin = enter_err;
	int ch = 0;
	int value_symbols = 0;
	set_color(yellow);

	do
        {
                while((ch = getchar()) && ch != '\n')
                {
                        value_symbols++;
                        if (ch == 'y')
                                contin = yes;
                        if (ch == 'n')
                                contin = no;
                }
                if (value_symbols > 1)
                        contin = enter_err;
                if (contin == enter_err)
                {
                        set_color(red);
			printf("Ошибка ввода. Введите \'y\' или \'n\': ");
                        value_symbols = 0;
			set_color(yellow);
                }
        } while(contin == enter_err);
	set_color(reset);
	return contin;
}

int print_test_error(struct answers roots)
{
        set_color(red);
	switch(roots.n_roots)
        {
                case inf_roots:
                        printf("бесконечность корней");
                        break;
                case no_roots:
                        printf("Уравнение не имеет корней\n");
                        break;
                case one_root:
                        printf("Уравнение имеет один корень:\nx = %g\n", roots.x1);
                        break;
                case two_roots:
                        printf("Уравнение имеет два корня:\nx1 = %g\nx2 = %g\n", roots.x1, roots.x2);
                        break;
                default:
                        printf("Уравнение имеет %d корней.\nx1 = %g\nx2 = %g\n", roots.n_roots, roots.x1, roots.x2);
                        break;
        }
	set_color(reset);
	return standart_return;
}
