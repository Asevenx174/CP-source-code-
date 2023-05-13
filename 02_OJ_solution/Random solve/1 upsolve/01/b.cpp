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
const ll maxx = 200+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
string s ; 
int n,pr[maxx+10] ;
std::vector < int > g[maxx+10] ;
bool used[maxx+10] ; 
string temp = "" ;
void dfs(int u)
{
   temp+=s[u] ; 
   used[u] = true ; 
   for(auto v : g[u])
   {
      if(used[v]){continue;}
      dfs(v) ; 
   }
}
string shift(string a)
{
   if(a.size()==1){return a;}
   string b = "" ; 
   for (int i = 1 ; i < a.size() ; ++i)
   {
      b+=a[i] ; 
   }
   b+=a[0] ; 
   return b ; 
}
ll lcm(ll a,ll b)
{
   ll ans = a*b ; 
   ll gk = __gcd(a,b) ; 
   ans = ans/gk  ;
   return ans ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ll res = 1 ; 
      for (int i = 0; i < maxx ; ++i)
      {
         used[i] = false ; 
         g[i].clear() ; 
      }
      cin >> n ;
      cin >> s ; 
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ;
         pr[i] = x-1 ; 
         g[i].push_back(pr[i]) ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         if(!used[i])
         {
            temp = "" ; 
            dfs(i) ; 
            string f = temp ; 
            ll op = 1 ; 
            while(1)
            {
               string k = shift(temp) ; 
               if(k==f){break;}
               temp = k ;
               op++ ;  
            }
            res = lcm(res,op) ; 
         }
      }
      cout << res << endl ; 
   }
   return 0 ;
}