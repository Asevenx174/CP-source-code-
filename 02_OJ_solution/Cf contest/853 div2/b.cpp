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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n ; 
void solve()
{
  int n ;
  cin >> n ;
  string s ;
  cin >> s ;
  int idx = 1 ; 
  for(auto c : s)
  {
    int x = c=='1' ? 1 : 0 ; 
    ar[idx++] = x ;  
  }
  int l,r ; 
  if(n%2==1)
  {
     l = n/2 ; 
     r = l+2 ; 
  }
  else
  {
     l = n/2 ; 
     r = l+1 ; 
  }
  while(ar[l]==ar[r] && l>0 && r<=n){l--;r++;}
  while(ar[l]!=ar[r] && l>0 && r<=n){l--;r++;}
  int f = 1 ; 
  while(l>0 && r<=n)
  {
     if(ar[l]!=ar[r]){f=0;}
     l-- ; 
     r++ ; 
  }
  if(f)
  {
    cout << "Yes" << endl ;
  }
  else
  {
    cout << "No" << endl ;
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