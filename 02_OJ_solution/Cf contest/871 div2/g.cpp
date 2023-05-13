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
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e6+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int l=0,pr=0,best=0 ;  
int pq[maxx+10] ;  
int calco(int val)
{
  int a=0,b=best,ans=0 ; 
  while(a<=b)
  {
    int m = (a+b)/2 ; 
    if(pq[m]>val)
    {
      b = m-qq ; 
    }
    else
    {
      ans = m ; 
      a = m+qq ; 
    }
  }
  return ans ; 
}
void ini()
{
  l = 0 ; 
  pr = 1 ; 
  pq[l] = pr ; 
  while((pr+l+qq)<=maxx)
  {
     l++ ; 
     pr+=l ; 
     pq[l] = pr ; 
     best = l ; 
  }
}
int used[maxx+10] ;  
int pos = 0 ; 
void solve()
{
  pos++ ; 
  int n ;
  cin >> n ;
  queue < pii > q ; 
  l = calco(n) ; 
  q.push({n,l}) ;
  vector < int > s ;  
  while(!q.empty())
  {
    pii p = q.front() ; q.pop() ; 
    if(p.ff<qq || used[p.ff]==pos){continue;}
    //cout << p.ff << endl ; 
    used[p.ff] = pos ; 
    s.push_back(p.ff) ;  
    l = p.ss ; 
   // cout << l << " " << pq[l] << " " << (p.ff-l) << endl ;
    if( pq[l]!=(p.ff-l) ){q.push({p.ff-l,l-qq});} 
    if(pq[l]!=p.ff){q.push({p.ff-l-qq,l-qq}) ;} 
  } 
  ll ans = 0 ; 
  for(auto x : s)
  {
    ll y = x ; 
    ans+=(y*y) ; 
  }
  cout << ans << endl ;
}
int main()
{
   debugMode();
   ini() ; 
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}