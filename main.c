#include "table.h"



int main(int argc, char* argv[])
{
	char table_inicial[LINHA][COLUNA] = {{'I', 'D', 'D', 'I'},
					     {'I', 'D', 'D', 'I'},
					     {'I', 'I', 'I', 'I'},
					     {'I', 'I', 'I', 'I'},
					     {'I', '0', '0', 'I'}};
	
	int livre1[] = {CORINGA, CORINGA};
	int livre2[] = {CORINGA, CORINGA};
	
	printTable(table_inicial);
	
	retornaCasaVazia(table_inicial, livre1, livre2);
	
	printf("LIVRE1: %d%d\n", livre1[0], livre1[1]);
	printf("LIVRE2: %d%d\n", livre2[0], livre2[1]);

	return 0;	
}
