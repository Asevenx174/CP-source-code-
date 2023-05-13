#include<bits\stdc++.h>
#define max 9999999
using namespace std ;
int prime[max];
vector < int > v ;
void seive(int n)
{
    memset(prime,0,sizeof(prime));
    int x = sqrt(n);
    prime[0]=prime[1]=1;
    for(int i=4; i<=n; i+=2)
    {
        prime[i]=1;
    }
    for(int i=3; i<=x; i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<=n; j+=i)
            {
                prime[j]=1;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(prime[i]==0)
        {
            v.push_back(i);
        }
    }
}
int main()
{
    int n ;
    cin >> n ;
    seive(n);
    for(int i=0;i<v.size();i++)
    {
       while(n%v[i]==0)
       {
           n/=v[i];
           cout <<v[i] << " " ;
       }
       if(n==1)/// must be compound number
       {
           break;
       }
    }
    return 0;
}
