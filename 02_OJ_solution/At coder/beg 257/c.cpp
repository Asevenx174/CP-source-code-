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
ll w[maxx+10],n,id[maxx+10],ar[maxx+10] ; 
ll ra[maxx+10],lc[maxx+10],val[maxx+10];
int main()
{
   debugMode();
   cin >> n ; 
   string s ;
   cin >> s ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> w[i+1] ; 
   }
   std::vector < pii > pq ;
   ll idx = 1 ; 
   for(auto c : s )
   {
      ll x = c=='1' ? 1 : 0 ;  
      pq.push_back({w[idx],x}) ; 
      idx++ ; 
   }
   sort(pq.begin(),pq.end()) ; 
   idx = 1 ; 
   vector < ll > v ;
   for(auto p : pq )
   {
      val[idx] = p.ff ; 
      ar[idx++] = p.ss ; 
      //cout << p.ff << " " << p.ss << endl ;
      v.push_back(p.ff) ; 
   }
   ra[n+1] = 0 ; 
   ll sum = 0 ; 
   for(int i=n;i>0;i--)
   {
      sum+=ar[i] ; 
      ra[i] = sum ;
   }
   lc[0] = 0 ; 
   sum = 0 ; 
   for(int i=1;i<=n;i++)
   {
      if(ar[i]==0){sum++;}
      lc[i] = sum ; 
   }
   ll ans = 0 ; 
   for(int i=0;i<=n;i++)
   {
      ll x = val[i] ; 
      auto it = upper_bound(v.begin(),v.end(),x);
      idx = it-v.begin() ; 
      idx++ ; 
      ll temp = ra[idx]+lc[idx-1] ; 
      ans = max(ans,temp) ; 
   }
   cout << ans << endl ;
   return 0 ;
}