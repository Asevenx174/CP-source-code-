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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 4e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,k,sr[maxx+10] ; 
std::vector < ll > v ;
ll com(ll x)
{
   ll ans = x*(x+qq) ; 
   ans = ans/tt ; 
   return ans ; 
}
ll baki(ll l,ll r,ll ex)
{
  ll a = ar[l] ; 
  ll b = ar[r] ; 
  if(a>b){swap(a,b);}
  ll ans = 0 ; 
  ll h = b-a ; 
  if(l==2){cout << ar[l] << " " << ar[r] << " " << ex << endl ;}
  if(h>=ex)
  {
     ans = com(b)-com(b-ex) ; 
     return ans ;  
  }
  //cout << "yes" << endl ; 
  ans = com(b)-com(b-h) ;
  ex-=h ; 
  b = a ; 
  l = a ; 
  r = l-(ex/tt) ; 
  ll temp = com(l)-com(r) ; 
  ans+=(temp*tt) ; 
  if(ex%tt==qq){ans+=r;}
 // if(l==3){cout << ans << endl ;}
  cout << ans << endl ;
  return ans ;  
}
ll solid(ll l,ll r)
{
   ll ans = sr[r]-sr[l-qq] ;
   return ans ;  
}
ll calco(ll l,ll ex)
{
   ll val = v[l-1]+ex ; 
   //cout << val << endl ;
   auto it = upper_bound(v.begin(),v.end(),val) ;
   //cout << *it << endl ;
   ll r = (it-v.begin())-qq ; 
   //cout << idx << endl ;
  // cout << l << " " << r << endl ;
   ll ans = 0 ; 
   if(l<=r)
   {
      ans+=solid(l,r) ; 
      //if(l==3){cout << l << " ? " << r << " " << ans << endl ; cout << (v[r]-v[l-1]) << endl ;}
      ex-=(v[r]-v[l-1]) ; 
      cout << l-1 << " " << r+1 << " " << ex << endl ;
      ans+=baki(l-1,r+1,ex) ; 
   }
   else
   {
      ll b = ar[l] ; 
      ll a = ar[l]-ex ; 
      ans+=(com(b)-com(a)) ; 
   }
   //if(l==4){cout << l << " " << r << " " << ans <<  endl ;}
   return ans ; 
}
void solve()
{
   v.clear() ; 
   v.push_back(zz) ; 
   cin >> n >> k ;
   ar[2*n] = 0 ; 
   ll sum=0,res=0 ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      sum+=ar[i+1] ; 
      res+=com(ar[i+1]) ; 
      v.push_back(sum) ; 
      sr[i+1] = res ; 
   }
   for(int i=1;i<=n;i++)
   {
      ar[n+i] = ar[i] ; 
      sum+=ar[i] ; 
      v.push_back(sum) ;
      res+=com(ar[i]) ;
      sr[n+i] = res ;  
   }
  // v.push_back(zz) ;
   //calco(2,10) ; 
   ll ans = 0 ; 
   for(int i=3;i<=3;i++)
   {
      ll temp = calco(i,k) ; 
      //cout << i << " " << temp << endl ;
      ans = max(ans,temp) ;  
   }
   cout << ans << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}