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
int ar[maxx+10],n ; 
void solve()
{
   int f = 0 ; 
   cin >> n ;
   set < int > s ; 
   for (int i = 0; i < n ; ++i)
   {
      s.insert(i+1) ; 
   }
   for (int i = 1 ; i <= n/2 ; ++i)
   {
      int x ;
      cin >> x ; 
      ar[2*i] = x ; 
      auto it = s.find(x) ; 
      if(it==s.end()){f=1;continue;}
      s.erase(it) ; 
   }
   if(f)
   {
      cout << "-1" << endl ; return  ; 
   }
   for(int i=n/2;i>0;i--)
   {
      int idx = 2*i ; 
      auto it = s.lower_bound(ar[idx]) ; 
      if(it==s.begin())
      {
         cout << "-1" << endl ; return ; 
      }
      it-- ; 
      ar[idx-1] = *it ; 
      s.erase(it) ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " ";}
      cout << ar[i+1] ; 
   }
   cout << endl ;
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