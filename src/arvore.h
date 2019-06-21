#include <stdio.h>
#iclude "tabuleiro.h"

#define TAM_TABULEIRO 50

struct Arvore
{
	struct Arvore* subdireita;
	struct Arvore* subesquerda;
	struct Arvore* novo;
} 

void inserirarvore(Arvore** raiz, Arvore** novo) // Função que insere dados na árvore recursivamente
{

  
	if(*raiz == NULL)
	{
		*raiz = (struct Arvore*)malloc(sizeof(Arvore)); 
    
		if(!raiz)
		{
			printf("Erro ao alocar =(\n");
			exit(1);
		}
    
    *raiz = *novo
    (*raiz)->subesquerda = NULL; 
    (*raiz)->subdireita = NULL; 
 
	} 
	else
	{
		if((*novo)->hash < (*raiz)->hash) {
			inserirarvore(&(*raiz)->subesqueda, novo);
		}
		else { 
			inserirarvore(&(*raiz)->subdireita, novo);
		}
	}
}
struct arvore* buscararvore(struct arvore **raiz, int hash)
{
	if (*raiz == NULL)
	{
		return NULL;
	}
	else
	{
		if ( hash < (*raiz)->hash){ 
			return buscararvore(&(*raiz)->subesquerda, hash);
		}
		else if (hash > (*raiz)->hash) {
			return buscararvore(&(*raiz)->subdireita, hash);
		}
		else {
		return *raiz;
		}
	}
}


int hash(char tabuleiro[LINHA][COLUNA])
{
	int i=0;
	int j=0;
	int k=0;

	char s[TAM_TABULEIRO];

	for (i=0; i<LINHA; i++)
	{
		for (j=0; j<COLUNA; j++)
		{
			s[k] = tabuleiro[i][j];
			k++;	
		}

	}
	s[k] = '\0';
	return fnv_hash(s);
}

unsigned int fnv_hash (const char *s)
{
	register unsigned int i;
 
	for (i = 0; *s; s++)
    {
		i *= 16777619;
		i ^= *s;
    }

	 return i;
  
 //Para mais detalhes sobre fnv_hash: http://www.isthe.com/chongo/tech/comp/fnv/index.html#FNV-param
 
}
