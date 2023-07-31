#include <stdio.h>
#include <stdlib.h>

unsigned char meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct
{
	unsigned char dia, mes;
	short unsigned ano;
} Data;

int main()
{
	int N, M;
	int i, qtdeDias = 0;
	int *index1;
	int *index2;
	Data *datas;

	scanf("%d", &N);
	datas = (Data*)calloc(N, sizeof(Data));


	for(i = 0; i < N; i++)
		scanf("%hhu/%hhu/%hu", &datas[i].dia, &datas[i].mes, &datas[i].ano);

	scanf("%d", &M);

	index1 = (int*)calloc(M, sizeof(int));
	index2 = (int*)calloc(M, sizeof(int));

	for(i = 0; i < M; i++)
		scanf("%d %d", &index1[i], &index2[i]);

	for(i = 0; i < M; i++)
	{
		Data biggerDate = datas[index1[i]];
		Data smallerDate = datas[index2[i]];

		/////////////////////////////////////////////////////////////////////////////////// CHECKING WICH IS BIGGER

		if(datas[index1[i]].ano < datas[index2[i]].ano)
		{
			biggerDate = datas[index2[i]];
			smallerDate = datas[index1[i]];
		}
		else if(datas[index1[i]].ano == datas[index2[i]].ano)
		{
			if(datas[index1[i]].mes < datas[index2[i]].mes)
			{
				biggerDate = datas[index2[i]];
				smallerDate = datas[index1[i]];
			}
			else if(datas[index1[i]].mes == datas[index2[i]].mes)
			{
				if(datas[index1[i]].dia < datas[index2[i]].dia)
				{
					biggerDate = datas[index2[i]];
					smallerDate = datas[index1[i]];
				}
			}
		}

		/////////////////////////////////////////////////////////////////////////////////// COUTING DAYS
		qtdeDias = 0;
		while(smallerDate.dia != biggerDate.dia || smallerDate.mes != biggerDate.mes || smallerDate.ano != biggerDate.ano)
		{
			smallerDate.dia++;

			if(smallerDate.dia > meses[smallerDate.mes-1])
			{
				smallerDate.dia = 1;
				smallerDate.mes++;
				if((smallerDate.mes) > sizeof(meses))
				{
					smallerDate.mes = 1;
					smallerDate.ano++;
				}
			}

			qtdeDias++;
		}

		if(i < N)
        printf("%d\n", qtdeDias);
		else
			printf("%d", qtdeDias);
	}
}
