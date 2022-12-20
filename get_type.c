#include <stdio.h>


int get_type(char* type)
{
	if(type[0] == '0' && type[1] == 'x')
		return 16;

	else if(type[0] == '0')
		return 8;

	else if(type[0] == '1')
		return 2;
	
	else
		return 0;
} 
