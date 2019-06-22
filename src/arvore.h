#include <stdio.h>
#iclude "tabuleiro.h"

#define TAM_TABULEIRO 50

struct Arvore
{
	struct Arvore* subdireita;
	struct Arvore* subesquerda;
	struct Arvore* novo;
} 

// Função que insere dados na árvore recursivamente
void inserirarvore(Arvore** raiz, Arvore** novo) 
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

// Função de busca na arvore

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

int criarnovapossibilidade (char tabuleiro[LINHA][COLUNA], Arvore **novono)
{
	int i;
	int j = 0;
	int k = 0;
	int existente = 0;
	int colisao = 0;
	struct Arvore* existe; 

	int hs = hash(tabuleiro);
	existe = buscararvore(&raiz, hs);
	
	// Função que verifica colisões
	
	if (existe != NULL)
	{
		for (j=0; j<LINHA; j++)
		{
			for (k=0; j<COLUNA; k++)
			{
				if (tabuleiro[j][k] != existe->tabuleiro[j][k])
				{
					colisao = 1;
					break
				}
			}
		}
		existente = colisao? 0 : 1;
	}
	
	// Função que adiciona novo possivel no
	
	if(!existente)
	{
		for i=0; i<8; i++)
		{
			if((*novono)->possibilidades[i] == NULL)
			{
				(*novono)->possibilidades[i] = (struct Arvore*)malloc(sizeof(Arvore));
				for (j=0; j<LINHA; j++)
				{
					for (k=0; j<COLUNA; k++)
					{
						(*novono)->possibilidades[i]->tabuleiro[j][k] = tabuleiro[j][k];
					}
				}
			(*novono)->possibilidades[i]->hash = hs;
			inserirarvore(*raiz, &((*novono)->possibilidades[i]));
			break;
			}
		}
	}
	return 1;
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
