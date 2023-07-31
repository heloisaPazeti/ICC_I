#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **vetor;
    int *x1;
    int *x2;
	int n, m;
	int i, j;
	int pos = 0, neg = 0;

	scanf("%d %d", &n, &m);

////////////////////////////////////////////////// MONTA VETOR E X1 E X2


	vetor = (int **)calloc(n, sizeof(int *));
	for (i = 0; i < n; i++)
		vetor[i] = (int *)calloc(m, sizeof(int));

    x1 = (int*)calloc(n-2, sizeof(int));
    x2 = (int*)calloc(n-2, sizeof(int));

////////////////////////////////////////////////// CRIA DUAS PRIMEIRAS LINHAS

	for(i = 1; i <= 2; i++)
    {
		for(j = 1; j <= m; j++)
		{
			switch(i)
			{
				case 1:
                {
                    if(j % 2 == 0)
						vetor[i-1][j-1] = 0;
					else
						vetor[i-1][j-1] = j;

					break;
                }
				case 2:
				{
					if(j % 2 == 0)
						vetor[i-1][j-1] = j;
					else
						vetor[i-1][j-1] = 0;

					break;
				}
			}
		}
	}

////////////////////////////////////////////////// PEGAR X1 E X2 E MONTAR OUTRAS LINHAS

	for(i = 0; i < n-2; i++)
        scanf("%d %d", &x1[i], &x2[i]);

	for(i = 3; i <= n; i++)
	{
        for(j = 1; j <= m; j++)
        {
            if(x1[i-3] <= x2[i-3])
            {
                if(j >= (x1[i-3]) && j <= (x2[i-3]))
                    vetor[i-1][j-1] = vetor[i-3][j-1] - vetor[i-2][j-1];
                else
                    vetor[i-1][j-1] = vetor[i-3][j-1] + vetor[i-2][j-1];
            }
            else if(x1[i-3] > x2[i-3])
            {
                if(j >= (x2[i-3]) && j <= (x1[i-3]))
                    vetor[i-1][j-1] = vetor[i-3][j-1] - vetor[i-2][j-1];
                else
                    vetor[i-1][j-1] = vetor[i-3][j-1] + vetor[i-2][j-1];
            }

        }
	}

////////////////////////////////////////////////// MOSTRAR MATRIZ PRONTA

	/*
	for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(j != m - 1)
                printf("%d ", vetor[i][j]);
            else
                printf("%d\n", vetor[i][j]);
        }
    }*/

////////////////////////////////////////////////// CALCULAR ÚLTIMA LINHA E QTDE + E -

    for(j = 0; j < m; j++)
    {
        if(vetor[n-1][j] > 0)
             pos++;
        else if (vetor[n-1][j] < 0)
            neg++;

    }

    printf("%d %d", neg, pos);

    return 0;
}

