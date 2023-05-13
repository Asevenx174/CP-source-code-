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
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,p ; 
map < int , int > pq ; 
int right(int idx)
{
   int val = p-1 ; 
   while(val>idx && pq[val]==1)
   {
      val-- ; 
   }
   int ans = mod ; 
   if(pq[val]==0 && val>=0){ans=val;}
   return ans ; 
}
int left(int idx)
{
   int val = idx-1 ; 
   while(val>=0 && pq[val]==1)
   {
      val-- ; 
   }
   int ans = mod ; 
   if(pq[val]==0 && val>=0){ans=val;}
   return ans ; 
}
void add(int d)
{
   int idx = n ; 
   int pre = d ; 
   while(idx>0)
   {
      int x = ar[idx]+pre ; 
      pre = 0 ; 
      if(x>=p){pre=1;}
      ar[idx] = x%p ; 
      pq[ ar[idx] ] = 1 ; 
      idx-- ;  
   }
   ar[idx] = pre ; 
   if(pre>0){pq[1]=1;}
}
void solve()
{
   pq.clear() ; 
   cin >> n >> p ; 
   for(int i=1;i<=n;i++)
   {
      int x ;
      cin >> x ;
      ar[i] = x ; 
      pq[x] = 1 ; 
   }
   int last = ar[n] ; 
   int r = right(last) ; 
   int l = left(last) ;
   //cout << l << " " << r << endl ;
   if(l==mod && r==mod)
   {
      cout << "0" << endl ; return ; 
   } 
   if(l==mod)
   {
      cout << (r-last) << endl ; return ; 
   }
   int ans = p-last ; 
   add(ans) ; 
   l = left(last) ;
   //cout << l << endl ;
   if(l==mod)
   {
      cout << ans << endl ; return ; 
   } 
   ans+=l ; 
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