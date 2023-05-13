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
int ur[maxx+10],uc[maxx+10],lr[maxx+10],rr[maxx+10],s[maxx+10] ; 
int main()
{
   debugMode();
   ios::sync_with_stdio(0); cin.tie(0); 
   int test,pos=1 ;
   cin >> test ;
   while(test--)
   {
      std::vector < int > r,c ;
      std::vector < pii > v ;
      int n,m,k,q ; 
      cin >> n >> m >> k >> q ; 
      //memset(ur,0,sizeof(ur)) ; 
      //memset(uc,0,sizeof(uc)) ;
      for (int i = 0; i < q ; ++i)
      {
         int x,y ;
         cin >> x >> y ; 
         v.push_back({x,y}) ; 
      }
      int idx = q ; 
      while(idx>0)
      {
         pii p = v[idx-1] ;  
         int x = p.ff ; 
         int y = p.ss ; 
         if(lr[x]!=pos)
         {
            ur[x] = idx ;
            lr[x] = pos ;  
         }
         if(rr[y]!=pos)
         {
            uc[y] = idx ;
            rr[y] = pos ;  
         }
         idx-- ; 
      }
      int ro=mod,co=mod;
      for(int i=1;i<=n;i++)
      {
         if(lr[i]==pos){r.push_back(ur[i]);ro=min(ro,ur[i]);}
      }
      for(int i=1;i<=m;i++)
      {
         if(rr[i]==pos){c.push_back(uc[i]);co=min(co,uc[i]);}
      }
      //sort(r.begin(),r.end()) ;
      //sort(c.begin(),c.end()) ;
      ll d = 0 ;  
      for(auto x : c )
      {
         if(s[x]==pos){continue;}
         if(r.size()!=n){s[x]=pos;d++;continue;}
         if(x>=ro){s[x]=pos;d++;} 
      }
      for(auto x : r )
      {
         if(s[x]==pos){continue;}
         if(c.size()!=m){s[x]=pos;d++;continue;}
         if(x>=co){s[x]=pos;d++;} 
      }
      ll ans = fastpow(k,d) ; 
      cout << ans << endl ; 
      pos++ ; 
   }
   return 0 ;
}