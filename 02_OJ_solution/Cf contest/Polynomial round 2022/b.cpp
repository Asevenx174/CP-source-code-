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

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,m,k ; 
void solve()
{
  std::vector<ll>ar ;
  cin >> n >> m >> k ; 
  for (int i = 0; i < m ; ++i)
  {
     ll x ;
     cin >> x ; 
     ar.push_back(x) ; 
  }
  ar.push_back(mod) ; 
  sort(ar.begin(),ar.end(),greater<ll>()) ; 
  ll b = n/k ; 
  ll r = n%k ; 
  priority_queue < pii > pq ; 
  if(r!=zz)
  {
     pq.push({b+qq,r}) ; 
    // cout << b+qq << " " << r << endl ;
  }
  pq.push({b,k-r}) ; 
  //cout << b << " " << k-r << endl ;
  ll idx = qq ; 
  while(!pq.empty() && idx<=m)
  {
     pii p = pq.top() ; pq.pop() ; 
     ll s = p.ff ; 
     ll f = p.ss ; 
     ll a = ar[idx] ; 
     //cout << a << " " << f << " " << s << endl ;
     if(s<a){break;}
     ll sub = s-a ; 
     if(sub>zz)
     {
        pq.push({sub,qq}) ;
     }
     if(f>qq)
     {
        pq.push({s,f-qq}) ; 
     }
     idx++ ; 
  }
  if(idx>m)
  {
     cout << "YES" << endl ;
  }
  else
  {
     cout << "NO" << endl ; 
  }
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