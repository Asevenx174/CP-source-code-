#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std ;
typedef long long ll ;
const int k = 6 ;
vector < ll > F(k+1),G(k+1);
ll a1,a2,b1,b2,c1,c2,mod,ans1,ans2;
typedef vector < vector < ll > > matrix ;
matrix mul(matrix A,matrix B)
{
    matrix   C (k+1,vector < ll > (k+1)) ;
    rep(i,k)
    {
        rep(j,k)
        {    C[i][j]=0;
            rep(r,k)
            {
                C[i][j]=(C[i][j]+A[i][r]*B[r][j])%mod;
            }
        }
    }
    return C ;
}
matrix power(matrix A,ll n)
{
    if(n==1){return A;}
    if(n%2){return mul(A,power(A,n-1));}
    matrix x = power(A,n/2);
    return mul(x,x);
}
void fib(ll n)
{
    if(n<=2){ ans1=F[n]%mod; ans2=G[n]%mod ;return ;}
    matrix T (k+1,vector<ll>(k+1));
    T[0][0]=a1;T[0][1]=b1;T[0][2]=0;T[0][3]=0;T[0][4]=0;T[0][5]=c1;
    T[1][0]=1;T[1][1]=0;T[1][2]=0;T[1][3]=0;T[1][4]=0;T[1][5]=0;
    T[2][0]=0;T[2][1]=1;T[2][2]=0;T[2][3]=0;T[2][4]=0;T[2][5]=0;
    T[3][0]=0;T[3][1]=0;T[3][2]=c2;T[3][3]=a2;T[3][4]=b2;T[3][5]=0;
    T[4][0]=0;T[4][1]=0;T[4][2]=0;T[4][3]=1;T[4][4]=0;T[4][5]=0;
    T[5][0]=0;T[5][1]=0;T[5][2]=0;T[5][3]=0;T[5][4]=1;T[5][5]=0;
    T = power(T,n-2);
    ll e=2,r=2;
    rep(i,k)
    {
        if(i<=2)
        {ans1 = (ans1 + T[0][i]*F[e--])%mod;}
        else{ans1 = (ans1 + T[0][i]*G[r--])%mod;}
    }
    e=2,r=2;
    rep(i,k)
    {
        if(i<=2)
        {ans2 = (ans2 + T[3][i]*F[e--])%mod;}
        else{ans2 = (ans2 + T[3][i]*G[r--])%mod;}
    }
    return ;
}
int main()
{
     ll x,test,q;
     cin >> test ;
     rep(l,test)
     {
      cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 ;
     cin >> x ; F[0]=x;
     cin >> x ; F[1]=x;
     cin >> x ; F[2]=x;
     cin >> x ; G[0]=x;
     cin >> x ; G[1]=x;
     cin >> x ; G[2]=x;
     cin >> mod ;
     cin >>  q ;
     cout << "Case " << l+1 << ":" << endl;
     rep(i,q)
     {
         ans1=0,ans2=0;
         ll n ;
         cin >> n ;
        fib(n);
        cout << ans1 << " " << ans2 << endl;
     }}
    return 0;
}
