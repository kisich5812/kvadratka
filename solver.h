/*!
\file
Данный файл содержит в себе прототипы функций
используемых программой для решения уравнения
*/
#ifndef _SOLVER_H_
#define _SOLVER_H_

#include "typcon.h"

/*!
\brief Решает уравнение

В зависимости от коэффициентов вызывает linear_case() или square_case()

\param[in] coef структура типа coefficients содержащая коэффициенты
\param[in] *roots указатель на структуру типа answers куда будут записаны ответы
*/
int solve(struct coefficients coef, struct answers* roots);

/*!
\brief Решает уравнение

Решает линейный случай уравнения

\param[in] coef структура типа coefficients содержащая коэффициенты
\param[in] *roots указатель на структуру типа answers куда будут записаны ответы
*/
int linear_case(struct coefficients coef, struct answers* roots);

/*!
\brief Решает уравнение

Решает случай квадратного уравнения

\param[in] coef структура типа coefficients содержащая коэффициенты
\param[in] *roots указатель на структуру типа answers куда будут записаны ответы
*/
int square_case(struct coefficients coef, struct answers* roots);

/*!
\brief Сравнивает числа

Сравнивает числа типа double

\param[in] ch1 число типа double
\param[in] ch2 число типа double

\return equal в случае равенства чисел\n
more в случае ch1>ch2\n
less в случае ch1<ch2
*/
int compare_doubles(double ch1, double ch2);

#endif /* _SOLVER_h_ */
