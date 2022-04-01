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
    ptr = &vt[0];
    //printf("\n%d\n\n", ptr);
    //printf("%d\n\n", *(vt));
    //printf("\n%d", *(vt+i));
    printf("\n");
    
    for(i = 0;i<N; i++)
    {
        printf("%f / ", &ptr);
        ptr++;
    }

    printf("\n\n\n");
    for(i = 0;i<N; i++)
    {
        vt[i]=1+rand()%100;
        printf("%f / ", vt[i]);
    }

    return 0;
}
