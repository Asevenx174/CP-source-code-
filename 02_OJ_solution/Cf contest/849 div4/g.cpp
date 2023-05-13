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
#define pii                pair < long long , long long >

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
void solve()
{
   std::vector < pii > ar ;
   vector < ll > pref ;  
   ll n,c ;
   cin >> n >> c ; 
   for(int i=1;i<=n;i++)
   {
      ll x ;
      cin >> x ;
      ll l = x+i ; 
      ll r = (n+1)-i+x ;
      ar.push_back({min(l,r),l}) ; 
     // cout << min(l,r) << endl ;
   }
   sort(ar.begin(),ar.end()) ; 
   ll sum = 0 ; 
   pref.push_back(sum) ; 
   for(auto p : ar)
   {
      sum+=p.ff ; 
      pref.push_back(sum) ; 
      //cout << sum << " ?? " << endl ;
   }
   ll ans = 0 ; 
   for(int i=0;i<n;i++)
   {
      ll have = c-ar[i].ss ; 
      ll l=0,r=n,best=0 ;
      while(l<=r)
      {
         ll m = (l+r)/tt ; 
         ll need = pref[m] ; 
         ll co = m+1 ; 
         if(i<m)
         {
            co-- ; 
            need-=ar[i].ff ; 
         }
         if(need<=have)
         {
            //cout << co << " " << need << endl ; 
            best = max(best,co) ; 
            l = m+qq ; 
         }
         else
         {
            r = m-qq ; 
         }
      }
      ans = max(ans,best) ;  
   }
   cout << ans << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}