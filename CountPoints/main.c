#include<stdio.h>

#define maxSize 100

typedef struct Point{
  int x;
  int y;
} Point;

int main()
{
	int i, j, n;
	int qtdeTotP = 0;
	Point points[maxSize];
	Point diffP[maxSize];


	//while(scanf("%d", &points[i].x) != EOF)
	while(points[i-1].x != -1)
	{
	    scanf("%d", &points[i].x);
		scanf("%d", &points[i].y);

		qtdeTotP = ++i;
	}

	for( i = 0; i < qtdeTotP; i++)
    {
        for( j = 0; j < n; j++ )
        {
            if( points[i].x == diffP[j].x && points[i].y == diffP[j].y)
                break;
        }

        if( j == n )
        {
            diffP[n] = points[i];
            n++;
        }
    }

	for( i = 0; i < n; i++ )
        printf("%d %d\n", diffP[i].x,  diffP[i].y);
    printf("\n");

    printf("%d", n);
}
