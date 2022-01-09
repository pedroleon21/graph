

#ifndef SORTES_H
#define SORTES_H


void bubbler_sort(long long vetor[],long long n){
    printf("\nbubbler_sort");
    int flag = 1;
    for(long long i=0;i<n && flag;i++){
        flag=0;
        for(long long j=0;j<n-1;j++){
            if(vetor[i] <= vetor[j]){
                flag=1;
                long long buffer=vetor[i];
                vetor[i]=vetor[j];
                vetor[j]=buffer;
            }
        }
    }
}

void swap(long long vetor[],long long index1,long long index2){
    long long buffer =vetor[index1];
    vetor[index1] = vetor[index2];
    vetor[index2]= buffer;
}

void q_sort(long long vetor[],long long init,long long end){
    long long menorIndex=init,maiorIndex=end,pivo=vetor[end];

    if(init >= end) return;

    while(menorIndex < maiorIndex){
        while(vetor[menorIndex] <= pivo && menorIndex < maiorIndex){
            menorIndex++;
        } 
        while(vetor[maiorIndex] >= pivo && maiorIndex > menorIndex ){
            maiorIndex--;
        }

        swap(vetor,menorIndex,maiorIndex);
    }
    swap(vetor,menorIndex,end);

    q_sort(vetor,init,menorIndex-1);
    q_sort(vetor,maiorIndex + 1,end);

}

void quick_sort(long long vetor[],long long size){
    printf("\nquick_sort");
    q_sort(vetor,0,size-1);
}


#endif