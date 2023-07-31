#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


int main()
{
    char *oldWord = GetSentence();
    char *newWord = GetSentence();
    char *sentence = GetSentence();
    char *newSentence;

    int i,j;
    int lastIndex = 0;
    int isWord;
    int newSize = strlen(sentence) + (strlen(newWord) - strlen(oldWord));

    newSentence = (char*)calloc(newSize, sizeof(char*));

    //////////////////////////////////////////////////// ANDA POR TODA A STRING ANTIGA
    for(i = 0; i < strlen(sentence); i++)
    {
        ////////////////////////////// SE O CARACTERE FOR != DO 1° DA PALAVRA VELHA, SO COPIA
        if(sentence[i] != oldWord[0])
        {
            newSentence[lastIndex] = sentence[i];
            lastIndex++;
        }
        else
        {
            isWord = 1;

            ///////////////////////////////////////// CHECANDO SE E A MESMA PALAVRA
            for(j = 0; j < strlen(oldWord); j++)
            {
                if(sentence[j+i] != oldWord[j]) ///// CASO ENCONTRE ALGUM CARACTERE DIFERENTE, N E
                {
                    isWord = 0;
                    break;
                }
            }

            if(isWord) ////////////////////////////////// SE FOR MESMA PALAVRA
            {
                for(j = 0; j < strlen(newWord); j++) //// COPIA NO LUGAR A NOVA PALAVRA
                {
                    newSentence[lastIndex] = newWord[j];
                    lastIndex++;
                }

                i += strlen(oldWord) - 1;
            }
            else //////////////////////////////////////// SE N FOR COPIA O CARACTERE IGUAL E CONTINUA
            {
                newSentence[lastIndex] = sentence[i];
                lastIndex++;
            }
        }

    }

    printf("%s", newSentence);

    return 0;
}
