/*!
\file
Заголовочный файл с функциями обработки флагов
*/

#ifndef _PRINT_HELP_H_
#define _PRINT_HELP_H_

#include "typcon.h"

/*!
\brief Вывод памятки

Выводит на экран информацию о использовании программы

\param[in] *prog_name строковый массив с именем программы
*/
int print_help(char* prog_name);

/*!
\brief Обработка флагов

Обрабатывает все флаги переданные программе

\param[in] val_args количество переданных флагов(включая название программы)
\param[in] *args[] строковый массив с флагами
\return norm_version - возвращаемое значение по умолчанию, программа выполняется стандартно
stop_prog - если нужно остановить выполнение программы
pranc_version - шуточная версия программы
*/
int processing_flags(int val_args, char* args[]);

#endif
