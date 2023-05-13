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
void solve()
{
   map < char ,int > ci ;
   map < int ,char > ic ; 
   char cc='a' ; 
   int pos=1 ; 
   while(cc<='z')
   {
      ci[cc] = pos ; 
      ic[pos] = cc ;  
      cc++ ; 
      pos++ ; 
   }
   std::vector < int > v[50] ;
   int n ;
   cin >> n ; 
   string s ;
   cin >> s ; 
   int idx = 0 ; 
   for(auto c: s)
   {
      int x = ci[c] ;   
      v[x].push_back(idx++) ; 
   }
   int f = 1 ; 
   for(int i=1;i<=26;i++)
   {
      int a = 0 ; 
      int b = 0 ; 
      for(auto x : v[i])
      {
         if(x%2){a=1;}else{b=1;}
      }
      if((a&b)==1){f=0;}
   }
   if(f)
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