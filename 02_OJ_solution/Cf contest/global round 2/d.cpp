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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],dr[maxx+10],suf[maxx+10] ; 
int main()
{
   debugMode();
   set < ll > s,sk ; 
   std::vector < ll > v,dis ;
   ll n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ;
      s.insert(x) ; 
   }
   ll idx = 0 ; 
   for(auto x : s )
   {
      ar[++idx] = x ; 
   }
   for(int i=2;i<=idx;i++)
   {
      ll temp = ar[i]-ar[i-1] ;  
      dis.push_back(temp) ; 
   }
   sort(dis.begin(),dis.end()) ; 
   idx = 0 ; 
   for(auto x : dis )
   {
      dr[++idx] = x ; 
   }
   ll sum = 0 ; 
   while(idx>0)
   {
      sum+=dr[idx] ; 
      suf[idx]=sum ; 
      idx-- ; 
   } 
   ll q ;
   cin >> q ;
   while(q--)
   {
      ll l,r ;
      cin >> l >> r ; 
      auto it = s.begin() ; 
      auto lt = s.rbegin() ; 
      ll ans = 0 ; 
      ll a = *it+l ; 
      ll b = *lt+r ; 
      ans+=(b-a+1) ; 
      ll p = r-l+1 ; 
      auto kt = upper_bound(dis.begin(),dis.end(),p) ; 
      if(kt!=dis.end())
      {
          idx = kt-dis.begin() ;
          idx++ ;  
          //cout << idx << " " << suf[idx] << endl ;
          ll sub = suf[idx]-(p*(dis.size()-idx+1)) ; 
          ans-=sub ; 
      }
      v.push_back(ans) ; 
   }
   idx = 0 ; 
   for(auto x : v )
   {
      if(idx==1){cout << " " ; }
      idx = 1 ; 
      cout << x ; 
   }
   cout << endl ;
   return 0 ;
}