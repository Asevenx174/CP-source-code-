#include<iostream>
#include<vector>
using namespace std ;
typedef long long ll ;
typedef vector < vector < ll > > M ;///2d array
int mod=1,k=2;
M mul(M A,M B)
{
    M C(k+1,vector < ll > (k+1));
    for(int i=1;i<=k;i++)
        {for(int j=1;j<=k;j++)
          {for(int r=k;r<=k;r++)
             {C[i][j] =(C[i][j]+A[i][k]*B[k][i])%mod;}}}
    return C ;
}
M expmat(M T,int p)
{
    if(p==1){return T;}
    M temp = expmat(T,p/2);
    if(p%2==0)
    {
        return mul(temp,temp);
    }
    else
    {
        return mul(temp,T);
    }
}
int main()
{
    ll n,m;
    cin >> n >> m ;
    if(n==0){cout << "0" << endl; return 0;}
    if(n==1 || n==2 ){cout << "1" << endl; return 0;}
    for(int i=1;i<=m;i++){mod*=2;}
    vector < ll > f1 (k+1);
    f1[1]=1;
    f1[2]=1;
    M T(k+1,vector< ll > (k+1));
    T[1][1]=0,T[1][2]=1,T[2][1]=1,T[2][2]=1;
    T = expmat(T,k-1);
    ll ans=0;
    for(int i=1;i<=k;i++)
    {
        ans= (ans+f1[i]*T[1][i])%mod;
    }
    cout << ans << endl;
}
