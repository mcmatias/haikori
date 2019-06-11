#include <stdio.h>
#include <stdbool.h>

#define LINHA 5
#define COLUNA 4
#define CONFIGURACOES 100
#define CORINGA 100
#define CASA_LIVRE 2
#define CASA_ADJACENTE_LINHA 4
#define CASA_ADJACENTE_COLUNA 2


	struct casa_ao_lado {
		int linha;
		int coluna;
		char valor;
	};

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

bool ladoEsquerdo(char tabuleiro[LINHA][COLUNA], int i, int j, struct casa_ao_lado x)
{
	printf("entrou ladoEsquerdo\n");
	if ((0 <= j - 1) && (j - 1 < COLUNA) && (tabuleiro[i][j - 1] != '0'))
	{
		x.linha = i;
		printf("x.linha: %d\n", x.linha);
		x.coluna = j;
		printf("x.coluna: %d\n", x.coluna);
		x.valor = tabuleiro[i][j - 1];
		printf("x.valor: %c\n", x.valor);
		return true;
	} else if (tabuleiro[i][j - 1] == '0') {
		x.linha = i;
		x.coluna = j;
		x.valor = '0';
	}

	return false;
}

bool ladoDireito(char tabuleiro[LINHA][COLUNA], int i, int j, struct casa_ao_lado x)
{
	if ((0 <= j + 1) && (j + 1 < COLUNA) && (tabuleiro[i][j + 1] != '0'))
	{
		x.linha = i;
		printf("x.linha: %d\n", x.linha);
		x.coluna = j;
		printf("x.coluna: %d\n", x.coluna);
		x.valor = tabuleiro[i][j + 1];
		printf("x.valor: %c\n", x.valor);
		return true;
	} else if (tabuleiro[i][j + 1] == '0') {
		x.linha = i;
		x.coluna = j;
		x.valor = '0';
	}

	return false;
}

bool ladoAcima(char tabuleiro[LINHA][COLUNA], int i, int j, struct casa_ao_lado x)
{
	if ((0 <= i - 1) && (i - 1 < LINHA) && (tabuleiro[i - 1][j] != '0'))
	{
		x.linha = i;
		printf("x.linha: %d\n", x.linha);
		x.coluna = j;
		printf("x.coluna: %d\n", x.coluna);
		x.valor = tabuleiro[i-1][j];
		printf("x.valor: %c\n", x.valor);
		return true;
	} else if (tabuleiro[i - 1][j] == '0') {
		x.linha = i;
		x.coluna = j;
		x.valor = '0';
	}

	return false;
}

bool ladoAbaixo(char tabuleiro[LINHA][COLUNA], int i, int j, struct casa_ao_lado x)
{
	if ((0 <= i + 1) && (i + 1 < LINHA) && (tabuleiro[i + 1][j] != '0'))
	{
		x.linha = i;
		printf("x.linha: %d\n", x.linha);
		x.coluna = j;
		printf("x.coluna: %d\n", x.coluna);
		x.valor = tabuleiro[i+1][j];
		printf("x.valor: %c\n", x.valor);
		return true;
	} else if (tabuleiro[i + 1][j] == '0') {
		x.linha = i;
		x.coluna = j;
		x.valor = '0';
	}

	return false;
}

void casasAdjacentes(char tabuleiro[][COLUNA], int casas_livres[],
					 struct casa_ao_lado adjacentes[], int sizeAdjacente)
{
	int i = casas_livres[0];
	int j = casas_livres[1];

	printf("sizeAdjacente: %d\n", sizeAdjacente);

	/*
	struct casa_ao_lado adjacentes[]
	0 - dir livre1
	1 - esq livre1
	2 - cima livre1
	3 - baixo livre1
	4 - dir livre2
	5 - esq livre2
	6 - cima livre2
	7 - baixo livre2
	uma casa do livre1 vai apontar p posicao do livre2
	e uma casa do livre2 vai apontar a posicao do livre1
	se achar um 'D' tem que ver se a outra livre achou
	um 'D' na mesma posicao
	Ex. se adjacentes[0] for 'D', p jogada ser válida,
	adjacentes[4] tem que ser 'D'.
	 */
	
	/*LIVRE1*/
	ladoDireito(tabuleiro, i, j, adjacentes[0]);
	ladoEsquerdo(tabuleiro, i, j, adjacentes[1]);
	ladoAcima(tabuleiro, i, j, adjacentes[2]);
	ladoAbaixo(tabuleiro, i, j, adjacentes[3]);

	/*LIVRE2*/
	ladoDireito(tabuleiro, i, j, adjacentes[4]);
	ladoEsquerdo(tabuleiro, i, j, adjacentes[5]);
	ladoAcima(tabuleiro, i, j, adjacentes[6]);
	ladoAbaixo(tabuleiro, i, j, adjacentes[7]);

	
	


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
