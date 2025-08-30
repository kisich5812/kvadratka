/*!
\file
Заголовочный файл с прототипом функции изменения цвета вывода
*/
#ifndef _COLOR_H_
#define _COLOR_H_

#include "typcon.h"

/*!
\brief Изменяет цвет текста в консоли
Изменяет цвет текта вводимых и выводимых символов
\param[in] color название желаемого цвета(см. enum colors)
*/
int set_color(int color);

#endif
