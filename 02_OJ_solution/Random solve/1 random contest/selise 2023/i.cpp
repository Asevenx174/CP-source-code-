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
map < char ,int > f,k ;
void calco(string s)
{
   k.clear() ; 
   for(auto c : s)
   {
      k[c]++ ; 
   }
} 
bool check(string s)
{
   for(auto p : k)
   {
      char c = p.ff ; 
      int x = p.ss ; 
      if(f[c]<x){return false;}
   }
   return true ; 
}
int t = 1 ; 
void solve()
{
   f.clear() ; 
   string s ;
   cin >> s ;
   for(auto c : s)
   {
      f[c]++ ; 
   }
   string a = "SELISE" ;
   string b = "SELISE Digital Platforms" ; 
   int p=0,q=0 ; 
   calco(a) ; 
   if(check(a)){p=1;}
   calco(b) ;
   if(check(b)){q=1;}
   string ans = "" ; 
   if(p==1 && q==1)
   {
      ans+="BOTH" ; 
   }
   else if(p==0 && q==0)
   {
      ans+="NONE" ;
   }
   else if(p==1)
   {
      ans+="SELISE" ;
   }
   else
   {
      ans+="SELISE Digital Platforms" ;
   }
   cout << "Case " << t++ << ": " << ans << endl ;
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