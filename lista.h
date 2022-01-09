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

typedef struct Lista Lista,*pno;

typedef struct Lista{
    long long length;
    struct No * inic,* fim;
    pno (*add)(Lista* l,int valor);
    pno (*add_order)(Lista *l,int valor);
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

No * achar_no(Lista *l,int index){
    No *no;
    int index_on=0;
    if(index < l->length/2){
        no= l->inic;
        while(index_on < index){
            no=no->prox;
            index_on++;
        }
    }else{
        index_on=l->length - 1;
        no= l->fim;
        while(index_on > index){
            no=no->ant;
            index_on--;
        }
    }
    return no;
}

int remove_index(Lista *l,int index){
    No * no = achar_no(l,index);
    int valor=0,index_on=0;
    if(l->inic == no && l->fim == no){
        l->inic=l->fim=NULL;
        valor = no->valor;
    }else if(l->inic==no){
        l->inic = no->prox;
        valor = no->valor;
        no->prox->ant=NULL;
    }else if(l->fim == no){
        l->fim=no->ant;
        valor = no->valor;
        no->ant->prox=NULL;
    }else{
        no->prox->ant=no->ant;
        no->ant->prox=no->prox;
        valor = no->valor;
    }
    l->length--;
    free(no);
    return valor;
}

int list_remove(Lista * l,int index){
    if(index > l->length - 1) return 0;
    return remove_index(l,index);
}


int list_get(Lista *l,int index){
    int index_on=0;
    No *no;
    if(index > l->length - 1) return 0;
    return achar_no(l,index)->valor;
}

int lista_pop(Lista * l){
    No * no = remove_first(l);
    if(no == NULL) return -1;
    int valor = no->valor;
    free(no);
    return valor;
}

pno add_function(Lista *l,int valor){
    push_no(l,valor);
}
pno add_orde_funcation(Lista *l,int valor){
    push_order(l,valor);
}

Lista * new_lista(){
    Lista * l = (Lista*)calloc(1,sizeof(Lista));
    l->length = 0;
    l->inic=l->fim=NULL;
    l->add=add_function;
    l->add_order=add_orde_funcation;
    return l;
}

Lista * criar_lista(){
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

int is_empty(Lista *l){
    return !l->length;
}

Lista * array_to_lista(int * vetor,int size){
    Lista *lista = new_lista();
    for(int i=0;i<size;i++){
        lista->add(lista,vetor[i]);
    }
    return lista;
}

#endif