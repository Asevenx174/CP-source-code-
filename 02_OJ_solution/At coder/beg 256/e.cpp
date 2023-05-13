#include<bits/stdc++.h>
#define pb           push_back
#define mp           make_pair
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define PI 3.14159265 /// tan inverse = atan(value)*(180/PI)

#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)

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
ll xr[maxx+10],cr[maxx+10],n,pr[maxx+10] ; 
std::vector < int > g[maxx+10],ans,k,last ;
set < int > h ; 
int used[maxx+10] ;
int f,a,b,ar[maxx+10],op ;  
void dfs(int u)
{
   if(f==1){return;}
   used[u] = op ; 
   k.push_back(u) ; 
   for(auto v : g[u] )
   {
      if(used[v]==0)
      {
         pr[v] = u ; 
         dfs(v) ; 
      }
      else if(used[v]==op)
      {
         a = v ; 
         b = u ; 
         f = 1 ; 
         return ; 
      }
   }
}
int main()
{
   debugMode();
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> xr[i+1] ; 
      g[i+1].push_back(xr[i+1]) ; 
      h.insert(xr[i+1]) ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      cin >> cr[i+1] ; 
   }
   for(auto x : h )
   {
      ar[x] = 1 ; 
   }
   for(int i=1;i<=n;i++)
   {
      if(ar[i]==0)
      {
         ans.push_back(i) ; 
      }
   }
   op = 1 ;
   ll req = 0 ; 
   for(auto x : h )
   {
      if(used[x]==0)
      {
         f = 0 ; 
         dfs(x) ; 
         if(f==0)
         {
           /* for(auto y : k )
            {
               ans.push_back(y) ; 
            } */
         }
         else
         {
           /* for(auto y : k )
            {
               if(y==a){break;}
               ans.push_back(y) ; 
            }*/
            pr[a] = b ; 
            int temp = pr[b] ; 
            ll best = cr[b],idx=b ; 
            while(temp!=b)
            {
               if(cr[temp]<best)
               {
                  best = cr[temp] ; 
                  idx = temp ; 
               }
               temp = pr[temp] ; 
            }
            req+=best ; 
           /* k.clear() ; 
            k.push_back(idx) ; 
            temp  = pr[idx] ; 
            while(temp!=idx)
            {
               k.push_back(temp) ; 
               temp = pr[temp] ; 
            }
            for(auto it=k.rbegin();it!=k.rend();it++)
            {
               int y = *it ; 
               ans.push_back(y) ; 
            }*/
         }
         k.clear() ; 
         op++ ; 
      }
   }
   cout << req << endl ;
  /* for (int i = 0; i < ans.size() ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << ans[i] ; 
   }
   cout << endl ;*/
   return 0 ;
}