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
const ll maxx = 2e6+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],br[maxx+10],gr[maxx+10] ; 
int n,m,lr[maxx+10],rr[maxx+10] ; 
map < pii , bool > taken ; 
void calco(int l,int r)
{
   if(r>n){return;}
  //cout << l << " " << r << endl ;
   taken[{l,r}] = true ; 
   if(gr[r]>r)
   {
      if(gr[r]==gr[r+1])
      {
         r = gr[r] ; 
         int l = rr[r] ; 
         calco(l,r) ;  
      }
      else
      {
         calco(r+1,lr[r+1]) ; 
      }
   }
   else
   {
      int idx = r+1 ; 
      while(idx<=n && gr[idx]<idx)
      {
         idx++ ; 
      }
    //  cout << l << " " << r << " " << idx << endl ; 
      if(idx<=n)
      {
         calco(idx,lr[idx]) ; 
      }
   }
}
void solve()
{
   cin >> n >> m ;
   for (int i = 0; i < n+5 ; ++i)
   {
      lr[i] = 0 ; 
      rr[i] = mod ; 
   }
   int start = mod ; 
   for (int i = 0; i < m ; ++i)
   {
      int l,r ;
      cin >> l >> r ; 
      r+=(l-1) ; 
      ar[i] = l ; 
      br[i] = r ; 
      lr[l] = max(lr[l],r) ; 
      rr[r] = min(rr[r],l) ; 
      start = min(start,l) ; 
   }
   int sum = 0 ; 
   for(int i=1;i<=n;i++)
   {
      sum = max(sum,lr[i]) ; 
      gr[i] = sum ; 
      //cout << i << " " << sum << endl ; 
   }
   taken.clear() ; 
   int l = start ; 
   int r = lr[l] ; 
   calco(l,r) ; 
   std::vector < int > ans ;
   for (int i = 0; i < m ; ++i)
   {
      int l = ar[i] ; 
      int r = br[i] ; 
      if(taken[{l,r}])
      {
        //cout << l << " " << r << endl ;
        taken[{l,r}] = false ; 
      }
      else
      {
         ans.push_back(i+1) ; 
      }
   }
   if(ans.size()==0)
   {
      cout << "0" << endl ; return ; 
   }
   cout << ans.size() << endl ;
   for (int i = 0 ; i < ans.size() ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << ans[i] ; 
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