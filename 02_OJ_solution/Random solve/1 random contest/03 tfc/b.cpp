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
const ll maxx = 4e6+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int lr[maxx+10] ; 
int rr[maxx+10] ;
int saved[maxx+10] ;  
void solve()
{
   set < int > s,ans ; 
   map < int ,int > pq,qp ; 
   int n,m ;
   cin >> n >> m ;
   for (int i = 0; i < m ; ++i)
   {
      ans.insert(i) ; 
      int l,r,add ;
      cin >> l >> add ;
      r = l+add-1 ; 
      lr[i] = l ;
      rr[i] = r ; 
      s.insert(l) ;
      s.insert(r) ; 
   }
   int idx = 0 ; 
   for(auto x : s )
   {
      pq[x] = idx ;
      qp[idx] = x ; 
      idx++ ;   
   }
   vector < int > dp(idx+5,mod) ; 
   dp[0] = 0 ;   
   vector < pair < int , pii > > last ; 
   map < pii , int > str ; 
   for (int i = 0; i < m ; ++i)
   {
      int l = lr[i] ; 
      int r = rr[i] ; 
      str[{l,r}] = i ; 
      l = pq[l] ; 
      r = pq[r] ;  
      //cout << l << " " << r << endl ; 
      last.push_back({r,{l,i}}) ; 
   }
   sort(last.begin(),last.end()) ; 
   for(auto temp : last )
   {
       int r = temp.ff ; 
       pii p = temp.ss ; 
       int l = p.ff ; 
       int pos   = p.ss ;  
      // cout << l << " " << r << " " << pos << endl ;
       //dp[r] = min(dp[r],dp[l-1]+1) ; 
       int val = dp[l-1]+1 ; 
       if(val<dp[r])
       {
          dp[r] = val ; 
          saved[r] = l ; 
       }
   }
   int pos = idx ; 
   while(pos>0)
   {
      int l = saved[pos] ; 
      int r = pos ; 

      int al = qp[l] ; 
      int ar = qp[r] ; 


      int d = str[{l,r}] ; 
      ans.erase(ans.find(d)) ; 

      int pos = pq[al] ; 

      pos = saved[pos-1] ; 
   }
   if(ans.size()==0)
   {
      cout << "0" << endl ; return ; 
   }
   cout << ans.size() << endl ;
   idx = 0  ; 
   for(auto x : ans )
   {
      if(idx>0){cout << " " ; }
      idx = 1;  
      cout << x+1 ;
   }
   cout << endl ;
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