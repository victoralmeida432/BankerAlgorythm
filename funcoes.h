#ifndef funcoes_h
#define funcoes_h
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h> // biblioteca pra usar o sleep()
#define DORME 5

typedef struct Cliente_banker {
    int max[5];
    int pedido[5];
} cliente;

// colocar as definições dos structs e cabeçalhos das funções

int verificarArquivo(FILE *fp, char *str);
void *initCliente(cliente c, int *rec);
int gerarRandom(int max);
int *gerarRecursos(int *max);
int verificarRecursos(int *solicitados, int *disponivel);
void *pegarRecurso(int *solicitados, int *recursos);
void *liberarRecurso(int *solicitados, int *recursos);



#endif /* funcoes_h */