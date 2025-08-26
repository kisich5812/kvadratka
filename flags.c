#include "flags.h"
#include <stdio.h>
#include <string.h>

int processing_flags(int val_args, char* args[])
{
	if (val_args > 1)
        {
                if (val_args == 2 && strcmp(args[1], "--help") == 0)
                {
                        print_help(args[0]);
                        return 0;
                }
                else
		{
			printf("Неизвестный аргумент %s\n", args[1]);
			return 0;
		}
        }
	return 1;
}

int print_help(char* prog_name)
{
	printf("Использование:\n");
	printf("%s [опции]\n", prog_name);
	printf("Опции:\n");
	printf("\t[без опций] решение квадратных уравнений\n");
	printf("\t--help вывести данную справку\n");
	return 1;
}
