#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#define maxSize 100

typedef struct Cliente
{
	char nome[maxSize];
	char sobrenome[maxSize];
	char cpf[maxSize];
	char idade[maxSize];
	char rua[maxSize];
	char bairro[maxSize];
	char cidade[maxSize];
	char estado[maxSize];
	char nCasa[maxSize];

} Cliente;

int main()
{
	int qtdeCadastro;
	int i, lastIndex = 0;
	char opcao[maxSize];
	Cliente *clientes;
	Cliente *clientResult;

	scanf("%d", &qtdeCadastro);

	clientes = (Cliente*)calloc(qtdeCadastro,sizeof(Cliente));
	clientResult = (Cliente*)calloc(qtdeCadastro,sizeof(Cliente));

	for(i = 0; i < qtdeCadastro; i++)
	{

	    //printf("NOVO CLIENTE -------------------------\n");

	    Cliente c;

	    //printf("Nome: ");
	    fflush(stdin);
	    fgets(c.nome, maxSize, stdin);

	    //printf("Sobrenome: ");
	    fflush(stdin);
	    fgets(c.sobrenome, maxSize, stdin);

	    //printf("CPF: ");
	    fflush(stdin);
	    fgets(c.cpf, maxSize, stdin);

	    //printf("Idade: ");
	    fflush(stdin);
	    fgets(c.idade, maxSize, stdin);

	    //printf("Rua: ");
        fflush(stdin);
        fgets(c.rua, maxSize, stdin);

        //printf("Bairro: ");
        fflush(stdin);
        fgets(c.bairro, maxSize, stdin);

        //printf("Cidade: ");
        fflush(stdin);
        fgets(c.cidade, maxSize, stdin);

	    //printf("Estado: ");
	    fflush(stdin);
        fgets(c.estado, maxSize, stdin);

	    //printf("N Casa: ");
	    fflush(stdin);
	    fgets(c.nCasa, maxSize, stdin);

		clientes[i] = c;
	}

    fflush(stdin);
	while(atoi(opcao) != -1)
    {
        char cpfSearch[maxSize];
        char nameSearch[maxSize];

        //printf("O que deseja: ");
        fflush(stdin);
        fgets(opcao, maxSize, stdin);

        switch(atoi(opcao))
        {
            case 1:
            {
                //printf("Insira um cpf: ");
                fflush(stdin);
                fgets(cpfSearch, maxSize, stdin);

                for(i = 0; i < qtdeCadastro; i++)
                {
                    if(!strcmp(clientes[i].cpf, cpfSearch))
                    {
                        clientResult[lastIndex] = clientes[i];
                        lastIndex++;
                    }
                }

                break;
            }


            case 2:
            {
                //printf("Insira um nome: ");
                fflush(stdin);
                fgets(nameSearch, maxSize, stdin);

                for(i = 0; i < qtdeCadastro; i++)
                {
                    if(!strcmp(clientes[i].nome, nameSearch))
                    {
                        clientResult[lastIndex] = clientes[i];
                        lastIndex++;
                    }
                }

                break;
            }

        }
    }

    for(i = 0; i < lastIndex; i++)
    {
        printf("CPF: %s", clientResult[i].cpf);
        printf("Nome: %s", clientResult[i].nome);
        printf("Sobrenome: %s", clientResult[i].sobrenome);
        printf("Idade: %s", clientResult[i].idade);
        printf("Rua: %s", clientResult[i].rua);
        printf("Bairro: %s", clientResult[i].bairro);
        printf("Cidade: %s", clientResult[i].cidade);
        printf("Estado: %s", clientResult[i].estado);
        printf("NroCasa: %s\n", clientResult[i].nCasa);
    }
}
