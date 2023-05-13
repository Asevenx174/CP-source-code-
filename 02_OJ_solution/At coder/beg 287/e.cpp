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
#define pii                pair < string ,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 5e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ; 
int calco(string a,string b)
{
   int n = min(a.size(),b.size()) ; 
   int ans = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
      if(a[i]!=b[i]){break;}
      ans++ ; 
   }
   return ans ; 
}
void solve()
{
   vector < pii > s ; 
   int n ; 
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      string x ;
      cin >> x ; 
      s.push_back({x,i+1}) ; 
   }
   sort(s.begin(),s.end()) ; 
   for (int k = 0; k < n ; ++k)
   {
      int ans = 0 ; 
      if(k==0 || k==n-1)
      {
         int j = k==0 ? 1 : n-2 ;
         ans = calco(s[k].ff,s[j].ff) ; 
      }
      else
      {
         ans = max( calco(s[k].ff,s[k+1].ff) , calco(s[k].ff,s[k-1].ff)  ) ; 
      }
      ar[ s[k].ss ] = ans ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      cout << ar[i+1] << endl ;
   }
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