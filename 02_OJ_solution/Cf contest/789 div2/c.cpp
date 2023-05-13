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
int main()
{
   debugMode();
   map < int , set < int > > pq ; 
   set < int > s ; 
   int n ;
   cin >> n ;
   lp(i,1,n)
   {
      int x,y ;
      cin >> x >> y ;
      pq[x].insert(y) ; 
      s.insert(x) ; 
   }
   int  ans = n ; 
   for(auto i : s )
   {
      if(pq[i+1].size()==0){continue;}
      int p = mod ; 
      for(auto x : pq[i] )
      {
         if(p!=mod && p+1==x)
         {
            auto it = pq[i+1].find(p);
            auto lt = pq[i+1].find(p+1) ; 
            if(it==pq[i+1].end() && lt!=pq[i+1].end())
            {
               // p+1 
               cout << i+1 << " " << p << endl ;
               pq[i+1].insert(p) ; 
               ans++ ; 
            }
            else if( it!=pq[i+1].end() && lt==pq[i+1].end() )
            { 
               // p 
               cout << i+1 << " " << p+1 << endl ;
               pq[i+1].insert(p+1) ; 
               ans++ ; 
            }
         }
         p = x ; 
      }  
   }
   cout << ans << endl ;
   return 0 ;
}