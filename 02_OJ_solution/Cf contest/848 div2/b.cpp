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
int n,m,d ; 
int ar[maxx+10],pr[maxx+10],pos[maxx+10],p[maxx+10] ; 
bool valid(int i)
{
   if(p[i]<p[i+1] && p[i+1]<=(p[i]+d) ){ return true; }
   return false ; 
}
void solve()
{
   cin >> n >> m >> d ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> pr[i+1] ; 
      pos[ pr[i+1] ] = i+1 ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      cin >> ar[i+1] ; 
      p[i+1] = pos[ ar[i+1] ] ; 
   }
   int ans = mod,f=0 ; 
   for(int i=1;i<m;i++)
   {
      if(valid(i))
      {
         int p1 = p[i] ; 
         int p2 = p[i+1] ; 

         ans = min(ans,p2-p1) ;
         int temp = p1+d+1 ;  
         if(temp<=n){ans = min(ans,temp-p2) ;} 
         else
         {
            int add = n-p2 ; 
            int need = (temp-p2)-add ; 
            if(p1-need>0)
            {
               ans = min(ans,temp-p2) ;
            } 
         }
         
         int sub = p1+d-p2+1 ; 
         if(p1-sub>0){ans = min(ans,p1+d-p2+1) ;}
         else
         {
            int need = 1+d-p2+1 ; 
            if(p2+need<=n)
            {
               ans = min(ans,p1+d-p2+1) ;
            }
         }
      }
      else{f=1;}
   }
   if(f){ans=0;}
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