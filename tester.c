#include "tester.h"

int solve_tester()
{
        int fail_tests = 0;

        struct coefficients test_coef = {.a = NAN, .b = NAN, .c = NAN};
        struct answers refans = {.x1 = NAN, .x2 = NAN, .n_roots = 0};

        FILE *tests_file;
        tests_file = fopen("tests.txt", "r");

        if(tests_file == NULL)
        {
                printf("Неудалось открыть файл\n");
                return 1;
        }

        double tester_params[5] = {0};
        int tester_param_n_roots;
        int num_rows = number_rows(tests_file);

        for (int i = 0; i < num_rows; i++)
        {
                for (int j = 0; j < 3; j++)
                        fscanf(tests_file, "%lg", &tester_params[j]);
                fscanf(tests_file, "%d", &tester_param_n_roots);
                for (int j = 3; j < 5; j++)
                        fscanf(tests_file, "%lg", &tester_params[j]);
                test_coef.a = tester_params[0], test_coef.b = tester_params[1], test_coef.c = tester_params[2];
                refans.x1 = tester_params[3], refans.x2 = tester_params[4], refans.n_roots = tester_param_n_roots;
                fail_tests += one_case(test_coef, refans);
        }

        return fail_tests;
}

int number_rows(FILE* tests_file)
{
        char ch = 0;
        int num_rows = 0;
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
