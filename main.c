#include "funcoes.c"
#include "funcoes.h"

pthread_mutex_t lock;
//falta a Matriz global de onde os ira ser retirado os recursos

int main(int argc, const char * argv[]) {
    FILE *fp;
    char *str = "teste \n";
    srand(time(NULL));
    int numRecursos = 4; // hardcode do número de recursos que serão utilizados
    
    
    int num = verificarArquivo(fp, str); // verificando se o arquivo tem o formato correto
    if (num <= 0) {
        printf("Arquivo de entrada inválido");
        return 0;
    }
    pthread_t threads[num]; // cria o vetor de threads de acordo com o número de linhas
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    cliente clientes[5];
 
    for (int i = 0; i < num; i++) {
        pthread_create(&threads[i], &attr, initCliente(clientes[i],numRecursos), argv[1]);
    }
                       sleep(50);
    return 0;
}