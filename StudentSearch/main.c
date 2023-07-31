#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//#define size 1000

typedef struct Aluno
{
    int nMatric;
    char *nome;
    char *codCurso;
    char *cpf;
    char *idade;

} Aluno;

char* GetSentence();
void Cadastrar();
void Buscar();
void PrintarAlunos();
void Sair();

Aluno *alunos;
int lastMatric = 0;

int main()
{
    int option = 0;
    alunos = malloc(sizeof(Aluno*));

    while(1)
    {
        scanf("%d", &option);

        switch(option)
        {
            case -1:
            {
                Sair();
                break;
            }

            case 1:
            {
                Cadastrar();
                break;
            }

            case 2:
            {
                Buscar();
                break;
            }
        }
    }



    return 0;
}

char* GetSentence()
{
    char *sentence = (char*)calloc(1, sizeof(char));
    char c;
    int size = 0;

    while((c = getchar()) != '\n' && c != EOF)
    {
        if(size > 0)
            sentence = (char*)realloc(sentence, size+1);

        sentence[size] = c;
        size++;
    }

    return sentence;
}

void Cadastrar()
{
    lastMatric++;
    alunos = realloc(alunos, lastMatric*sizeof(Aluno*));

    alunos[lastMatric - 1].nome = GetSentence();
    alunos[lastMatric - 1].codCurso = GetSentence();
    alunos[lastMatric - 1].cpf = GetSentence();
    alunos[lastMatric - 1].idade = GetSentence();
    alunos[lastMatric - 1].nMatric = lastMatric;
}

void Buscar()
{
    int nMatric = 0;
    int founded = 0;

    scanf("%d", &nMatric);

    for(int i = 0; i < lastMatric; i++)
    {
        if(nMatric == alunos[i].nMatric)
        {
            PrintarAlunos(alunos[i]);
            founded = 1;
        }
    }

    if(!founded)
        printf("Aluno nao cadastrado!\n");
}

void PrintarAlunos(Aluno aluno)
{
    printf("Matricula: %d\n", aluno.nMatric);
    printf("Nome: %s", aluno.nome);
    printf("CPF: %s", aluno.cpf);
    printf("Curso: %s", aluno.codCurso);
    printf("Idade: %s\n", aluno.idade);
}

void Sair()
{
    //free(ordemBusca);
    //free(alunosResultados);
    //free(alunos);
    exit(0);
}
