#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define N 5
#define M 7
int main()
{
    int i,j;
    int mt[N][M];
    srand((int)time(NULL));
    printf("\n");
    printf("\n");
    for(i = 0;i<N; i++)
    {
        for(j = 0;j<M; j++)
        {
            mt[i][j]=1+rand()%100;
            printf("%ld ", mt[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    return 0;
}

