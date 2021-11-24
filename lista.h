#ifndef LISTA_H
#define LISTA_H

#ifndef STDLIB_H
#define STDLIB_H
#endif

#ifndef STDIO_H
#define STDIO_H
#endif

typedef struct No{
    int valor;
    struct No * prox,*ant;
}No;

typedef struct Lista{
    int length;
    struct No * inic,* fim;
}Lista;

No * new_no(int valor){
    No* no = (No*) calloc(1,sizeof(No));
    no->prox=no->ant=NULL;
    no->valor=valor;
    return no;
}

Lista * push_order(Lista *lista,int valor){
    if(lista->inic == NULL && lista->fim == NULL){
        lista->inic=lista->fim=new_no(valor);
    }else{
        No * buffer = lista->inic;
        while(buffer->valor < valor && buffer->prox != NULL){
            buffer=buffer->prox;
        }
        if(buffer == lista->fim){
            buffer->prox=new_no(valor);
            buffer->prox->ant = buffer;
            lista->fim=buffer->prox;
        }else if(buffer == lista->inic){
            lista->inic=new_no(valor);
            lista->inic->prox=buffer;
            buffer->ant=lista->inic;
        }else {
            No *no = new_no(valor);
            no->prox=buffer;
            no->ant=buffer->ant;
            no->ant->prox=no;
            buffer->ant=no;
        }
    }
    lista->length++;
    return lista;
}


Lista * push_no(Lista * l,int valor){
    if(l->inic == NULL && l->fim == NULL){
        l->inic=l->fim = new_no(valor);
    }else{
        No * buffer = l->fim;
        No * _no = new_no(valor);
        buffer->prox=_no;
        _no->ant=buffer;
        l->fim=_no;
    }
    l->length++;
    return l;
}

No * remove_first(Lista *l){
    No * no = l->inic;
    if(no != NULL){
        if(l->inic == l->fim){
            l->inic=l->fim= NULL;
        }else{
            l->inic = no->prox;
            if(l->inic != NULL){
                l->inic->ant = NULL;
            }
        }
        l->length--;
    }
    return no;
}

int lista_pop(Lista * l){
    No * no = remove_first(l);
    if(no == NULL) return -1;
    int valor = no->valor;
    free(no);
    return valor;
}

Lista * new_lista(){
    Lista * l = (Lista*)calloc(1,sizeof(Lista));
    l->length = 0;
    l->inic=l->fim=NULL;
    return l;
}

Lista * create_lista(){
    return new_lista();
}

void free_nos(No * no){
    while(no != NULL){
        No * buffer =no->prox;
        free(no);
        no = buffer;
    }
}

void free_lista(Lista * lista){
    No * no = lista->inic;
    free(lista);
    free_nos(no);
}

#endif