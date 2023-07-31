#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define InfoFile "Info.txt"
#define fieldSize 200

FILE *fp;
FILE *entry;
char name[fieldSize];
int pronoun = 0;
int lastId = -1;

void Start();
void Menu();
void Close();
void NewEntry();
bool ListEntries();
bool ReadEntry();
bool DeleteEntry();
bool DeleteAll();
bool Cripto();
bool Uncripto();

void WriteInfoFile();

/*
struct Entry
{
    int id;
    char name[200];
    char date[100];
    char text[1000];
};
*/


int main()
{
    Start();
    return 0;
}

void Start()
{
    fp = fopen(InfoFile, "r");

    if(fp != NULL)
    {
        for (int i = 0; i < 3; i++)
        {
            switch(i)
            {
                case 0:
                    fgets(name, fieldSize, fp);
                    name[strcspn(name, "\n")] = 0;
                    break;

                case 1:
                    fscanf(fp, "%d", &pronoun);
                    break;

                case 2:
                    fscanf(fp, "%d", &lastId);
                    break;
            }
        }

        switch(pronoun)
        {
            case 1:
                printf(">> Seja Bem-Vindo, %s, o que deseja? <<\n\n", name);
                break;

            case 2:
                printf(">> Seja Bem-Vinda, %s, o que deseja? <<\n\n", name);
                break;

            case 3:
                printf(">> Ola, %s, o que deseja? <<\n\n", name);
                break;

            default:
                printf("Parece que um erro aconteceu: %d", pronoun);
                exit(1);
                break;
        }

        Menu();
    }
    else
    {

        printf("Oh nao... parece que ainda nao conhecemos. Qual o seu nome?\n");
        fflush(stdin);
        fgets(name, 100, stdin);
        name[strcspn(name, "\n")] = 0;

        printf("Muito bem, %s, e como devo me referir a voce?\n", name);
        printf("[1] Ele\n[2]Ela\n[3]Neutro\n");
        scanf("%d", &pronoun);

        WriteInfoFile();

        printf("Agora sim, podemos comecar!\n");
        Menu();
    }
}

void Menu()
{
    bool open = true;
    int option = 0;

    while(open)
    {
        printf("------------- MENU --------------\n");
        printf("\n");
        printf("[1] Nova Entrada\n");
        printf("[2] Listar Entradas\n");
        printf("[3] Ler Entrada\n");
        printf("[4] Deletar Entrada\n");
        printf("[5] Deletar Tudo\n");
        printf("[6] Criptografar Entradas\n");
        printf("[7] Descriptografar Entradas\n");
        printf("[8] Fechar\n");

        printf(">> ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                NewEntry();
                break;

            case 2:
                ListEntries();

            case 3:
                ReadEntry();
                break;

            case 4:
                DeleteEntry();
                break;

            case 5:
                DeleteAll();
                break;

            case 6:
                Cripto();
                break;

            case 7:
                Uncripto();
                break;

            case 8:
                Close();
                open = false;
                break;

            default:
                printf("Essa nao e uma opcao valida...");
                break;
        }
    }
}

void NewEntry()
{
    char  codigo;
    char fileName[fieldSize];
    char date[fieldSize];
    char body[fieldSize];
    char fileID[fieldSize];

    lastId += 1;
    sprintf(fileID, "%d", lastId);
    strcat(fileID, ".txt");


    if(entry = fopen(fileID, "wt"))
    {
        fprintf(entry, "%d\n", lastId);

        printf("Otima escolha, %s, então, qual será o nome dessa nova entrada?\n>>", name);
        fflush(stdin);
        fgets(fileName, fieldSize, stdin);
        fputs(fileName, entry);

        printf("Qual a data dessa entrada? Coloque na formatacao dd/mm/aa\n >>");
        fflush(stdin);
        fgets(date, fieldSize, stdin);
        fputs(date, entry);

        printf("Agora basta escrever sua mensagem (não se esqueça de colocar '-' quando acabar):\n");

        codigo=' ';
        while (codigo != '-')
      	{
            fgets(body,fieldSize,stdin);
            fputs(body, entry);
            codigo=body[0];
        }
        fclose(entry);

        WriteInfoFile();
    }
    else
    {
        printf("Parece que um erro ocorreu...");
        exit(1);
    }
}

bool ListEntries()
{
    FILE *currentFile;
    char currentName[fieldSize];
    char currentDate[fieldSize];

    printf("- - - - Aqui estao suas Entradas ate agora: - - - -\n");

    for(int i = 0; i <= lastId; i++)
    {
        printf("INDEX:");
        //passar i para string primeiro
        printf("%s", strcat(i, ".txt"));


        if(currentFile = fopen(strcat(i, ".txt"), "r"))
        {
            for(int n = 0; n < 3; n++)
            {
                switch(n)
                {
                    case 1:
                        fgets(currentName, fieldSize, currentFile);
                        break;

                    case 2:
                        fgets(currentDate, fieldSize, currentFile);
                        break;
                }
            }

            printf("[%d] - %s (%s)\n", i, currentName, currentDate);

        }
        else
        {
            printf("Parece que teve um problema ao abrir o arquivo no index: %d", i);
        }
    }
}

bool ReadEntry()
{

}

bool DeleteEntry()
{

}

bool DeleteAll()
{

}

bool Cripto()
{

}

bool Uncripto()
{

}

void Close()
{
    printf("-- Foi muito bom falar com voce, %s! =D --", name);
    exit(0);
}

void WriteInfoFile()
{
    if(fp = fopen(InfoFile, "wt"))
    {
        fprintf(fp, "%s\n", name);
        fprintf(fp, "%d\n", pronoun);
        fprintf(fp, "%d\n", lastId);
        fclose(fp);
    }
    else
    {
        printf("Parece que algum errou ocorreu ao tentar criar o arquivo...\n");
    }
}
