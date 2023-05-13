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
ll n,cap,wr[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      cin >> n >> cap ; 
      vector < int > ar(n+5,0) ; 
      std::vector < pii > v ;
      ll l = (cap+1LL)/2LL ;
      ll r = cap ; 
      ll sum = 0 ; 
      for (int i = 0; i < n ; ++i)
      {
         ll x ;
         cin >> x ;
         if(x>r){continue;}
         v.push_back({x,i+1}) ; 
         sum+=x ; 
      }
      sort(v.begin(),v.end(),greater<pii>()) ; 
      if(sum<l){cout <<"-1" << endl;continue;}
      sum = 0 ; 
      ll f = 0 ; 
      for(auto p : v )
      {
         sum+=p.ff ; 
         ar[p.ss] = 1 ; 
         f++ ; 
         if(sum>=l){break;}
      }
      cout << f << endl ;
      f = 0 ; 
      for(int i=1;i<=n;i++)
      {
         if(ar[i]==1)
         {
            if(f){cout << " " ; }
            f = 1 ; 
            cout << i ; 
         }
      }
      cout << endl ;
   }
   return 0 ;
}