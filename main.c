#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"lista.h"
#include"graph.h"
#include "lib\sorts.h"
#include "lib\utils.h"
#include "lib\printer.h"

int main(){
    Lista * lista = criar_lista(), * lista2 = criar_lista();
    for(long long i=0;i<79999999;i++){
        int val = rand()%10000;
        lista->add(lista,val);
    }
    printf("tamanho: %lli\n", lista->length);
    
    int end_length=0,ini_length = lista->length;
    while (!is_empty(lista))
    {
        list_remove(lista,lista-> length <= 2? lista->length - 1 : 2);
        end_length++;
    }
    printf("\nremoveu todos:%s",(end_length==ini_length ? "true": "false"));

    free_lista(lista);
    free_lista(lista2);
    return 0;
}