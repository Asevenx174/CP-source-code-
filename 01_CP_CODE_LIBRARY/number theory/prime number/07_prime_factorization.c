#include<stdio.h>
int main()
{
// 1st seive of era use kre prime number gula ber kre ekta array create krb0
// 28 er prime fact 2*2*7
    int array[6]= {2,3,5,7,11,13};
    int n=12,i;
    for(i=0; i<5; i++)
    {
        while(n%array[i]==0 ) // 12%2==0 then 2 print hoilo
        {
            // 6%2==0 ......
            n/=array[i];      // 3%3==0 then 3 print hoilo
            printf("%d ",array[i]);
        }
        if(n==1)
        {
            break;
        }
    }
    return 0;
}
