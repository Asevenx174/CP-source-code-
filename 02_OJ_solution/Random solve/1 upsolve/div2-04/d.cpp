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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,q,ar[maxx+10] ; 
std::vector < pii > pq[maxx+10] ;
bool used[maxx+10][40] ; 
int main()
{
   debugMode();
   ll vo = (qq << 32LL)-1ll ; 
   std:: vector < ll > com(maxx,vo) ;
   cin >> n >> q ;
   for (int i = 0; i < q ; ++i)
   {
      ll a,b,x ;
      cin >> a >> b >> x ; 
      if(a>b){swap(a,b);}
      pq[a].push_back({b,x}) ; 
      ar[a] = ar[a]|x ; 
      ar[b] = ar[b]|x ; 
      com[a] = com[a]&x ; 
      com[b] = com[b]&x ; 
      if(a==b)
      {
         ll idx = 0 ;
         while(idx<=30)
         {
            ll temp = qq << idx ; 
            if(x&temp)
            {
               used[a][idx] = true ; 
            }
            idx++ ; 
         }
      }
   }
  
   for(ll i=1;i<=n;i++)
   {
      if(pq[i].size()==0){continue;}
      ll x = ar[i] ; 
      ll idx = 30 ; 
      while(idx>=0)
      {
         ll temp = qq << idx ; 
         if(x&temp && !used[i][idx])
         {
            vector < pii > sett ; 
            ll f = 1 ; 
            for(auto p : pq[i])
            {
               ll j = p.ff ; 
               if(!used[j][idx] && (com[j]&temp)!=0 )
               {
                  sett.push_back({j,idx}) ;  
               }
               else{f=0;}
            }
            if(f==1)
            {
               temp = !temp ; 
               ar[i] = ar[i]&temp ; 
               for(auto p : sett )
               {
                  used[p.ff][p.ss]=true ;
               }
            }
         }
         idx-- ;
      }
   }
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << ar[i+1] ; 
   }
   cout << endl ;
   return 0 ;
}