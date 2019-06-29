/*
   Implementing a Data Abstract Structure: A SixTree.
   Public methods:
	-> insert_item(Node* root, casa_ao_lado* configuracoes_possiveis)
	-> search_item(Node* root, casa_ao_lado* configuracoes_possiveis)
*/
#include <stdlib.h>
#include <stdbool.h>


/*
   SixTree baseline structure.
   By default all data pointers members'll be initialized with NULL.   
*/
typedef struct Node {
	struct Node* child_1;
	struct Node* child_2;
	struct Node* child_3;
	struct Node* child_4;
	struct Node* child_5;
	struct Node* child_6;
	casa_ao_lado* configuracoes_possiveis;
} Node;


/* function's prototypes */
static Node *choose_node(Node *node);
static Node* search_node(Node* node, casa_ao_lado* configuracoes_possiveis);
bool search_item(Node* root, casa_ao_lado* configuracoes_possiveis);
bool insert_item(Node* root, casa_ao_lado* configuracoes_possiveis);
static Node* create_node(Node* node, casa_ao_lado* configuracoes_possiveis);


/*
   Função que auxilia na inserção de novos nós.
   Esta função retorna o endereço de um nó filho disponível entre os 6.
   Ela inicia o checking de disponibilidade a partir do primeiro filho,
   portanto, os nós não apresentam nenhum tipo de ordenação.
*/
Node *choose_node(Node *node) 
{
	Node *result = NULL;

	if((result = node->child_1) == NULL)
	{
		;
	} else if((result = node->child_2) == NULL)
	{
		;
	} else if((result = node->child_3) == NULL)
	{
		;
	} else if((result = node->child_4) == NULL)
	{
		;
	} else if((result = node->child_5) == NULL)
	{
		;
	} else if((result = node->child_6) == NULL)
	{
		;
	}

	return result;
}


/*
   A function that helps to find items on the tree.
   This is not a public function, then is not callable outside this file's scope.
*/
static Node* search_node(Node* node, casa_ao_lado* configuracoes_possiveis)
{
	if(node->configuracoes_possiveis == configuracoes_possiveis)
	{
		;
	} else if(node->child_1 != NULL)
	{
		return search_node(node->child_1, configuracoes_possiveis);
	} else if(node->child_2 != NULL)
	{
		return search_node(node->child_2, configuracoes_possiveis);
	} else if(node->child_3 != NULL)
	{
		return search_node(node->child_3, configuracoes_possiveis);
	} else if(node->child_4 != NULL)
	{
		return search_node(node->child_4, configuracoes_possiveis);
	} else if(node->child_5 != NULL)
	{
		return search_node(node->child_5, configuracoes_possiveis);
	} else if(node->child_6 != NULL)
	{
		return search_node(node->child_6, configuracoes_possiveis);
	}
		
	return node;	
}


/*
   A function that finds elements on the tree.
*/
bool search_item(Node* node, casa_ao_lado* configuracoes_possiveis)
{
	if(search_node(node, configuracoes_possiveis)->configuracoes_possiveis == configuracoes_possiveis)
	{
		return true;
	} else
	{
		return false;
	}
}


/*
    A function that inserts elements on the tree.
*/
bool insert_item(Node* node, casa_ao_lado* configuracoes_possiveis)
{
	if(!(node->configuracoes_possiveis))
	{
		node->configuracoes_possiveis = configuracoes_possiveis;
		return true;		
	} else if(!search_item(node, configuracoes_possiveis))
	{
		Node* new_node = create_node(node, configuracoes_possiveis);
		new_node->configuracoes_possiveis = configuracoes_possiveis;
		return true;		
	}
	
	return false;	
}


/*
   A function that helps to insert items on the tree.
   This is not a public function, then is not callable outside this file's scope.
*/
static Node* create_node(Node* node, casa_ao_lado* configuracoes_possiveis)
{	
	/* first we have to allocate a new block of memory to the new node */
	Node* new_node = (Node*) malloc(sizeof(Node));
	Node* parent = search_node(node, configuracoes_possiveis);
	
	/* then we have to decide which side the node'll be inserted */
	parent->choose_node(node) = new_node;	
	
	return new_node;	
}
