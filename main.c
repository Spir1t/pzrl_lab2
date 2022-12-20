#include <stdio.h>
#include <stdlib.h>
#include <funcs.h>

int main()
{
	printf("\tБИТОВЫЙ КАЛЬКУЛЯТОР\n\tДля выхода из калькулятора введите @\n");
	printf("\n\tВведите числа и операции");


	char* n1;
	char* n2;
	char* oper;
	scanf("%s %s %s", n1, oper, n2);


	while(n1 != '@')
	{
		//if(n1 == '~')	
		if(get_type(n1) == 0 or get_type(n2) == 0)
		{
			printf("\tНекорректный ввод\n");
		}

		else if(get_type(n1) != get_type(n2))
		{
			printf("\tОшибка: системы счисления не совпадают\n");
		}

		else if(get_type(n1) == 2)
		{
			
		}
	
	}	

	return 0;
}
