#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main()
{
	printf("\tБИТОВЫЙ КАЛЬКУЛЯТОР\n\tДля выхода из калькулятора введите @\n");
	printf("\n\tВведите числа и операции\n");


	char n1[100];
	char n2[100];
	char oper[100];
	scanf("%s %s %s", &n1, &oper, &n2);


	while(*(n1) != "@")
	{
		//if(n1 == '~')	
		if(get_type(n1) == 0 || get_type(n2) == 0)
		{
			printf("\tНекорректный ввод\n");
		}

		else if(get_type(n1) != get_type(n2))
		{
			printf("\tОшибка: системы счисления не совпадают\n");
		}

		else if(get_type(n1) == 2)
		{
			if(oper == "+")
			{	
				int m1 = bin2int(n1);
				int m2 = bin2int(n2);
				char* str = int2bin(m1 + m2);
				printf("%s (%d)", str, m1 + m2);
				free(str);
			}
			if(oper == "-")
			{
				int m1 = bin2int(n1);
				int m2 = bin2int(n2);
				char* str = int2bin(m1 - m2);
				printf("%s (%d)", str, m1 - m2);
				free(str);
			}
			if(oper == "*")
			{
				int m1 = bin2int(n1);
				int m2 = bin2int(n2);
				char* str = int2bin(m1 * m2);
				printf("%s (%d)", str, m1 * m2);
				free(str);
			}
			if(oper == "/")
			{
				int m1 = bin2int(n1);
				int m2 = bin2int(n2);
				char* str = int2bin(m1 / m2);
				printf("%s (%d)", str, m1 / m2);
				free(str);
			}

		}
	
	}	

	return 0;
}
