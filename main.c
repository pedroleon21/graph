#include<stdio.h>
#include<stdlib.h>
#include"lista.h"
#include"graph.h"
#include<time.h>

int main(){
    Lista * lista = create_lista();
    for(int i=0;i<100;i++){
        lista = push_order(lista,rand()%10000);
    }
    printf("tamanho: %d\n", lista->length);
    for(int i=0;i<100;i++){
        printf("%d\n",lista_pop(lista));
    }
    free_lista(lista);
    return 0;
}