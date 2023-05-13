#include<stdio.h>
#include<string.h>
int main()
{
    char vajjo[1000];// jake vag kra hbe
    long long vajok,vagshesh=0,i,n ; // vajok jake dia vag kra hbe
    // vajok cant be greater than 10^18
    gets(vajjo);
    scanf("%lld",&vajok);
    n=strlen(vajjo);
    // char to int , just - '0'
    // char 0 ascii er value 48 , char 5 er 53
    // so ascii value er diff theke int number ber krte pari
    // 5 = '5'-'0'
    for(i=0; i<n; i++)
    {
        vagshesh=((vagshesh*10)+(vajjo[i]-'0'))%vajok ;
    }
    printf("%lld\n",vagshesh);
    return 0;
}
