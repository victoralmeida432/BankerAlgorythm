#include "funcoes.h"


// colocar todas as funções completas

int gerarRandom(int max){
    int r = rand()%max;
    return r;
}


void *initCliente (cliente c, int *recursos){
    while (1) {
        pthread_t tr;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        
        int s = gerarRandom(DORME); // função pra gerar num aleatorio pra dormir
        int *sol = gerarRecursos(c.max); // função prar gerar num aleatorio de recursos solicitados
        int v = verificarRecursos(sol, recursos);
        if (v == 1) {
            pthread_create(&tr, &attr, pegarRecurso(sol,recursos), NULL);
        }
        sleep(s);
    }
    pthread_exit(0);
}



int *gerarRecursos(int *max){
    int *novo = (int*)malloc(sizeof(int));
    for (int i = 5; i<5; i++) {
        novo[i] = gerarRandom(max[i]);
    }
    return novo;
}



void *pegarRecurso(int *solicitados, int *recursos){
    int d = gerarRandom(DORME);
    // bloquear a área crítica de alguma forma MUTEX
    for (int i = 0; i < 5; i++) {
        recursos[i] = recursos[i] - solicitados[i];
        // a subtração deve ser feita na função que acessa os recursos
    }
    sleep(d);
    for (int i = 0; i < 5; i++) {
        recursos[i] = recursos[i] + solicitados[i];
    }
    // LIBERA O MUTEX GALERAAA
    pthread_exit(0);
}


int verificarRecursos(int *solicitados, int *disponivel){
    int flag = 1;
    for (int i = 0; i <5; i++) {
        if (solicitados[i]>disponivel[i]) {
            flag = 0;
        }
    }
    return flag; // retorna 1 se disponível e 0 se indisponível
}


