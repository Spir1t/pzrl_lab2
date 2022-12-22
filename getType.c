#include <stdio.h>
#include "funcs.h"

int getType(char* n)
{
	if(n[0] == '1' || (n[0] == '0' && n[1] == '\0'))
		return(2);

	if(n[0] == '0' && n[1] == 'x')
		return(16);
	
	if(n[0] == '0')
		return(8);

	else
		return(0);
}
