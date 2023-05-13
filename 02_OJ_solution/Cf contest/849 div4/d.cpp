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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int lr[maxx+10],rr[maxx+10] ; 
void solve()
{
  int n ;
  cin >> n ;
  rr[n+1] = 0 ; 
  string s ;
  cin >> s ;
  set < int > l,r ; 
  string temp = s ; 
  reverse(temp.begin(),temp.end()) ; 
  int idx = 1 ; 
  for(auto c : s)
  {
    l.insert(c) ;
    lr[idx++] = l.size() ; 
  }
  idx = n ; 
  for(auto c : temp)
  {
    r.insert(c) ;
    rr[idx--] = r.size() ; 
  }
  int ans = 0 ; 
  for(int i=1;i<=n;i++)
  {
     int pq = lr[i]+rr[i+1] ;
     ans = max(ans,pq) ;  
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