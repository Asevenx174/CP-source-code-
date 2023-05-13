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
int ar[maxx+10],n,f[maxx+10] ; 
vector < int > v ; 
bool valid(int g)
{
   int idx = 0 ; 
   std::vector < int > br(n+5,0) ;
   for( auto x : v )
   {
      f[x] = ar[x] ; 
   }

   for(int i=1;i<=n;i++)
   {
      if(br[i]==0)
      {
          if(idx==v.size()){return false;}
          br[i] = v[idx++] ;
          f[ br[i] ] -- ;   
      }
      
      if( f[ br[i] ] > 0 )
      {
         if( (i+g+1)>n ) { return false ; }
         br[i+g+1] = br[i] ; 
         f[ br[i] ] -- ; 
      }
   }  
   return true ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      v.clear() ; 
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         ar[i+1] = 0 ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ;
         ar[x] ++ ; 
      }
      std::vector < pii > pq ; 
      for(int i=1;i<=n;i++)
      {
         if(ar[i]==0){continue;}
         pq.push_back({ar[i],i}) ; 
      }
      sort(pq.begin(),pq.end(),greater<pii>()) ; 
      for(auto p : pq )
      {
         v.push_back(p.ss) ; 
      }
      int l=0,r=n,ans=0 ; 
      while(l<=r)
      {
         int m = (l+r)/2 ;
         if(valid(m))
         {
            ans = m ; 
            l = m+1 ; 
         }
         else
         {
            r = m-1 ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}