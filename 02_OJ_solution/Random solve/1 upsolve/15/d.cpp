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
ll n,m,k,q ; 
int rr[maxx+10],cr[maxx+10],xr[maxx+10],yr[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      set < int > s,r,c ;
      memset(rr,0,sizeof(rr)) ;
      memset(cr,0,sizeof(cr)) ; 
      cin >> n >> m >> k >> q ; 
      for (int i = 0; i < n ; ++i)
      {
         r.insert(i+1) ; 
      }
      for (int i = 0; i < m ; ++i)
      {
         c.insert(i+1) ; 
      }
      for (int i = 0; i < q ; ++i)
      {
         cin >> xr[i+1] >> yr[i+1] ;
      }
      for(int i=q;i>0;i--)
      {
         int x = xr[i] ; 
         int y = yr[i] ;
         auto it = r.find(x) ; 
         auto lt = c.find(y) ;
         if(it!=r.end())
         {
            rr[x] = i ; 
            r.erase(it) ;  
         } 
         if(lt!=c.end())
         {
            cr[y] = i ; 
            c.erase(lt) ;  
         }  
         if(r.empty() || c.empty()){break;}
      }
      if(r.empty())
      {
         int f = 0 ; 
         for (int i = 0; i < n ; ++i)
         {
            if(rr[i+1]!=0){f=i+1;break;}
         }
         while(f--)
         {
            cr[f] = 0 ; 
         }
      }
      if(c.empty())
      {
         int f = 0 ; 
         for (int i = 0; i < m ; ++i)
         {
            if(cr[i+1]!=0){f=i+1;break;}
         }
         while(f--)
         {
            rr[f] = 0 ; 
         }
      }
      for (int i = 0; i < n ; ++i)
      {
         if(rr[i+1]!=0){s.insert(i+1);}
      }
      for (int i = 0; i < m ; ++i)
      {
         if(cr[i+1]!=0){s.insert(i+1);}
      }
      ll dis = s.size() ; 
      ll ans = fastpow(k,dis) ; 
      cout << ans << endl ; 
   }
   return 0 ;
}