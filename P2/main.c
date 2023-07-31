#include <stdio.h>
#include <stdlib.h>

#define AmerFile "Americanas.csv"
#define PetFile "Petrobras.csv"
#define SaveFile "AMER3.txt"


typedef  struct  {
    int dia;
    int mes;
    int ano;
    float valorAcao;

} vetorEstruturas;

vetorEstruturas *dadosAmer;
vetorEstruturas *dadosPet;
FILE *Arq;

int le_arq(char *nome_arq, vetorEstruturas *Tabela)
{
    int qtdeLinhas = 0;
    char endLine[10];

    Arq = fopen(nome_arq,"rt");

    if (Arq==NULL)
    {
        printf("\nERRO\n\n");
        exit(-1);
    }

    while ((fscanf(Arq,"%d, %d, %d, %f, %s", &Tabela[qtdeLinhas].dia, &Tabela[qtdeLinhas].mes, &Tabela[qtdeLinhas].ano, &Tabela[qtdeLinhas].valorAcao, endLine)) != EOF)
        qtdeLinhas++;

    fclose(Arq);

    return qtdeLinhas;
}


void salva_arq(char *nome_arq, vetorEstruturas *Tabela, int total_dados)
{
    FILE *fp = fopen(nome_arq, "wt");
    int i;

    if (fp == NULL)
    {
        printf("Error!!");
        exit(-1);
    }

    for(i = total_dados-1; i >= 0; i--)
        fprintf(fp, "%.3f \n", Tabela[i].valorAcao);

    fclose(fp);
}

float maior_valor(vetorEstruturas *Tabela, int total_dados)
{
    float maiorV = 0.00;
    int i;

    for(i = 0; i < total_dados; i++)
    {
        if(Tabela[i].valorAcao > maiorV)
            maiorV = Tabela[i].valorAcao;
    }

    return maiorV;
}

float menor_valor(vetorEstruturas *Tabela, int total_dados)
{
    float menorV = Tabela[0].valorAcao;
    int i;

    for(i = 0; i < total_dados; i++)
    {
        if(Tabela[i].valorAcao < menorV)
            menorV = Tabela[i].valorAcao;
    }

    return menorV;
}

float percentual(vetorEstruturas *Tabela, float maiorV, float menorV)
{
    return (menorV / maiorV) *100 ;
}

float maior_variacao(vetorEstruturas *Tabela, int total_dados, int mes_consultado, int *dia, int *mes, int *ano)
{
    float maiorVar = 0.00;
    int i;

    for(i = 0; i < total_dados; i++)
    {
        while((Tabela[i].mes == *mes) && (i+1 < total_dados))
        {
            float maiorValor, menorValor, newVar;

            if(Tabela[i].valorAcao > Tabela[i+1].valorAcao)
            {
                maiorValor = Tabela[i].valorAcao;
                menorValor = Tabela[i+1].valorAcao;
            }
            else
            {
                menorValor = Tabela[i].valorAcao;
                maiorValor = Tabela[i+1].valorAcao;
            }

            newVar = maiorValor - menorValor;

            if(newVar > maiorVar)
            {
                int saveDay = Tabela[i].dia;
                maiorVar = newVar;
                *dia = saveDay;
                *ano = Tabela[i].ano;
            }
            i++;
        }
    }

    return maiorVar;

}

int main()
{
    int totLinhas = 0;
    int tolLinhasAmer, tolLinhasPet;
    int i;
    float maiorAmer, menorAmer, percAmer;
    float maiorPet, menorPet, percPet;

    scanf("%d", &totLinhas);
    printf("Nro. maximo de linhas: %d\n", totLinhas);

    dadosAmer = (vetorEstruturas*)calloc(totLinhas, sizeof(vetorEstruturas));
    dadosPet = (vetorEstruturas*)calloc(totLinhas, sizeof(vetorEstruturas));

    tolLinhasAmer = le_arq(AmerFile, dadosAmer);
    tolLinhasPet = le_arq(PetFile, dadosPet);

    //////////////////////////////////////////////////////// CALCULANDO DADOS AMERICANAS

    maiorAmer = maior_valor(dadosAmer, tolLinhasAmer);
    menorAmer = menor_valor(dadosAmer, tolLinhasAmer);
    percAmer = percentual(dadosAmer, maiorAmer, menorAmer);

    //////////////////////////////////////////////////////// CALCULANDO DADOS PETROBRAS

    maiorPet = maior_valor(dadosPet, tolLinhasPet);
    menorPet = menor_valor(dadosPet, tolLinhasPet);
    percPet = percentual(dadosPet, maiorPet, menorPet);

    ///////////////////////////////////////////////////////// DADOS AMERICANAS

    printf("Total AMER3: %d\n", tolLinhasAmer);
    printf("DADOS AMER3: ");
    for(i = 0; i < tolLinhasAmer; i++)
    {
        printf("%.3f, ", dadosAmer[i].valorAcao);
    }
    printf("\n\n");

    ///////////////////////////////////////////////////////// DADOS PETROBRAS

    printf("Total PETR4: %d\n", tolLinhasPet);
    printf("DADOS PETR4: ");
    for(i = 0; i < tolLinhasPet; i++)
    {
        printf("%.3f, ", dadosPet[i].valorAcao);
    }
    printf("\n\n");

    ///////////////////////////////////////////////////////// OUTROS DADOS

    printf("AMER3: Menor = %0.3f Maior = %0.3f Percentual(menor/maior) = %.3f%%\n", menorAmer, maiorAmer, percAmer);
    printf("PETR4: Menor = %0.3f Maior = %0.3f Percentual(menor/maior) = %.3f%%\n", menorPet, maiorPet, percPet);

    ///////////////////////////////////////////////////////// MAIOR VARIACAO

    for(i = 1; i <= 5; i++)
    {
        int *dia, *mes, *ano;
        mes = i;
        float maiorVar;

        maiorVar = maior_variacao(dadosAmer, tolLinhasAmer, i, &dia, &mes, &ano);
        printf("Maior Variacao AMER3 (Mes: %d): %d/%d/%d: %.3f\n", i, dia, mes, ano, maiorVar);
    }

    ///////////////////////////////////////////////////////// SALVANDO ARQ .TXT

    salva_arq(SaveFile, dadosAmer, tolLinhasAmer);
    printf("Arquivo AMER3.txt salvo!");

    return 0;
}
