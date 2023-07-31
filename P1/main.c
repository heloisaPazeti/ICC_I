#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

int main()
{
    int qtdeParadas = 0;
    int qtdeIn = 0; //qtde pessoas entraram
    int qtdeOut = 0; //qtde pessoas sairam
    int totalPes = 0;

    char inOut[100]; //recebe formatacao "entrada saida"
    char delim[] = " "; //para dar split na string
    char *ptr; //guardar valor

    int inParadas[100][100]; //movimentacao = [index parada][qtde Entrou]
    int outParadas[100][100]; //movimentacao = [index parada][qtde Sairam]

    int peopleOnBus[100][100];
    int paradeIndex = 0; //parada onde quantidade pessoas foi maior
    int biggerPeopleQuant = 0;
    int smallerPeopleQuant = 1000;

    int totalPeopleOnBus = 0;
    float totalV = 0.00;
    float media = 0.00;
    float dPadrao = 0.00;

    scanf("%d", &qtdeParadas);

    while(qtdeParadas < 2 || qtdeParadas > 10)
    {
        printf("Valor de paradas invalida. Tente Novamente.\n");
        scanf("%d", &qtdeParadas);
    }

    for (int i = 0; i < qtdeParadas; i++)
    {
        fflush(stdin);
        fgets(inOut,100,stdin);
        ptr = strtok(inOut, delim);

        for (int n = 0; n < 2; n++)
        {
            if(n == 0)
            {
                qtdeIn = atoi(ptr);
                totalPes += qtdeIn;

                inParadas[i][0] = qtdeIn;

                if(i == qtdeParadas - 1 && qtdeIn != 0)
                {
                    printf("Esse e o fim da linha... nao podemos pegar mais ninguem.");
                    exit(0);
                }
            }
            else if(n == 1)
            {
                if(i == 0 && atoi(ptr) != 0)
                {
                    printf("Sendo a primeira parada passageiros nao deveriam sair.");
                    exit(0);
                }

                if(atoi(ptr) > totalPes)
                {
                    printf("Nao podem sair mais pessoas do que entraram...\n");
                    exit(0);
                }
                else
                {
                    qtdeOut = atoi(ptr);
                    outParadas[i][0] = qtdeOut;
                }
            }
            if (i == 0)
            {
                peopleOnBus[i][0] = qtdeIn - qtdeOut;
                biggerPeopleQuant = peopleOnBus[i][0];
            }
            else
            {
                peopleOnBus[i][0] = (peopleOnBus[i-1][0] + qtdeIn) - qtdeOut;
            }

            ptr = strtok(NULL, delim);
        }
    }

    printf("%d\n", totalPes);

    for (int k = 1; k <= qtdeParadas; k++)
    {
        printf("%d %d\n", k, peopleOnBus[k - 1][0]);

        if (biggerPeopleQuant < peopleOnBus[k -1][0])
        {
            biggerPeopleQuant = peopleOnBus[k -1][0];
            paradeIndex = k;
        }

        if(smallerPeopleQuant > peopleOnBus[k -1][0] && peopleOnBus[k -1][0] != 0)
        {
            smallerPeopleQuant = peopleOnBus[k -1][0];
        }

        totalPeopleOnBus += peopleOnBus[k-1][0];
    }


    media = (float)totalPeopleOnBus / qtdeParadas;

    for (int i = 0; i < qtdeParadas; i++)
    {
        totalV += (float)pow(((float)peopleOnBus[i][0]- media),2);
        dPadrao = sqrt((float)totalV/(float)qtdeParadas);
    }

    printf("%d\n", biggerPeopleQuant);
    printf("%d\n", smallerPeopleQuant);
    printf("%d\n", paradeIndex);
    printf("%.2f %.2f", media, dPadrao);

    return 0;
}
