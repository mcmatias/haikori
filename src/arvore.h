/*
   Arquivo que fornece a estrutura de dados base para o tratamento do problema.
   Aqui é implementada um árvore que pode apresentar até no máximo 6 filhos.
   Funções públicas que foram desenvolidas para interagir com a interface da estrutura de dados:
	  1> search_item(item)
          2> insert_item(item)
*/
#include <stdio.h>
#include <stdbool.h>
#include "tabuleiro.h"


/* Definição dos protótipos das funções presentes neste arquivo */
Node *choose_node(Node *node);
bool insert_node(Node *root, Node *node_new);
Node *search_node(Node *root, char tabuleiro_configuracao[]);
Node *create_node(void);


/*
   Construção do tipo Abstrato de dados: um nó que pode ter até 6 nós filhos.
 */
typedef struct Node {
	struct Node *child_1 = NULL;
	struct Node *child_2 = NULL;
	struct Node *child_3 = NULL;
	struct Node *child_4 = NULL;
	struct Node *child_5 = NULL;
	struct Node *child_6 = NULL;
	char configuracao_tabuleiro[LINHA][COLUNA]	
} Node;


Node *root;


/*
   Função que auxilia na inserção de novos nós.
   Esta função retorna o endereço de um nó filho disponível entre os 6.
   Ela inicia o checking de disponibilidade a partir do primeiro filho,
   portanto, os nós não apresentam nenhum tipo de ordenação.
*/
Node *choose_node(Node *node) 
{
	Node *result = NULL;

	if((result = node.child_1) == NULL)
	{
		;
	} else if((result = node.child_2) == NULL)
	{
		;
	} else if((result = node.child_3) == NULL)
	{
		;
	} else if((result = node.child_4) == NULL)
	{
		;
	} else if((result = node.child_5) == NULL)
	{
		;
	} else if((result = node.child_6) == NULL)
	{
		;
	}

	return result;
}


/*
    Função que cria um novo nó.
*/
Node *create_node(void)
{
	Node *node_new = (Node*) malloc(sizeof(Node));
	return node_new
}


/*
   Função que insere novos nós numa árvore de nós, de forma recursiva.   
*/
bool insert_node(char configuracao_tabuleiro[][]) 
{

	if(root->configuracao_tabuleiro == NULL)
	{
		root->configuracao_tabuleiro = configuracao_tabuleiro;
	} else 
	{
		Node *node_new = create_node;
		node_new = insert_node(choose_node(parent), node_new);
		return true;		
	}			
}


/*
   Função que realiza busca de nós numa árvore.
   Encontrado o nó em questão, a função retorna o seu endereço.
   A busca é realizada sempre dós nós filhos mais a esquerda para a direita.   
*/
Node *search_node(Node *node, char tabuleiro_configuracao[][])
{
	if (node == NULL)
	{
		return NULL;
	} else if(node->configuracao_tabuleiro == configuracao_tabuleiro)
	{
		return node;
	} else 
	{
		if(node->child_1 != NULL && node->child_1->configuracao_tabuleiro != configuracao_tabuleiro)
		{
			return search_node(node->child_1, tabuleiro_configuracao);
		}
		
		if(node->child_2 != NULL node->child_2->configuracao_tabuleiro != configuracao_tabuleiro)
		{
			return search_node(node->child_2, tabuleiro_configuracao);
		} 
		
		if(node->child_3 != NULL node->child_3->configuracao_tabuleiro != configuracao_tabuleiro)
		{
			return search_node(node->child_3, tabuleiro_configuracao);
		}
 
		if(node->child_4 != NULL node->child_4->configuracao_tabuleiro != configuracao_tabuleiro)
		{
			return search_node(node->child_4, tabuleiro_configuracao);
		}

		if(node->child_5 != NULL node->child_5->configuracao_tabuleiro != configuracao_tabuleiro)
		{
			return search_node(node->child_5, tabuleiro_configuracao);
		}

		if(node->child_6 != NULL node->child_6->configuracao_tabuleiro != configuracao_tabuleiro)
		{
			return search_node(node->child_6, tabuleiro_configuracao);
		}
	}		
}


/*
 */
bool  search_item(char configuracao_tabuleiro[][])
{
	if((Node *node = search_node(root)) != NULL)
	{
		return true;
	} else
	{
		return false;
	}	
}
