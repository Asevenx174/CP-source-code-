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
ll ar[maxx+10],n  ;  
std::vector < pii > v[maxx+10] ;
ll calco()
{
   int l=1 ; 
   set < ll > s ; 
   while(l<=n)
   {
      int r = l ; 
      while(r+1<=n && ar[l]==ar[r+1])
      {
         r++ ; 
      }
      int val = ar[l]  ;
      int f = r-l+1 ; 
      v[ val ].push_back({l,r}) ; 
      s.insert(ar[l]) ; 
      //cout << l << " " << r << endl ;
      l = r+1 ; 
   }

   int dis = s.size() ; 
   vector <  vector < int > > g ; 
   g.resize(dis+5) ; 
   int idx = 0 ; 
   ll ans = 0 ; 
   for(auto x : s )
   {
      idx++ ; 
      int siz = v[x].size() ; 
      g[idx].resize(siz+5);
      int k = 0 ; 
      auto it = v[x].begin() ; 
      pii p = *it ; 
      g[idx][++k] = p.ss-p.ff+1 ; 
      it++ ; 
      while(it!=v[x].end())
      {
         pii q = *it ; 
         g[idx][++k] = -(q.ff-p.ss-1) ; 
         g[idx][++k] = q.ss-q.ff+1 ;  
         it++ ; 
         p = q ; 
      }
      // x -> g[idx][1]....g[idx][k] 
      ll pre = 0 , best = 0 ; 
      int l=0,r=0,pos ; 
      for(int i=1;i<=k;i++)
      {
        ll temp = pre+g[idx][i] ; 
        if(i%2==1)
        { 
           ans = max(ans,temp-best) ;   
        }
        pre+=g[idx][i] ; 
        best = min(best,pre) ; 
      }
      ll suf = 0 ; 
      best = 0  ;
      while(k>0)
      {
         ll temp = suf+g[idx][k] ; 
         if(k%2==1)
         {
             ans = max(ans,temp-best) ; 
         }
         suf+=g[idx][k] ; 
         best = min(best,suf) ; 
         k-- ; 
      }
   }
   return ans ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      for (int i = 0; i < maxx ; ++i)
      {
         v[i].clear() ; 
      }
      cin >> n ;
      set < int > s ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         s.insert(ar[i+1]) ; 
      }
      map < int ,int > pq ; 
      int idx = 1 ; 
      for(auto x : s )
      {
         pq[x] = idx++ ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         ar[i+1] = pq[ ar[i+1] ] ; 
      }
      cout << calco() << endl ; 
   }
   return 0 ;
}