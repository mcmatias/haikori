#include <stdio.h>
#include <stdbool.h>
#include "arvore.h"

#define LINHA 5
#define COLUNA 4
#define CONFIGURACOES 100
#define CORINGA 100
#define CASA_LIVRE 2
#define CASA_ADJACENTE_LINHA 4
#define CASA_ADJACENTE_COLUNA 2

/*
 * Função para imprimir a configuração atual do tabuleiro. 
 */
void imprimeTabuleiro(char tabuleiro[LINHA][COLUNA])
{
	int i;
	int j;

	for (i = 0; i < LINHA; i++)
	{
		for (j = 0; j < COLUNA; j++)
		{
			printf("%c", tabuleiro[i][j]);
		}
		printf("\n");
	}
}

/*
 * Função para retornar as posições livres do tabuleiro 
 */
void retornaCasaVazia(char tabuleiro[LINHA][COLUNA], int livre1[CASA_LIVRE], int livre2[CASA_LIVRE])
{
	int i;
	int j;
	int contador = 0;

	for (i = 0; i < LINHA; i++)
	{
		for (j = 0; j < COLUNA; j++)
		{
			if (tabuleiro[i][j] == '0')
			{
				if (contador == 0)
				{
					livre1[0] = i;
					livre1[1] = j;
					contador++;
				}
				else
				{
					livre2[0] = i;
					livre2[1] = j;
				}
			}
		}
	}
}

bool ladoEsquerdo(char tabuleiro[LINHA][COLUNA], int i, int j)
{
	if ((0 <= j - 1) && (j - 1 < COLUNA) && (tabuleiro[i][j - 1] != '0'))
	{
		return true;
	}

	return false;
}

bool ladoDireito(char tabuleiro[LINHA][COLUNA], int i, int j)
{
	if ((0 <= j + 1) && (j + 1 < COLUNA) && (tabuleiro[i][j + 1] != '0'))
	{
		return true;
	}

	return false;
}

bool ladoAcima(char tabuleiro[LINHA][COLUNA], int i, int j)
{
	if ((0 <= i - 1) && (i - 1 < LINHA) && (tabuleiro[i - 1][j] != '0'))
	{
		return true;
	}

	return false;
}

bool ladoAbaixo(char tabuleiro[LINHA][COLUNA], int i, int j)
{
	if ((0 <= i + 1) && (i + 1 < LINHA) && (tabuleiro[i + 1][j] != '0'))
	{
		return true;
	}

	return false;
}

void casasAdjacentes(char tabuleiro[LINHA][COLUNA], int casas_livres[CASA_LIVRE],
					 int casas_adjacentes[CASA_ADJACENTE_LINHA][CASA_ADJACENTE_COLUNA],
					 int *tamanho_casas_adjacentes)
{
	int i = casas_livres[0];
	int j = casas_livres[1];
	int contador_i = 0;
	int contador_j = 0;
	int n_casas_adjacentes = 0;

	if (ladoEsquerdo(tabuleiro, i, j))
	{
		casas_adjacentes[contador_i][contador_j] = i;
		contador_j++;
		casas_adjacentes[contador_i][contador_j] = j - 1;
		contador_i++;
		contador_j = 0;
		n_casas_adjacentes++;
	}

	if (ladoDireito(tabuleiro, i, j))
	{
		casas_adjacentes[contador_i][contador_j] = i;
		contador_j++;
		casas_adjacentes[contador_i][contador_j] = j + 1;
		contador_i++;
		contador_j = 0;
		n_casas_adjacentes++;
	}

	if (ladoAcima(tabuleiro, i, j))
	{
		casas_adjacentes[contador_i][contador_j] = i - 1;
		contador_j++;
		casas_adjacentes[contador_i][contador_j] = j;
		contador_i++;
		contador_j = 0;
		n_casas_adjacentes++;
	}

	if (ladoAbaixo(tabuleiro, i, j))
	{
		casas_adjacentes[contador_i][contador_j] = i + 1;
		contador_j++;
		casas_adjacentes[contador_i][contador_j] = j;
		contador_i++;
		contador_j = 0;
		n_casas_adjacentes++;
	}

	*tamanho_casas_adjacentes = n_casas_adjacentes;
}

/*
	Função que a partir de uma configuração de tabuleiro, fornece todos os
	possíveis movimentos.
	A ideia do algoritmo, inicialmente, é localizar os espaços vazios do tabuleiro.
	Depois disso, nós devemos achar os espaços adjacentes aos espaços vazios.
	Daí, checar se as peças adjacentes podem, de fato, se mover para o vazio disponível.
	Quando encontrado todos os possíveis movimentos, adiciona-los a uma matriz responsável
	por guardar todos esses elementos.
*/

void possiveisMovimentos(char tabuleiro[LINHA][COLUNA],
						 char possiveisMovimentos[LINHA][COLUNA][CONFIGURACOES], int *contador_jogadas)
{

}
