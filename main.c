#include "table.h"


int main(int argc, char* argv[])
{
	char table_inicial[LINHA][COLUNA] = {{'I', 'D', 'D', 'I'},
					     {'I', 'D', 'D', 'I'},
					     {'I', 'I', 'I', 'I'},
					     {'I', 'I', 'I', 'I'},
					     {'I', '0', '0', 'I'}};
	
	printTable(table_inicial);

	return 0;	
}
