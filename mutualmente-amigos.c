#include <stdio.h>
#include <stdlib.h>
#include <math.h> 


//Primeiro número do range
int min;

//Último número do range
int max;

//Array com todos os números dentro do range
int *vector;

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

int somaDivisores( int valor )
{

	int extra = (int) sqrt( valor ), j, divid, soma = 0;

	for( j = 1; j <= extra; j++ )
	{
		if( valor % j == 0 )
		{
			divid = valor / j;

			if( ( valor / j ) == j )
				divid = 0;
			soma += j + divid;
		}
	}
	return soma;
}

int main(int argc, char **argv) {
	
	if(atoi(argv[1]) && atoi(argv[2])) {
		min = atoi(argv[1]);
		max = atoi(argv[2]);
		populaArray();




	} else {
		printf("Não foram inseridos os números como argumentos. Digite ./mutualmente-amigos x y , sendo x e y os números que gostaria de encontrar."); 
	}


	double fracaoA;
	int range = maximo - minimo;
	double amigos[ range ];
	int i,j; 

	for( j = minimo; j <= maximo; j++ )
	{
		fracaoA = (double) somaDivisores( j ) / j;
		amigos[ j - minimo ] = fracaoA;
	}

	for( i = 0; i <= range; i++ )
	{
		for( j = i + 1; j <= range; j++ )
		{
			if( amigos[ i ] == amigos[ j ] )
			{
				printf( "Os numeros %d e %d são mutuamente amigos.\n",
				( minimo + j ), ( minimo + i ) );
			}
		}
	}

	return 0;
}
