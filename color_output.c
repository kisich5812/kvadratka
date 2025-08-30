/*!
\file
*/
#include <math.h>
#include <float.h>
#include <stdio.h>
#include "color_output.h"

int set_color(int color)
{
        switch (color)
        {
                case black:
                        printf("\033[1;30m");
                        break;
                case red:
                        printf("\033[1;31m");
                        break;
                case green:
                        printf("\033[1;32m");
                        break;
                case yellow:
                        printf("\033[1;33m");
                        break;
                case blue:
                        printf("\033[1;34m");
                        break;
                case magenta:
                        printf("\033[1;35m");
                        break;
                case cyan:
                        printf("\033[1;36m");
                        break;
                case white:
                        printf("\033[1;37m");
                        break;
		case orange:
			printf("\033[1;38;5;214m");
			break;
		case reset:
                        printf("\033[1;0m");
                        break;
                default:
                        printf("\033[1;0m");
        }
        return 1;
}

