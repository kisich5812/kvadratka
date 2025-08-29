/*!
\file
*/
#include <math.h>
#include <float.h>
#include <stdio.h>
#include <string.h>
#include "flags.h"

int processing_flags(int val_args, char* args[])
{
	int do_prog = norm_version;
	for(int i = 1; i<val_args; i++)
	{
		if (strcmp(args[i], "-h") == 0 || strcmp(args[i], "--help") == 0)
		{
			print_help(args[0]);
			do_prog = stop_prog;
			return do_prog;
		}
		if (strcmp(args[i], "-p") == 0 || strcmp(args[i], "--pranc") == 0)
                {
                        do_prog = pranc_version;
                }
		else
		{
			printf("Неизвестный аргумент %s\n", args[i]);
			do_prog = stop_prog;
			return do_prog;
		}
	}
	return do_prog;
}

int print_help(char* prog_name)
{
	printf("Использование:\n");
	printf("%s [опции]\n", prog_name);
	printf("Опции:\n");
	printf("\t[без опций] решение квадратных уравнений\n");
	printf("\t-h, --help вывести данную справку\n");
	printf("\t-p, --pranc шуточная версия программы\n");
	return 1;
}
