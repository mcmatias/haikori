#include <stdio.h>

#define LINHA 5
#define COLUNA 4



void printTable(char table[LINHA][COLUNA])
{
	int i;
	int j;

	for(i = 0; i < LINHA; i++)
	{
		for(j = 0; j < COLUNA; j++)
		{
			printf("%c", table[i][j]);
		}
		printf("\n");	
	}
}
