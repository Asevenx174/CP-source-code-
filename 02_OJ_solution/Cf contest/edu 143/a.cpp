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
bool check(string s)
{
   for (int i = 1 ; i < s.size() ; ++i)
   {
      if(s[i]==s[i-1]){ return false ;}
   }
   return true ; 
}
string sub(string s)
{
   string a = "" ; 
   int n = s.size() ; 
   for (int i = 0; i+1 < n ; ++i)
   {
      a+=s[i] ; 
   }
   return a ; 
}
string add(string s,char c)
{
   s+=c ; 
   return s ; 
}
void solve()
{
   int n,m,f=0 ; 
   cin >> n >> m ;
   string a,b ; 
   cin >> a >> b ; 
   if(check(a) && check(b)){f=1;}
   if(a[n-1]!=b[m-1])
   {
      string p=a ; 
      string q=b ; 
      while()
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