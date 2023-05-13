#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
string ans[maxx+10] ; 
string calco(string s,int k)
{
   string d = "" ; 
   while(k>9)
   {
      int x = k%10 ; 
      k = k/10 ; 
      char c = x+'0' ; 
      d+=c ; 
   }
   char c = k+'0' ; 
   d+=c ; 
   reverse(d.begin(),d.end()) ; 
   string p = s+"("+d+")" ; 
   return p ;  
}
int main()
{
   debugMode();
   map < string ,int > pq ; 
   int n ;
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      string s ;
      cin >> s ; 
      if(pq[s]==0)
      {
         ans[i] = s ; 
      }
      else
      {
         ans[i] = calco(s,pq[s]) ;
      }
      pq[s]++ ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      cout << ans[i] << endl ; 
   }
   return 0 ;
}