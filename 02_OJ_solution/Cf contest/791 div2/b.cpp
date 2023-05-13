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
ll ar[maxx+10],n,q,f[maxx+10] ; 
int main()
{
   debugMode();
   std::vector< pair < int , pii > > pq ;
   cin >> n >> q ; 
   ll sum = 0 ; 
   lp(i,1,n)
   {
      cin >> ar[i] ; 
      sum+=ar[i] ; 
   }
   ll last = 0 ; 
   lp(i,1,q)
   {
      ll t,idx=0,x ; 
      cin >> t ; 
      if(t==1)
      {
         cin >> idx >> x ; 
      }
      else
      {
         last = i ; 
         cin >> x ; 
      }
      pq.push_back({t,{idx,x}}) ; 
   }
   ll co = 0 ,slap = 0 ; 
   for(auto x : pq )
   {
      ll t = x.ff ; 
      pii p = x.ss ; 
      ll idx = p.ff ;
      ll val = p.ss ; 
      if(t==2)
      {
         co++ ; 
         sum = val*n ; 
         slap = val  ; 
      }
      else
      {
         if(f[idx]<co)
         {
            ar[idx] = slap ; 
            f[idx] = co ;  
         }
         ll add = val-ar[idx] ; 
         ar[idx] = val ; 
         sum+=add ; 
      }
      cout << sum << endl ;
   }
    
   return 0 ;
}