#include<stdio.h>
int main()
{
    // i was told to output the value of !100%97
    // we know (a*b)%m=((a%m)*(b%m))%m
    // at 1st iteration fact store the value of 1%97
    // 2nd itera fact store the value of (1*2)%97
    // 3rd ... (1*2*3)%97
    int n=100,i,j,fact=1;
    for(i=1; i<=100; i++)
    {
        fact=((fact%97)*(i%97))%97 ;
    }
    printf("%d",fact);
    return 0 ;
}
