#include <stdlib.h>
#include <stdio.h>


int main( void )
{
    /* Vetor de entrada com elementos de valor duplicado */
    int vetor[14] = { 1, 2, 3, 4, 4, 5, 5, 6, 7, 8, 9, 9, 10, 10 };

    /* Vetor de saida */
    int saida[14];

    int i, j, n = 0;
    int tam = sizeof(vetor) / sizeof(int);

    /* Exibe Vetor de Entrada */
    printf("Antes: ");
    for( i = 0; i < tam; i++ )
        printf("%d ", vetor[i] );
    printf("\n");

    /* Remove elementos com valor duplicado */
    for( i = 0; i < tam; i++)
    {
        for( j = 0; j < n; j++ )
        {
            if( vetor[i] == saida[j] )
                break;
        }

        if( j == n )
        {
            saida[n] = vetor[i];
            n++;
        }
    }

    /* Exibe Vetor de Saida */
    printf("Depois: ");
    for( i = 0; i < n; i++ )
        printf("%d ", saida[i] );
    printf("\n");

    return 0;
}
