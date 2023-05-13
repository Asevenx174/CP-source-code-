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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      priority_queue < ll > v[5] ;
      ll n,f=1 ;
      cin >> n ;
      for(int i=1;i<=n;i++)
      {
         ll x ;
         cin >> x ;
         ar[i] = x ; 
         if(i==1 || i==n){continue;}
         if(x!=1LL){f=0;}
         v[x%2LL].push(x) ; 
      }
      if(n==3LL && ar[2]%2LL==1LL){f=1;}
      if(f){cout << "-1" << endl ; continue ;}
      ll ans = 0 ; 
      if(v[0].size()==0LL)
      {
         ll x = v[1].top() ;
         v[1].pop() ;  
         ll y = v[1].top() ; 
         v[1].pop() ; 
         x-- ; 
         y-- ; 
         if(x>0ll){v[0].push(x);} ; 
         if(y>0ll){v[0].push(y);} ;
         ans+=2LL ; 
      }
      while(!v[1].empty())
      {
         ll o = v[1].top() ; v[1].pop() ; 
         ll e = v[0].top() ; v[0].pop() ;
         e-=2 ; 
         o++ ;
         if(e>0ll)
         {
            v[0].push(e) ; 
         } 
         v[0].push(o) ; 
         ans++ ; 
      }
      while(!v[0].empty())
      {
         ans+=(v[0].top()/2LL) ;
         v[0].pop() ; 
      }
      cout << ans << endl ;
   }
   return 0 ;
}