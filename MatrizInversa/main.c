#include <stdio.h>
#include <stdlib.h>

#define dSize 11

int main()
{
    int matrizSize = 0;
    int v = 0;
    int isI = 1;
    int i, j, k;
    int matrizA[dSize][dSize];
    int matrizB[dSize][dSize];
    int matrizM[dSize][dSize];

    while(scanf("%d", &matrizSize) != EOF)
    {
        /////////////////////////////////////////////// ZERANDO MATRIZ

        for(i = 0; i < matrizSize; i++)
        {
            for(j = 0; j < matrizSize; j++)
            {
                matrizA[i][j] = 0;
                matrizB[i][j] = 0;
            }
        }

        /////////////////////////////////////////////// PEGANDO VALORES DA MATRIZ A

        for(i = 0; i < matrizSize; i++)
        {
            for(j = 0; j < matrizSize; j++)
            {
                scanf("%d", &v);
                matrizA[i][j] = v;
            }
        }

        /////////////////////////////////////////////// PEGANDO VALORES DA MATRIZ B
        for(i = 0; i < matrizSize; i++)
        {
            for(j = 0; j < matrizSize; j++)
            {
                scanf("%d", &v);
                matrizB[i][j] = v;
            }
        }

        /////////////////////////////////////////////// MULTIPLICANDO MATRIZ

        for(i = 0; i < matrizSize; i++)
        {
            for(j = 0; j < matrizSize; j++)
            {
                int r = 0;

                for(k = 0; k < matrizSize; k++)
                {
                    r += matrizA[i][k] * matrizB[k][j];
                    //printf("CALCULANDO[%d][%d] temos: %d x %d\n", i,j, matrizA[i][k], matrizB[k][j]);
                }

                matrizM[i][j] = r;
            }
        }

        /////////////////////////////////////////////// CHECANDO SE E IDENTIDADE

        for(i = 0; i < matrizSize; i++)
        {
            for(j = 0; j < matrizSize; j++)
            {
                if(j == i)
                {
                    if(matrizM[i][j] != 1)
                        isI = 0;
                }
                else
                {
                    if(matrizM[i][j] != 0)
                        isI = 0;
                }
            }
        }

        if(isI == 1)
            printf("sim\n");
        else
            printf("nao\n");
    }

    return 0;
}
