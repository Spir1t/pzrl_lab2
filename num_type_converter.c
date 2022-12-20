#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *_strreverse(const char *str1)
{
	if(str1 == NULL)
	{
		return 0;
	}
	int len = strlen(str1);
	char *str2 = (char*)calloc(len, sizeof(char));
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
	for(int i = 0; i < len;	i++)
	{
		if(newbin[i] == '1')
		{
			num += c;
		}
		c = c * 2;
	}
	free(newbin);
	return num;
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
	for(int i = 0; i < len - 1; i++)
	{
		if(newoct[i] != '0')
		{
			num += (newoct[i] - '0') * c;
		}
		c = c * 8;
	}
	free(newoct);
	return num;
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


int hex2int(char* hex);
{
	int num = 0;
	int c = 1;
	int len = strlen(oct);
	char* newoct = _strreverse(oct);
	for(int i = 0; i < len - 2; i++)
	{
		if(newoct[i] != '0')
		{
			num += (newoct[i] - '0') * c;
		}
		c = c * 16;
	}
	free(newoct);
	return num;
}

char* int2hex(int num);


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
	
	return 0;
}