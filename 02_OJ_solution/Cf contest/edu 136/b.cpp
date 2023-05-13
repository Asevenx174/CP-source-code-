#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n,ar[maxx+10],dr[maxx+10],co ; 
std::vector < int > v ;
bool dp[10010][110] ; 
void calco2(int a,int idx)
{
    if(dp[a][idx]){return;}
    if(idx>n){co++;return;}
    int b = dr[idx]+a ; 
    if(b>=0)
    {
      calco2(b,idx+1) ; 
    }
    int y = a-dr[idx] ; 
    if(y>=0 && y!=b)
    {
      calco2(y,idx+1) ; 
    }
    dp[a][idx] = true ; 
}
int flag = 0 ;
void calco(int a,int idx)
{
    if(dp[a][idx]){return;}
    if(flag==1){return ;}
    if(idx>n){ flag=1; return;}
    int b = dr[idx]+a ; 
    if(b>=0)
    {
      v.push_back(b) ; 
      calco(b,idx+1) ; 
      if(flag){return;}
      v.pop_back() ; 
    }
    int y = a-dr[idx] ; 
    if(y>=0 && y!=b)
    {
      v.push_back(y) ;
      calco(y,idx+1) ; 
      if(flag){return;}
      v.pop_back() ; 
    }
    dp[a][idx] = true ;
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      v.clear() ; 
      flag = 0 ; 
      co = 0 ; 
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> dr[i+1] ; 
      }
      memset(dp,false,sizeof(dp)) ; 
      ar[1] = dr[1] ; 
      calco2(ar[1],2) ; 
      if(co!=1){cout << "-1" << endl ; continue ;}
      v.push_back(ar[1]) ; 
      memset(dp,false,sizeof(dp)) ;
      calco(ar[1],2) ;
      for (int i = 0; i < n ; ++i)
      {
         if(i>0){cout << " " ;}
         cout << v[i] ; 
      }
      cout << endl ;
   }
   return 0 ;
}