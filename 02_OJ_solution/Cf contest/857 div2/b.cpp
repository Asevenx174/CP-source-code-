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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n,ar[maxx+10],fr[maxx+10],id[maxx+10] ; 
int calco(int a,int b)
{
   int ans = (a/2)+(a%2)+(b/2)+(b%2) ; 
   return ans ; 
}
void solve()
{
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   int pos = 0 ; 
   int idx = 1 ; 
   while(idx<=n)
   {
      pos++ ; 
      int l = idx ; 
      int r = idx ;
      while(r+1<=n && ar[r]==ar[r+1]){r++;}
      id[pos] = ar[l] ; 
      fr[pos] = r-l+1 ; 
      idx = r+1 ;  
   }
   int ans = 0 ; 
   idx = 1 ; 
   if(id[idx]==2){idx++;}
   int m=0,f=0,sum=0 ; 
   while(idx<=pos)
   {
      if(id[idx]==1)
      {
         ans = max(ans,sum+fr[idx]) ; 
         sum+=fr[idx] ; 
      } 
      else
      {
         int a = fr[idx-1]/2 ; 
         int b = fr[idx-1]-a ; 
         int best = 0 ; 
         int x = a ;
         int y = b ; 
         for(int i=-3;i<=3;i++)
         {
            int j = -i ; 
            int mm = m+i+a ; 
            int ff = f+j+b ;  
            if((i+a)>=0 && (j+b)>=0)
            {
               int temp = calco(mm,ff) ;
               if(temp>best)
               {
                  best = temp ; 
                  x = mm ; 
                  y = ff ; 
               }
            }
         }
         //cout << x << " " << y << endl ;
         m=x ; 
         f=y ;
         ans = max(ans,best) ;
         sum = best ;  
      }
      idx++ ; 
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