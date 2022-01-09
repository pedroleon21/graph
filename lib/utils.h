

#ifndef UTILS_H
#define UTILS_H

void baguncar_vetor(long long vetor[],long long n){
    printf("\nbaguncando vetor");
    
    for(long long i=0; i<n; i++){
        vetor[i]=i;
    }
    for(long long i=0; i<n; i++){
        long long x = rand()%n;
        long long swap = vetor[x];
        vetor[x]=vetor[i];
        vetor[i]=swap;
    }
}


long long * criar_vetor_long_long(int n,int size){
    long long *vet = (long long *)calloc(n,size);
    printf("\nAllocando vetor, n:%d ,size:%d",n,size);
    for(long long i=0; i< n; i++){
        vet[i]=i;
    }
    return vet;
}


#endif