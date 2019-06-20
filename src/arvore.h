#include <stdio.h>

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
	if((*novo) < (*raiz)->novo) 
		inserirarvore(&(*raiz)->subesqueda, novo);
	else  
		inserirarvore(&(*raiz)->subdireita, novo);
     
}

