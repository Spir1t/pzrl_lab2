#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

int main()
{
	printf("\tБИТОВЫЙ КАЛЬКУЛЯТОР\n\tДля выхода из калькулятора введите @ @ @\n");
	printf("\n\tВведите числа и операции\n");


	char* n1 = (char*)calloc(32, sizeof(char));
	char* n2 = (char*)calloc(32, sizeof(char));
	char* oper = (char*)calloc(32, sizeof(char));
	scanf("%s", n1);
	while(n1[0] != '@')
	{
		if(n1[0] == '~')
		{
			memmove(&n1[0], &n1[1], strlen(n1));
			if(getType(n1) == 2)
			{
				int m1 = bin2int(n1);
				char* str = int2bin(-1 * ~m1);
				printf("-%s (%d)\n\n", str, ~m1);
				free(str);
			}
			if(getType(n1) == 8)
			{
				int m1 = oct2int(n1);
				char* str = int2oct(-1 * ~m1);
				printf("-%s (%d)\n\n", str, ~m1);
				free(str);
			}
			if(getType(n1) == 16)
			{
				int m1 = hex2int(n1);
				char* str = int2hex(-1 * ~m1);
				printf("-%s (%d)\n\n", str, ~m1);
				free(str);
			}
			scanf("%s", n1);
			continue;
		}
		scanf("%s %s", oper, n2);
		if(getType(n1) != getType(n2))
		{
			printf("\tОшибка: системы счисления не совпадают\n");
		}

		else if(getType(n1) == 2)
		{
			if(oper[0] == '+')
			{	
				int m1 = bin2int(n1);
				int m2 = bin2int(n2);
				char* str = int2bin(m1 + m2);
				printf("%s (%d)\n\n", str, m1 + m2);
				free(str);
			}
			if(oper[0] == '-')
			{
				int m1 = bin2int(n1);
				int m2 = bin2int(n2);
				if(m1 >= m2)
				{
					char* str = int2bin(m1 - m2);
					printf("%s (%d)\n\n", str, m1 - m2);
					free(str);
				}
				else
				{
					char* str = int2bin(m2 - m1);
					printf("-%s (%d)\n\n", str, m2 - m1);
					free(str);
				}
			}
			if(oper[0] == '*')
			{
				int m1 = bin2int(n1);
				int m2 = bin2int(n2);
				char* str = int2bin(m1 * m2);
				printf("%s (%d)\n\n", str, m1 * m2);
				free(str);
			}
			if(oper[0] == '/')
			{
				int m1 = bin2int(n1);
				int m2 = bin2int(n2);
				char* str = int2bin(m1 / m2);
				printf("%s (%d)\n\n", str, m1 / m2);
				free(str);
			}
			if(oper[0] == '&')
			{
				int m1 = bin2int(n1);
				int m2 = bin2int(n2);
				char* str = int2bin(m1 & m2);
				printf("%s (%d)\n\n", str, m1 & m2);
				free(str);
			}
			if(oper[0] == '|')
			{
				int m1 = bin2int(n1);
				int m2 = bin2int(n2);
				char* str = int2bin(m1 | m2);
				printf("%s (%d)\n\n", str, m1 | m2);
				free(str);
			}
			if(oper[0] == '^')
			{
				int m1 = bin2int(n1);
				int m2 = bin2int(n2);
				char* str = int2bin(m1 ^ m2);
				printf("%s (%d)\n\n", str, m1 ^ m2);
				free(str);
			}
		}


		else if(getType(n1) == 8)
		{
			if(oper[0] == '+')
			{	
				int m1 = oct2int(n1);
				int m2 = oct2int(n2);
				char* str = int2oct(m1 + m2);
				printf("%s (%d)\n\n", str, m1 + m2);
				free(str);
			}
			if(oper[0] == '-')
			{
				int m1 = oct2int(n1);
				int m2 = oct2int(n2);
				if(m1 >= m2)
				{
					char* str = int2oct(m1 - m2);
					printf("%s (%d)\n\n", str, m1 - m2);
					free(str);
				}
				else
				{
					char* str = int2oct(m2 - m1);
					printf("-%s (%d)\n\n", str, m2 - m1);
					free(str);
				}
			}
			if(oper[0] == '*')
			{
				int m1 = oct2int(n1);
				int m2 = oct2int(n2);
				char* str = int2oct(m1 * m2);
				printf("%s (%d)\n\n", str, m1 * m2);
				free(str);
			}
			if(oper[0] == '/')
			{
				int m1 = oct2int(n1);
				int m2 = oct2int(n2);
				char* str = int2oct(m1 / m2);
				printf("%s (%d)\n\n", str, m1 / m2);
				free(str);
			}
			if(oper[0] == '&')
			{
				int m1 = oct2int(n1);
				int m2 = oct2int(n2);
				char* str = int2oct(m1 & m2);
				printf("%s (%d)\n\n", str, m1 & m2);
				free(str);
			}
			if(oper[0] == '|')
			{
				int m1 = oct2int(n1);
				int m2 = oct2int(n2);
				char* str = int2oct(m1 | m2);
				printf("%s (%d)\n\n", str, m1 | m2);
				free(str);
			}
			if(oper[0] == '^')
			{
				int m1 = oct2int(n1);
				int m2 = oct2int(n2);
				char* str = int2oct(m1 ^ m2);
				printf("%s (%d)\n\n", str, m1 ^ m2);
				free(str);
			}
		}

		else if(getType(n1) == 16)
		{
			if(oper[0] == '+')
			{	
				int m1 = hex2int(n1);
				int m2 = hex2int(n2);
				char* str = int2hex(m1 + m2);
				printf("%s (%d)\n\n", str, m1 + m2);
				free(str);
			}
			if(oper[0] == '-')
			{
				int m1 = hex2int(n1);
				int m2 = hex2int(n2);
				if(m1 >= m2)
				{
					char* str = int2hex(m1 - m2);
					printf("%s (%d)\n\n", str, m1 - m2);
					free(str);
				}
				else
				{
					char* str = int2hex(m2 - m1);
					printf("-%s (%d)\n\n", str, m2 - m1);
					free(str);
				}
			}
			if(oper[0] == '*')
			{
				int m1 = hex2int(n1);
				int m2 = hex2int(n2);
				char* str = int2hex(m1 * m2);
				printf("%s (%d)\n\n", str, m1 * m2);
				free(str);
			}
			if(oper[0] == '/')
			{
				int m1 = hex2int(n1);
				int m2 = hex2int(n2);
				char* str = int2hex(m1 / m2);
				printf("%s (%d)\n\n", str, m1 / m2);
				free(str);
			}
			if(oper[0] == '&')
			{
				int m1 = hex2int(n1);
				int m2 = hex2int(n2);
				char* str = int2hex(m1 & m2);
				printf("%s (%d)\n\n", str, m1 & m2);
				free(str);
			}
			if(oper[0] == '|')
			{
				int m1 = hex2int(n1);
				int m2 = hex2int(n2);
				char* str = int2hex(m1 | m2);
				printf("%s (%d)\n\n", str, m1 | m2);
				free(str);
			}
			if(oper[0] == '^')
			{
				int m1 = hex2int(n1);
				int m2 = hex2int(n2);
				char* str = int2hex(m1 ^ m2);
				printf("%s (%d)\n\n", str, m1 ^ m2);
				free(str);
			}
		}


		else
		{
			printf("Некорректный ввод\n");
		}

		scanf("%s", n1);
	}	

	free(n1);
	free(n2);
	free(oper);
	return 0;
}
