#include<iostream>
#include<stdio.h>
using namespace std ;
typedef long long ll ;
const ll k=2;
ll mod=1;
void mul(ll A[k][k],ll B[k][k])
{
    ll C[k][k];
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {   C[i][j]=0;
            for(int r=0;r<k;r++)
            {
                C[i][j]= (C[i][j]+A[i][r]*B[r][j])%mod;
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            A[i][j]=C[i][j];
        }
    }
}
ll power(ll F[k][k],ll n)
{
    if(n==1){return (F[0][0]+F[0][1])%mod;}
    ll M[k][k]={{1,1},{1,0}};
    power(F,n/2);
    mul(F,F);
    if(n%2==1)
    {
        mul(F,M);
    }
    return (F[0][0]+F[0][1])%mod;
}
ll fib(ll n)
{
    if(n==2 || n==1){return 1;}
    if(n==0){return 0;}
    ll F[k][k]={{1,1},{1,0}};
    return power(F,n-2);
}
int main()
{
    ll n,m;
    while(cin >> n >> m)
    {
    mod = 1 << m ;
    if(mod==1){cout << "0" << endl;continue;}
    cout << fib(n)<< endl;
    }
    return 0;
}
