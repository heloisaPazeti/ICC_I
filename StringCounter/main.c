#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *sentence = (char*)calloc(1, sizeof(char));
    char c;
    int i, size = 0;

    while((c = getchar()) != '\n' && c != EOF)
    {
        if(size > 0)
            sentence = (char*)realloc(sentence, size+1);

        sentence[size] = c;
        size++;
    }

    //sentence = (char*)realloc(sentence, size+1);
    //sentence[size+1] = '\0';

    for(i = 0; i < size; i++)
        printf("%c", sentence[i]);

    printf("\n");
    printf("%d", size);

    free(sentence);
}
