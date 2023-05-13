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
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,idx[maxx+10],sr[maxx+10] ; 
void check()
{
   std::vector < pii > v ;
   for (int i = 0; i < n ; ++i)
   {
      v.push_back({ar[i+1],i+1}) ; 
   }
   sort(v.begin(),v.end()) ; 
   for (int i = 0; i < n ; ++i)
   {
      sr[i+1] = v[i].ff ; 
      idx[i+1] = v[i].ss ;  
   }
}
int a,b,p,q ; 
void get()
{
   a = sr[1] ; 
   b = sr[n] ; 
   p = idx[1] ; 
   q = idx[n] ; 
}
void solve()
{
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ; 
      ar[i+1] = x ;  
   }
   check() ; 
   get() ; 
   if(a==b)
   {
      cout << "0" << endl ; return ;
   }
   if(a==1)
   {
      cout << "-1" << endl ; return ; 
   }
   vector < pii > ans ; 
   while(a!=b)
   {
      //cout << a << " --- " << b << endl ;
      //cout << p << "--- "  << q << endl;
      int val = b/a ; 
      if(b%a!=0){val++;}
      ar[q] = val ;
      ans.push_back({q,p}) ;  
      check() ; 
      get() ; 
   }
   cout << ans.size() << endl ; 
   for(auto x : ans )
   {
      cout << x.ff << " " << x.ss << endl ;
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