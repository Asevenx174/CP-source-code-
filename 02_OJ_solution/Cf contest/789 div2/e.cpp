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
struct com {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        if(a.ss==b.ss)
        {
          return a.ff > b.ff ; 
        }
        return a.second > b.second;
    }
};

int main()
{
   debugMode();
   map < int , set < int > > s ; 
   priority_queue < pii , vector < pii> , com > pq ; 
   int n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      int x,y ;
      cin >> x >> y ; 
      pq.push({x,y}) ; 
      s[x].insert(y) ; 
   }
   int ans = n ; 
   while(!pq.empty())
   {
      pii p  = pq.top() ; pq.pop() ; 
      if(pq.empty()){break;}
      pii q  = pq.top() ; 
      if(p.ss==q.ss && p.ff+1==q.ff)
      {
         // cout << p.ff << " " << p.ss << endl ; 
          //cout << q.ff << " " << q.ss << endl ; 

          auto it = s[p.ff].find(p.ss+1);
          auto lt = s[q.ff].find(p.ss+1) ; 
          //cout << *it << " " << *lt << endl ;
          if(it==s[p.ff].end() && lt!=s[q.ff].end())
          {
             // q.ff a p.ss+1 
             ans++ ; 
             // p.ff p.ss+1 
             int l = p.ff , r = p.ss+1 ; 
             pq.push({l,r}) ; 
             s[l].insert(r) ; 
             cout << l << " " << r << endl ;
          }
          else if(it!=s[p.ff].end() && lt==s[q.ff].end()) 
          {
             ans++ ; 
             int l = q.ff , r = p.ss+1 ; 
             pq.push({l,r}) ; 
             s[l].insert(r) ; 
             cout << l << " " << r << endl ;
          }
      }
   }
   cout << ans << endl ;
   return 0 ;
}