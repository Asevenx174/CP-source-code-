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
 
int n,m ; 
std::vector < int > v ;
int lr[maxx+10],rr[maxx+10] ; 

void solve()
{
   map < int , bool > used ; 
   set < int > s ;
  // sett.clear() ; 
    v.clear() ; 
   int l=0,r=0 ; 
   cin >> n >> m ;
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      if(x==-1){l++;}else if(x==-2){r++;}
      else {
         s.insert(x) ; 
         v.push_back(x) ; 
        // sett.insert(x) ; 
         used[x] = true ; 
      }
   }
   int sum = 0 ; 
   for(int i=1;i<=m;i++)
   {
      if(!used[i]){sum++;}
      lr[i] = sum ; 
   }
   sum = 0 ; 
   for(int i=m;i>0;i--)
   {
      if(!used[i]){sum++;}
      rr[i] = sum ;
   }
   int dis = s.size() ; 
   int ans = dis+min(max(l,r),m-dis) ; 
   for(auto x : v)
   {
      int a = min(lr[x],l) ; 
      int b = min(rr[x],r) ;
      ans = max(ans,a+b+dis) ;  
   }
   cout << ans << endl ;
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