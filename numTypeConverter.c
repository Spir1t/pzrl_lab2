#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funcs.h"


char *_strreverse(const char *str1)
{
	if(str1 == NULL)
	{
		return 0;
	}
	int len = strlen(str1);
	char *str2 = (char*)calloc(32, sizeof(char));
	for(int i = 0; i < len; ++i) //принцип работы очевиден, идем у одного массива с одной стороны, у другого с другой
	{
		str2[i] = str1[len - i - 1];
	}
	return(str2);
}


int bin2int(char* bin)
{
	int num = 0;
	int c = 1;
	int len = strlen(bin);
	char* newbin = _strreverse(bin);
	int sign = 1;
	for(int i = 0; i < len;	i++)
	{
		if(newbin[i] == '1')
		{
			num += c;
		}
		if(newbin[i] == '-')
		{
			sign = -1;
		}
		c = c * 2;
	}
	free(newbin);
	return(sign * num);
}


char* int2bin(int num)
{
	int r = num;
	char* bin = (char*)calloc(32, sizeof(char));
	int i = 0;
	if(r == 0)
	{
		bin[0] = '0';
		return(bin);
	}
	while(r != 0)
	{
		int s = r - r / 2 * 2;
		bin[i] = '0' + s;
		i++;
		r = r / 2;
	}
	char* bin2 = _strreverse(bin);
	for(int i = 0; i < strlen(bin); i++)
	{
		bin[i] = bin2[i];
	}
	free(bin2);
	return(bin);
}


int oct2int(char* oct)
{
	int num = 0;
	int c = 1;
	int len = strlen(oct);
	char* newoct = _strreverse(oct);
	int sign = 1;
	for(int i = 0; i < len - 1; i++)
	{
		if(newoct[i] == '-')
		{
			sign = -1;
		}
		else if(newoct[i] != '0')
		{
			num += (newoct[i] - '0') * c;
		}
		c = c * 8;
	}
	free(newoct);
	return(sign * num);
}


char* int2oct(int num)
{
	int r = num;
	char* oct = (char*)calloc(32, sizeof(char));
	int i = 0;
	if(r == 0)
	{
		oct[0] = '0';
		oct[1] = '0';
		return(oct);
	}
	while(r != 0)
	{
		int s = r - r / 8 * 8;
		oct[i] = '0' + s;
		i++;
		r = r / 8;
	}
	char* oct2 = _strreverse(oct);
	oct[0] = '0';
	for(int i = 1; i < strlen(oct) + 1; i++)
	{
		oct[i] = oct2[i - 1];
	}
	free(oct2);
	return(oct);
}


int hex2int(char* hex)
{
	int num = 0;
	int c = 1;
	int len = strlen(hex);
	char* newhex = _strreverse(hex);
	for(int i = 0; i < len - 2; i++)
	{
		if(newhex[i] >= '0' && newhex[i] <= '9')
		{
			num += (newhex[i] - '0') * c;
		}
		else
		{
			num += (newhex[i] - 'a' + 10) * c;
		}
		c = c * 16;
	}
	free(newhex);
	return num;
}

char* int2hex(int num)
{
	int r = num;
	char* hex = (char*)calloc(32, sizeof(char));
	int i = 0;
	if(r == 0)
	{
		hex[0] = '0';
		hex[1] = 'x';
		hex[2] = '0';
		return(hex);
	}
	while(r != 0)
	{
		int s = r - r / 16 * 16;
		if(s <= 9)
		{
			hex[i] = '0' + s;
		}
		else
		{
			hex[i] = 'a' + s - 10;
		}
		i++;
		r = r / 16;
	}
	char* hex2 = _strreverse(hex);
	hex[0] = '0';
	hex[1] = 'x';
	for(int i = 2; i < strlen(hex) + 2; i++)
	{
		hex[i] = hex2[i - 2];
	}
	free(hex2);
	return(hex);
}


bool checkBinOctHex(char* n)
{
	int len = strlen(n);
	if(getType(n) == 16)
	{
		for(int i = 2; i < len; i++)
		{
			if(((n[i] >= '0' && n[i] <= '9') || (n[i] >= 'a' && n[i] <= 'f') || (n[i] == '~' && i == 0)) == false)
			{
				return false;
			}
		}
	}
	
	else if(getType(n) == 8)
	{
		for(int i = 1; i < len; i++)
		{
			if(((n[i] >= '0' && n[i] <= '7') || (n[i] == '~' && i == 0)) == false)
			{
				return false;
			}
		}
	}
	
	else if(getType(n) == 2)
	{
		for(int i = 0; i < len; i++)
		{
			if(((n[i] == '0' || n[i] == '1') || (n[i] == '~' && i == 0)) == false)
			{
				return false;
			}
		}
	}
	return true;
}



/*
int main()
{
	printf("\n\tBIN2INT TEST\n\n");
	char* bin21 = "1011";
 	int a1 = bin2int(bin21);
	char* bin22 = "100001";
	int a2 = bin2int(bin22);
	char* bin23 = "1";
	int a3 = bin2int(bin23);
	char* bin24 = "0";
	int a4 = bin2int(bin24);
	printf("\nТест 1:\n%s\n%d\n", bin21, a1);
	printf("\nТест 2:\n%s\n%d\n", bin22, a2);
	printf("\nТест 3:\n%s\n%d\n", bin23, a3);
	printf("\nТест 4:\n%s\n%d\n", bin24, a4);


	printf("\n\tINT2BIN TEST\n\n");
	int b1 = 0;
	char* bin1 = int2bin(b1);
	int b2 = 1;
	char* bin2 = int2bin(b2);
	int b3 = 22;
	char* bin3 = int2bin(b3);
	int b4 = 77;
	char* bin4 = int2bin(b4);
	printf("\nТест 1:\n%d\n%s\n", b1, bin1);
	printf("\nТест 2:\n%d\n%s\n", b2, bin2);
	printf("\nТест 3:\n%d\n%s\n", b3, bin3);
	printf("\nТест 4:\n%d\n%s\n", b4, bin4);
	free(bin1);
	free(bin2);
	free(bin3);
	free(bin4);


	printf("\n\tOCT2INT TEST\n\n");
	char* oct1 = "01";
 	int c1 = oct2int(oct1);
	char* oct2 = "071";
	int c2 = oct2int(oct2);
	char* oct3 = "0127";
	int c3 = oct2int(oct3);
	char* oct4 = "00";
	int c4 = oct2int(oct4);
	printf("\nТест 1:\n%s\n%d\n", oct1, c1);
	printf("\nТест 2:\n%s\n%d\n", oct2, c2);
	printf("\nТест 3:\n%s\n%d\n", oct3, c3);
	printf("\nТест 4:\n%s\n%d\n", oct4, c4);



	printf("\n\tINT2OCT TEST\n\n");
	int d1 = 0;
	char* oct21 = int2oct(d1);
	int d2 = 1;
	char* oct22 = int2oct(d2);
	int d3 = 22;
	char* oct23 = int2oct(d3);
	int d4 = 77;
	char* oct24 = int2oct(d4);
	printf("\nТест 1:\n%d\n%s\n", d1, oct21);
	printf("\nТест 2:\n%d\n%s\n", d2, oct22);
	printf("\nТест 3:\n%d\n%s\n", d3, oct23);
	printf("\nТест 4:\n%d\n%s\n", d4, oct24);
	free(oct21);
	free(oct22);
	free(oct23);
	free(oct24);
	

	printf("\n\tHEX2INT TEST\n\n");
	char* hex1 = "0x1";
 	int e1 = hex2int(hex1);
	char* hex2 = "0x71";
	int e2 = hex2int(hex2);
	char* hex3 = "0x1a7";
	int e3 = hex2int(hex3);
	char* hex4 = "0x0";
	int e4 = hex2int(hex4);
	printf("\nТест 1:\n%s\n%d\n", hex1, e1);
	printf("\nТест 2:\n%s\n%d\n", hex2, e2);
	printf("\nТест 3:\n%s\n%d\n", hex3, e3);
	printf("\nТест 4:\n%s\n%d\n", hex4, e4);


	printf("\n\tINT2HEX TEST\n\n");
	int f1 = 0;
	char* hex21 = int2hex(f1);
	int f2 = 1;
	char* hex22 = int2hex(f2);
	int f3 = 22;
	char* hex23 = int2hex(f3);
	int f4 = 77;
	char* hex24 = int2hex(f4);
	printf("\nТест 1:\n%d\n%s\n", f1, hex21);
	printf("\nТест 2:\n%d\n%s\n", f2, hex22);
	printf("\nТест 3:\n%d\n%s\n", f3, hex23);
	printf("\nТест 4:\n%d\n%s\n", f4, hex24);
	free(hex21);
	free(hex22);
	free(hex23);
	free(hex24);


	return 0;
}
*/
