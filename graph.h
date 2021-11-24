
#ifndef GRAPH_H
#define GRAPH_H

#ifndef LISTA_H
#define LISTA_H
#endif

#ifndef STDLIB_H
#define STDLIB_H
#endif

#ifndef STDIO_H
#define STDIO_H
#endif


typedef struct Node{
     Lista * lista_adj ;
     int valor;
     int visitado;
}Node;

Node* push_adj(Node * node, int valor){
    if(node->lista_adj == NULL){
        node->lista_adj = create_lista();
    }
    node->lista_adj = push_order(node->lista_adj,valor);
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