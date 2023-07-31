#include <stdio.h>
#include <stdlib.h>

int **ler_matriz(int linhas, int colunas)
{
    int **valores;
	int i, j;

	valores = (int*)calloc(linhas, sizeof (int*));

	for (i = 0; i < linhas; i++)
		valores[i] = (int*)calloc(colunas, sizeof (int));

	for(i = 0; i < linhas; i++)
	{
		for(j = 0; j < colunas; j++)
		{
			scanf("%d", &valores[i][j]);
		}
	}

	return valores;
}

void somar_matrizes(int **mat1, int **mat2, int linhas, int colunas)
{
    printf("SOMANDO VALORES ----------- \n");
    printf("SOMANDO VALORES (%d) ----------- \n", mat1[0][0]);
    int i, j;
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            //printf("COLUNAS ----------- \n");
            //printf("SOMANDO VALORES (%d + %d) ----------- \n", mat1[i][j], mat2[i][j]);
            printf("SOMANDO VALORES (%d) ----------- \n", mat2[i][j]);
            mat1[i][j] += mat2[i][j];

        }
        printf("ESTAMOS NA LINHA %d ----------- \n", i);
    }

    printf("ACABAMOS DE SOMAR VALORES ----------- \n");
    //imprimir_matriz(mat1, linhas, colunas);
}

void imprimir_matriz(int **mat, int linhas, int colunas)
{
    int i, j;

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void liberar_matriz(int **mat, int linhas)
{
	for(int i = 0; i < linhas; i++)
	{
		free(mat[i]);
	}
}

struct matriz
{
	int linhas, colunas;
	int **valores;
};

int main(void)
{
	int K, i, j, h;
	int soma1 = -1, soma2 = -1;
	struct matriz *matrizes;

	scanf("%d", &K);
	matrizes = (struct matriz*)calloc(K, sizeof(struct matriz*));

	//printf("ESCOLHER VALORES ----------- \n");
	for(i = 0; i < K; i++)
	{
		scanf("%d %d", &matrizes[i].linhas, &matrizes[i].colunas);
		matrizes[i].valores = ler_matriz(matrizes[i].linhas, matrizes[i].colunas);
		//imprimir_matriz(matrizes[i].valores, matrizes[i].linhas, matrizes[i].colunas);
	}

	//printf("FINALIZOU ESCOLHER VALORES ----------- \n");

	/*
	for(i = 0; i < K; i++)
	{
	    printf("\n\n");
		imprimir_matriz(matrizes[i].valores, matrizes[i].linhas, matrizes[i].colunas);
	}*/

	while((soma1 != 0) || (soma2 != 0))
    {
        scanf("%d %d", &soma1, &soma2);
        if((soma1 != 0) || (soma2 != 0))
        {
            int linhas, colunas;

            if(matrizes[soma1].linhas > matrizes[soma2].linhas)
                linhas = matrizes[soma2].linhas;
            else
                linhas = matrizes[soma1].linhas;

            if(matrizes[soma1].colunas > matrizes[soma2].colunas)
                colunas = matrizes[soma2].colunas;
            else
                colunas = matrizes[soma1].colunas;

            //somar_matrizes(matrizes[soma1].valores, matrizes[soma2].valores, matrizes[soma1].linhas, matrizes[soma1].colunas);
            somar_matrizes(matrizes[soma1].valores, matrizes[soma2].valores, linhas, colunas);
            imprimir_matriz(matrizes[soma1].valores, matrizes[soma1].linhas, matrizes[soma1].colunas);
        }

    }

    printf("RESPOSTAS ----------- \n");
    imprimir_matriz(matrizes[0].valores, matrizes[0].linhas, matrizes[0].colunas);
}
