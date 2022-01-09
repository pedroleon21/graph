
#include "lista.h"

#ifndef GRAPH_H
#define GRAPH_H

#ifndef STDLIB_H
#define STDLIB_H
#endif

#ifndef STDIO_H
#define STDIO_H
#endif

#ifdef LISTA_H
#define LISTA_H
#endif

typedef struct Node{
     Lista * lista_adj ;
     int valor;
     int visitado;
}Node;


typedef struct Tree{
    struct Node * root;
}Tree;

Node * new_node(int valor){
    Node * node = (Node*)malloc(1 * sizeof(Node));
    return node;
}

//void add_children_fn(Tree * tree,int valor){
//    Node no = new_node(valor); 
//}

Tree * new_tree(){
    Tree * tree = (Tree*)calloc(1,sizeof(tree));
    return tree;
}

Node* push_adj(Node * node, int valor){
    if(node->lista_adj == NULL){
        node->lista_adj = criar_lista();
    }
    node->lista_adj->add_order(node->lista_adj,valor);
    return node;
}

int size_adj_lista(Node * node){
    if(node->lista_adj== NULL){
        return 0;
    }
    return node->lista_adj->length;
}

void visitar(Node *node){
    node->visitado=1;
}

int vistado(Node * node){
    return node->visitado;
}

void limpar_visita(Node * node){
    node->visitado=0;
}

#endif