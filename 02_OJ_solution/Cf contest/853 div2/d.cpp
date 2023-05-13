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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,k,x,ar[maxx+10] ; 
ll getval(ll val)
{
   ll temp = qq,ans=0 ; 
   while(temp<=val)
   {
      if( (val&temp) !=zz ){ans=temp;}
      temp = temp*tt ; 
   }
   return ans ; 
}
ll req[maxx+10] ; 
void solve()
{
  cin >> n >> k >> x ; 
  ll temp = getval(x) ; 
  ll lim = min(n,temp*tt-qq) ; 
  ll m = 0 ; 
  for(ll i=temp;i<=n;i++)
  {
     if( (i&temp)!=zz){m++;req[m]=i;}
  }
  if(m<k)
  {
    cout << "NO" << endl ; return ;
  }
  cout << "YES" << endl ;
  vector < vector < int > > pq ; 
  vector < bool > used(n+5,false) ; 
  ll idx = 0 ; 
  for(ll i=1;i<k;i++)
  {
     ll y = req[++idx] ; 
     ll yy = (y^x) ; 
     if(y==x){i--;continue;}
     used[y] = true ; 
     used[yy] = true ; 
     vector < int > v ; 
     v.push_back(y) ; 
     v.push_back(yy) ; 
     pq.push_back(v) ; 
  }
  vector < int > v ; 
  for (int i = 0; i < n ; ++i)
  {
     if(!used[i+1])
     {
        v.push_back(i+1) ; 
     }
  }
  pq.push_back(v) ;
  for(auto vv : pq )
  {
     cout << vv.size() ; 
     for(auto xx : vv)
     {
        cout << " " << xx ; 
     }
     cout << endl ;
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