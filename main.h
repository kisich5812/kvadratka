/*!
\file
Данный файл содержит в себе прототипы функций
используемых программой для ввода-вывода
*/

#ifndef _MAIN_H_
#define _MAIN_H_

#include "io_functions.h"
#include "tester.h"
#include "solver.h"
#include "flags.h"
#include "pranc.h"
#include "typcon.h"

/*!
\brief Главная функция программы

Запускает проверку флагов
По результам проверки выбирает режим работы(нормальный, шуточный, остановка)

\param[in] argc количество флагов
\param[in] *argv[] массив с флагами
*/
int main(int argc, char* argv[]);

#endif /* _MAIN_H_ */
