/*!
\file
Данный файл содержит в себе прототипы функций
используемых программой для ввода-вывода
*/

#ifndef _IO_FUNCTIONS_H_
#define _IO_FUNCTIONS_H_

#include "solver.h"
#include "typcon.h"
#include "color_output.h"

/*!
\brief Приглашение на ввод коэффициентов

Выводит приглашение на ввод

\param[in] enter_values указатель на структуру типа coefficients с коэффициентами
*/
int enter_coef(struct coefficients* enter_values);

/*!
\brief Ввод и проверка коэффициентов

Проверяет корректно ли произошёл ввод(не были ли введены символы не являющиеся цифрами)

\param[in] double_number указатель на число типа double
*/
int check_enter(double* double_number);

/*!
\brief Очистка входного буфера

Очищает входной буфер

\warning Если буфер пуст программа зависнет, ожидая ввода символа
*/
int clean_buffer();

/*!
\brief Вывод получившихся ответов

Выводит получившиеся ответы

\param[in] roots структура типа answers содержащая ответы
*/
int print_answer(struct answers roots);

/*!
\brief Продолжать ли выполнение программы

Считывает символ и в зависимости от ввода возвращает значения yes или no типа enum

\return yes если введён 'y'\n
no если введён 'n'
*/
int continue_solve();

/*!
\brief Вывод ошибок во время тестов

В случае ошибки при выполнении тестов выводит получившиеся ответы

\param[in] roots структура типа answers содержащая ответы
*/
int print_test_error(struct answers roots);

/*!
\brief Выводит фразы кота

\param[in] pranc переменная типа bool для вывода доп фраз
*/
int poltorashka_standard_2005(bool pranc);

#endif
