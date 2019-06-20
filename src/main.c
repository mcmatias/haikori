#include "tabuleiro.h"
#include "arvore.h"
 
/*
    Função que executa o jogo Hairoki.
 */
int main(int argc, char *argv[])
{
	char tabuleiro_inicial[LINHA][COLUNA] = {
		{'I', 'D', 'D', 'I'},
		{'I', 'D', 'D', 'I'},
		{'I', 'I', 'I', 'I'},
		{'I', 'I', 'I', 'I'},
		{'I', '0', '0', 'I'}};

	/*
		Matrix que guarda os possíveis movimentos a cada jogada. 
	*/
	char possiveis_movimentos[LINHA][COLUNA][CONFIGURACOES] = {0};
	int contador_jogadas = 0;
	int livre1[2] = {CORINGA, CORINGA};
	int livre2[2] = {CORINGA, CORINGA};
	int casas_adjacentes[CASA_ADJACENTE_LINHA][CASA_ADJACENTE_COLUNA];
	int i;
	int j;
	int tamanho_casas_adjancentes = 0;

	imprimeTabuleiro(tabuleiro_inicial);
	retornaCasaVazia(tabuleiro_inicial, livre1, livre2);
	casasAdjacentes(tabuleiro_inicial, livre2, casas_adjacentes, &tamanho_casas_adjancentes);

	for (i = 0; i < tamanho_casas_adjancentes; i++)
	{
		for (j = 0; j < CASA_ADJACENTE_COLUNA; j++)
		{
			printf("[%d]", casas_adjacentes[i][j]);
		}
		printf("\n");
	}
	return 0;
}
