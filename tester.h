/*!
\file
Данный файл содержит в себе прототипы функций
используемых программой для самотестирования
*/
#ifndef _TESTER_H_
#define _TESTER_H_

#include "typcon.h"
#include "io_functions.h"
#include "solver.h"

/*!
\brief Вызывает тесты

Считывает тестовые коэффициенты и ответы из файла

\return количество проваленых тестов
*/
int solve_tester();

/*!
\brief Выполняет один тест

Выполняет один тест, сверяет полученные результаты с ожидаемыми

\return 1 если тест провален\n
0 если всё прошло успешно
*/
int one_case(struct coefficients test_coef, struct answers refans);

/*!
\brief Подсчитывает количество строк в файле

\param[in] tests_file указатель на файл
\return количество строк
*/
unsigned long number_rows(FILE* tests_file);

/*!
\brief Проверяет равны ли полученные корни ожидаемым

Проверяет равны ли корни
x1 = x1ref	или	x1 = x2ref
x2 = x2ref		x2 = x1ref

\param[in] x1,x2 полученные корни
\param[in] x1ref,x2ref ожидаемые корни
\return количество строк
*/
int check_roots(double x1, double x2, double x1ref, double x2ref);

#endif
