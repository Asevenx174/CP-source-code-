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
const ll maxx = 2e5+10,mod=998244353,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll fastpow(ll a, ll p)
{
    ll res = 1;
    while (p)
    {
        if (p % 2 == 0)
        {
            a = (a * a) % mod;
            p /= 2;
        } 
        else 
        {
            res = (res * a) % mod;
            p--;
        }
    }
    return res ;
}
int ur[maxx+10],uc[maxx+10] ; 
bool used[maxx+10] ; 
int main()
{
   debugMode();
   //ios::sync_with_stdio(0); cin.tie(0); 
   int test ;
   cin >> test ;
   while(test--)
   {
      std::vector < int > r,c ;
      std::vector < pii > v ;
      int n,m,k,q ; 
      //cin >> n >> m >> k >> q ; 
      scanf("%d %d %d %d",&n,&m,&k,&q) ; 
      memset(ur,0,sizeof(ur)) ; 
      memset(uc,0,sizeof(uc)) ;
      memset(used,false,sizeof(used)) ; 
      for (int i = 0; i < q ; ++i)
      {
         int x,y ;
         scanf("%d %d",&x,&y) ; 
         v.push_back({x,y}) ; 
      }
      int idx = q ; 
      while(idx>0)
      {
         pii p = v[idx-1] ; 
         int x = p.ff ; 
         int y = p.ss ; 
         if(ur[x]==0)
         {
            ur[x] = idx ; 
         }
         if(uc[y]==0)
         {
            uc[y] = idx ; 
         }
         idx-- ; 
      }
      for(int i=1;i<=n;i++)
      {
         if(ur[i]!=0){r.push_back(ur[i]);}
      }
      for(int i=1;i<=m;i++)
      {
         if(uc[i]!=0){c.push_back(uc[i]);}
      }
      sort(r.begin(),r.end()) ;
      sort(c.begin(),c.end()) ;
      for(auto x : c )
      {
         if(r.size()!=n){used[x]=true;continue;}
         if(x>=r[0]){used[x]=true;} 
      }
      for(auto x : r )
      {
         if(c.size()!=m){used[x]=true;continue;}
         if(x>=c[0]){used[x]=true;} 
      }
      ll d = 0 ; 
      for (int i = 0; i < maxx ; ++i)
      {
         if(used[i]){d++;}
      }
      ll ans = fastpow(k,d) ; 
      cout << ans << endl ; 
   }
   return 0 ;
}