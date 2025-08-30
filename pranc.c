/*!
\file
*/
#include <math.h>
#include <float.h>
#include <stdio.h>
#include "pranc.h"

int pranc_coef(struct coefficients coef)
{
	char otgovorki[2][100] = {"Легкотня, сам решай!\n", "Лёгкие примеры не решаю\n"};
	char solve[2][100] = {"Так уж и быть решу\n", "Решу только потому что Полторашка попросила:\n"};
	set_color(cyan);
	if (easy(coef.a, coef.b, coef.c))
	{	
		printf("%s", otgovorki[rand()%2]);
		set_color(reset);
		return 0;
	}
	else
	{
		printf("%s", solve[rand()%2]);
		set_color(reset);
		return 1;
	}
}

int easy(double a, double b, double c)
{
	if (fabs(a) <= 5 && fabs(b) <= 5 && fabs(c) <= 5)
		if (compare_doubles(round(a), a) == equal && compare_doubles(round(b), b) == equal && compare_doubles(round(c), c) == equal)
			return 1;
	return 0;
}

int cat_sleep_stop_prog()
{
	set_color(orange);
	printf("	\
		,		\n	\
               / )		\n	\
              ( (		\n	\
               ) )		\n	\
              / /		\n	\
             (_(		\n	\
        _,-\"\"   \"\"-._	\n	\
      /_  /\\     /\\  _\\	\n	\
     (/ \\(/\\\\-~-//\\)/ \\)	\n	\
     {   \"         \"   }	\n	\
      \\   __     __		\n	\
     ,--.>_ .:Y:. _<,--.	\n	\
     `'''  '--^--'  `'''\n");
	printf("Шшшшш! Котик спит!\n");
	printf("Хотите ли вы будить котика? [y/n] ");
	set_color(reset);
	if(continue_solve() == yes)
		return 0;
	return 1;
}
