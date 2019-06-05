#include <stdio.h>

#define LINHA 5
#define COLUNA 4
#define CORINGA 100


/*
 * Função para imprimir a configuração atual do tabuleiro. 
 */
void imprimeTabuleiro(char tabuleiro[LINHA][COLUNA])
{
	int i;
	int j;

	for(i = 0; i < LINHA; i++)
	{
		for(j = 0; j < COLUNA; j++)
		{
			printf("%c", tabuleiro[i][j]);
		}
		printf("\n");	
	}
}

/*
 * Função para retornar as posições livres do tabuleiro 
 */
void retornaCasaVazia(char tabuleiro[LINHA][COLUNA], int livre1[], int livre2[]) 
{	
	int i;
	int j;

	for(i = 0; i < LINHA; i++)
	{
		for(j = 0; j < COLUNA; j++)
		{
				if (tabuleiro[i][j] == '0') 
				{
					if (livre1[0] == CORINGA) 
					{
							livre1[0] = i;
							livre1[1] = j;
					} else 
					{
						livre2[0] = i;
						livre2[1] = j;
					}
				}	
		}			
	}
}
