/*!
\file
Данный файл содержит в себе прототипы функций
используемых программой для работы шуточного режима
*/

#ifndef _PRANC_H_
#define _PRANC_H_

#include "typcon.h"
#include "solver.h"
#include "io_functions.h"

/*!
\brief Выводит шутки

Выводит шутки исходя из введёных коэффициентов

\param[in] coef структура типа coefficients с коэффициентами
*/
int pranc_coef(struct coefficients coef);

/*!
\brief Функция кота

Спрашивает будить ли кота, в зависимости от ответа программа останавливается или идёт дальше

\return 0 если введён 'y'(программа продолжается)\n
1 если введён 'n'(программа останавливается)
*/
int cat_sleep_stop_prog();

/*!
\brief Определяет простое ли уравнение

\param[in] a,b,c коэффициенты уравнения
\return 1 если лёгкое\n
0 если нет
*/
int easy(double a, double b, double c);

#endif
