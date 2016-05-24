#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


//Primeiro número do range
int min;

//Último número do range
int max;

//Array com todos os números dentro do range
int *vector;

//Número de threads
int numThreads;

//Mutex
pthread_mutex_t mutex;

// Aponta para o proximo bucket que a thread pegará
int ponteiroBucket = 0;

void populaArray(){
    int i;
    int counter;

    //Verifica se Max é maior que min senão sai do programa
    if(max - min > 0) {
        // Inicializa o array
        v = (int*) malloc(sizeof(int) * (max - min));

        // Popula array de 0 a (max - min)
        for (i = 0; i < (max - min); i++) {     
            v[i] = min;
        }
    }
}

// Inicializa as threads
void comecaThreads(pthread_t *threads, int numThreads){
    // Cria o mutex
    pthread_mutex_init(&mutex, NULL);
    int i;
    for(i = 0; i < numThreads; i++){
        // cria a thread e vê se ela tem algum bucket pra resolver
        pthread_create(&threads[i], NULL, bucketEscolha, (void *)i);
    }

    for(i = 0; i < nThreads; i++){
        // Evita que apenas uma thread faça todo o trabalho sujo
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
}

int main(int argc, char **argv) {
    // Se o console não enviou os três parâmetros
    if(argc <= 3){
        printf("%s\n", "Favor inserir os três parâmetros." );
        exit(0);
    }
    // Pega os 3 parâmetros do bash
    min = atoi(argv[1]);
    max = atoi(argv[2]);
    numThreads = atoi(argv[3]);

    // Popula o vetor()
    populaArray();

    // Imprime os valores do vetor embaralhado na tela
    int i; for (i = 0; i < tamVet; i++) {    
        printf("%d ", v[i]);
    }
    printf("\n");

    pthread_t threads[numThreads];

    comecaThreads(threads, numThreads);
    

    return 0;
}
