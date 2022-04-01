#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 20

int main()
{
    double* ptr;
    int i;
    double vt[N];
    srand((int)time(NULL));
    printf("\n");
    
    for(i = 0;i<N; i++)
    {
        vt[i]=1+rand()%100;
        ptr = &vt[i];
        printf("%f / ", *ptr);
    }
    return 0;
}
