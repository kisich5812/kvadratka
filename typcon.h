/*!
\file
Данный файл содержит определения типов и констант
*/
#ifndef _TYPCON_H_
#define _TYPCON_H_
/// Структура для коэффициентов уравнения
struct coefficients {
        double a;	///< Коэффициент при x^2
        double b;	///< Коэффициент при x
        double c;	///< Свободный член
};

/// Структура ответов
struct answers {
        double x1;	///< Первый ответ
        double x2;	///< Второй ответ
        int n_roots;	///< Количество корней
};

/// Структура совмещающая коэффициенты и ответы
struct equation_parametrs {
        struct coefficients coef;	///< Коэффициенты
        struct answers ans;		///< Ответы
};

const double PREDEL = pow(10, -DBL_DIG);	///< Точность для сравнения чисел типа double

const int standart_return = 1;	///< стандартное возвращаемое значение функции

/// Количество корней
enum number_of_roots {
        inf_roots = -1,		///< бесконечное количество корней
        no_roots,		///< нет корней
        one_root,		///< один корень
        two_roots,		///< два корня
        no_calculate_err	///< ошибка
};

/// Возможные варианты результата сравнения
enum compare {
        less = -1,		///< меньше
        equal,			///< равно
        more,			///< больше
        no_compare_err = 3	///< ошибка
};

/// Перечисление для ответов на вопрос да\нет\ошибка
enum continue_sol {
        no=0,		///< нет
        yes=1,		///< да
	enter_err	///< ошибка ввода
};

/// Набор возможных вариантов продолжения работы программы
enum continue_program {
	stop_prog,	///< Программа останавливается
	norm_version,	///< Выполняется стандартный вариант программы
	pranc_version	///< Выполняется шуточная версия программы
};

#endif
