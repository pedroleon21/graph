#include<stdio.h>
#include<stdlib.h>
#include"lista.h"
#include"graph.h"
#include<time.h>

int main(){
    Lista * lista = create_lista(), * lista2 = create_lista();
    for(int i=0;i<100;i++){
        int val = rand()%10000;
        lista = push_order(lista,val);
        lista2 = push_no(lista2,val);
    }
    printf("tamanho: %d\n", lista->length);
    for(int i=0;i<100;i++){
        printf("%d:%d\n",lista_pop(lista),lista_pop(lista2));
    }
    free_lista(lista);
    free_lista(lista2);
    return 0;
}