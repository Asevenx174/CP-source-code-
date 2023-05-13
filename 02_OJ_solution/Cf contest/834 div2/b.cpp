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
const ll maxx = 2000+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

void solve()
{
   std::vector < int > ar(maxx+5,0) ;
   int m,s ;
   cin >> m >> s ;
   int best = 0 ; 
   for (int i = 0; i < m ; ++i)
   {
      int x ; 
      cin >> x ; 
      ar[x] = 1 ; 
      best = max(best,x) ; 
   }
   int add = 0 ; 
   for (int i = 1 ; i < best ; ++i)
   {
      if(ar[i]==0)
      {
         add+=i ; 
      }
   }
   while(add<s)
   {
      best++ ; 
      add+=best ; 
   }
   if(add==s)
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