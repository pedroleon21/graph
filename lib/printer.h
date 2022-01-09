
#include <stdarg.h>

#ifndef PRINTER_H
#define PRINTER_H

void print_vetor(long long vetor[],long long n){
    printf("\n[");
    for(long long i=0;i<n;i++){
        if(i == n-1)
            printf("%d",vetor[i]);
        else
            printf("%d, ",vetor[i]);
    }
    printf("]\n");
}


#endif