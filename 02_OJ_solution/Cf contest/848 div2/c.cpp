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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int sett(int idx,int mask )
{
   mask = mask | (1<< (idx-1)) ; 
   return mask ; 
}
bool check(int idx,int mask )
{
   if( (mask&(1<<(idx-1))) ==0 )
   {
      return false ; 
   }
   return true ; 
}
ll res = 0,t=0 ; 
int n,pk,ar[maxx+10],br[maxx+10],val[15],cr[maxx+10] ;
bool dp[maxx+5][1050] ; 
set < int > s ; 
void calco(int idx,int mask)
{
   if(dp[idx][mask]){return;}
  
   if(idx>s.size())
   {
      int f = 0 ; 
      map < int , int > pq ; 
      for(int i=1;i<=s.size();i++)
      {
         if(check(i,mask))
         {
            pq[ val[i] ] = 1 ; 
            f++ ; 
         }
      }
      
      if(f>k){return;}
      for(int i=1;i<=n;i++)
      {
         if(ar[i]==br[i])
         {
            cr[i] = ar[i] ; continue ; 
         }
         int x = ar[i] ; 
         if(pq[ ar[i] ])
         {
            x = br[i] ; 
         }
         cr[i] = x ; 
      }
      
      ll l=1 ; 
      ll ans = 0 ; 
      while(l<=n)
      {
         ll r = l ;
         if(cr[l]!=br[l]){l++;continue;}
         while(r+1<=n && br[r+1]==cr[r+1]){r++;}
         ll len = r-l+qq ; 
         ll add = len*(len+qq) ; 
         add = add/tt ; 
         ans+=add ;
         //cout << l << " " << r << " " << add << endl ;
         l = r+1 ; 
      }
      res = max(res,ans) ; 
      return ; 
   }
   

   calco(idx+1,sett(idx,mask)) ; 
   calco(idx+1,mask) ; 
   dp[idx][mask] = true ; 
   return ;
}
void solve()
{
   t++ ; 
   res = 0 ; 
  //int x = c-'0'-48 ; 
   s.clear() ; 
   cin >> n >> pk ; 
   for (int i = 0; i <=  n+5 ; ++i)
   {
      for (int j = 0; j <=1040 ; ++j)
      {
         dp[i][j] = false ; 
      }
   }
   string a,b ; 
   cin >> a >> b ; 
   int idx = 1 ; 
   for(auto c : a)
   {
      ar[idx++] = c-'0'-48 ; 
      s.insert(ar[idx-1]) ;  
   }
   idx = 1 ; 
   for(auto c : b)
   {
      br[idx++] = c-'0'-48 ;  
   }
   idx = 1 ; 
   for(auto x : s)
   {
      val[idx++] = x ;  
   }
   calco(1,0) ; 
   cout << res << endl ;
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