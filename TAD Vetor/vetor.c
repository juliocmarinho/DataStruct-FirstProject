#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

struct vetor{
int tamanho;
float *elementos;
};

Vetor* criaVetor(int n){
    if(n <= 0){
        printf("Tamanho invalido: menor ou igual a 0!\n");
        return NULL;
    }

    Vetor* v = (Vetor*) malloc(sizeof(Vetor));

    if (v == NULL) {
        printf("Memoria insuficiente!\n");
        exit(1);
    }

    v->tamanho = n;

    v->elementos = (float*) malloc(sizeof(float)*n);

    if (v->elementos == NULL) {
        printf("Memoria insuficiente!\n");
        exit(1);
    }

    return v;
}

void liberaVetor(Vetor* v){
    free(v->elementos);
    free(v);
}

int tamanhoVetor(Vetor* v){
    return v->tamanho;
}

float acessa(Vetor* v, int i){
    if(v->tamanho > i && i >= 0 ){
        return v->elementos[i];
    }else{
        printf("Indice fora da faixa do vetor!\n");
        return -999999;
    }
}

void atribui(Vetor* v, int i, float c){
    if(v->tamanho > i && i >= 0){
        v->elementos[i] = c;
    }else{
        printf("Indice fora da faixa do vetor!\n");
    }
}

float maior(Vetor* v){
    float maior = v->elementos[0];

    for(int i=1;i<v->tamanho;i++){
        if(v->elementos[i] > maior)
            maior = v->elementos[i];
    }
    
    return maior;
}

float menor(Vetor* v){
    float menor = v->elementos[0];

    for(int i=1;i<v->tamanho;i++){
        if(v->elementos[i] < menor)
            menor = v->elementos[i];
    }

    return menor;
}

void listarVetor(Vetor* v){
    if(v != NULL){
    printf("{");

    for(int i=0;i<v->tamanho;i++)
        printf(" %.1f ",v->elementos[i]);
    
    printf("}\n");
    }else{
        printf("Vetor vazio!\n");
    }
}

float somaVetor(Vetor* v){
    float soma = 0;

    for(int i=0;i<v->tamanho;i++)
        soma += v->elementos[i];

    return soma;
}

float somaElementos(Vetor* v, int n){
    if(v->tamanho < n || n < 0){
        printf("Indice fora da faixa do vetor!\n");
       return -999999;
    }
    
    float soma = 0;

    for(int i=0;i<n;i++)
        soma += v->elementos[i];

    return soma;
}

Vetor* somaVetores(Vetor* v1, Vetor* v2){
    if(v1->tamanho != v2->tamanho){
        printf("Vetores com tamanhos desiguais\n");
        return NULL;
    }

    Vetor* resultante = criaVetor(v1->tamanho);

    for(int i=0;i<v1->tamanho;i++)
        atribui(resultante, i, v1->elementos[i] + v2->elementos[i]);

    return resultante;
}

void mostrasomaVetores(Vetor* v1, Vetor* v2){
    if(v1->tamanho != v2->tamanho){
        printf("Vetores com tamanhos desiguais\n");
    }else{
        printf("Entrada:\nv1 = ");
        listarVetor(v1);
        printf("v2 = ");
        listarVetor(v2);
        printf("Saida:");

        for(int i=0;i<v1->tamanho;i++)
            printf("\n%.1f + %.1f = %.1f", v1->elementos[i], v2->elementos[i], v1->elementos[i] + v2->elementos[i]);
    }
}
