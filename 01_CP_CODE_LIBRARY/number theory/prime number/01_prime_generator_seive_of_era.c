// can generate prime within a given range
// can generate prime factors of number
// why rooot ??
// 32 er bivajok 1,2,4 abar 32 k 1,2,4 dhara vag dile pai 32,16,8
// here 4 cant be larger then root n
//16=4*4 here a=b
int array[1000005];// initially shob 0 krlam mane 0 to n shobai prime
#include<stdio.h>
#include<math.h>
int main()
{
    int n=100,i,j,s;
    s=sqrt(n);// root n prjonto loop chalalei cholbe
    array[0]=1;
    array[1]=1;// 0,1 prime na
    for(i=4;i<=n;i=i+2)
    {
        array[i]=1;// 2 baade shob even not prime
    }
    for(i=3;i<=s;i=i+2)
    {
        if(array[i]==0)// 3 jdi prime hoy then tar gunitok shob non prime
        {
            for(j=i*i;j<=n;j=j+i)
            {
                array[j]=1;
            }
        }
    }
    for(i=0;i<=n;i++)
    {
        if(array[i]==0)
        {
            printf("%d\t",i);
        }
    }
    return 0;
}
