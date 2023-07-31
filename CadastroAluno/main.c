#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int nroMatricula;
	char* nome;
	char* cpf;
	char* codCurso;
	char* idade;
} Aluno;

Aluno *alunos;
int lastMatric;

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

void PrintarAluno(Aluno aluno)
{
    printf("Matricula: %d\n", aluno.nroMatricula);
    printf("Nome: %s\n", aluno.nome);
    printf("CPF: %s\n", aluno.cpf);
    printf("Curso: %s\n", aluno.codCurso);
    printf("Idade: %s\n", aluno.idade);
}

void CadastrarAluno()
{
	lastMatric++;

	alunos = realloc(alunos, lastMatric*sizeof(*alunos));

	alunos[lastMatric - 1].nome = GetSentence();
	alunos[lastMatric - 1].codCurso = GetSentence();
	alunos[lastMatric - 1].cpf = GetSentence();
	alunos[lastMatric - 1].idade = GetSentence();
	alunos[lastMatric - 1].nroMatricula = lastMatric;
}

void BuscarAluno()
{
    int nMatric;
    scanf("%d", &nMatric);

	int founded = 0;
	for(int i = 0; i < lastMatric; i++)
	{
		if(alunos[i].nroMatricula == nMatric)
		{
			founded = 1;
			PrintarAluno(alunos[i]);
		}
	}
	if(!founded)
		printf("Aluno nao cadastrado!\n");
}

void Sair()
{
    free(alunos);
    exit(0);
}

int main()
{
    int option = 0;
	alunos = malloc(sizeof(Aluno*));

	while(1)
	{

		scanf("%d%*c", &option);
        switch(option)
        {
            case -1:
            {
                Sair();
                break;
            }
            case 1:
            {
                CadastrarAluno();
                break;
            }
            case 2:
            {
                BuscarAluno();
                break;
            }

        }
	}

	return 0;
}
