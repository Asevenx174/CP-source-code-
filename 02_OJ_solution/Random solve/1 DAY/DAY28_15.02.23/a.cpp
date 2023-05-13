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
/*

for(int i=1;i<=n;i++)
{
   int x ;
   cin >> x ; 
}

*/
int ar[maxx+10],n,p ; 
void solve()
{
   int co = 0 ; 
   map < int ,int > pq ; 
   cin >> n >> p ; 
   for(int i=1;i<=n;i++)
   {
      int x ;
      cin >> x ; 
      ar[i] = x ; 
      if(pq[x]==0){co++;}
      pq[x] = 1 ; 
   }
   if(co==p){cout << "0" << endl ; return ;}
   int ans = 1 ; 
   ar[n+1] = 0 ;  
   for(int i=n;i>0;i--)
   {
      if(ar[i+1]!=0)
      {
        break ; 
      }
      else
      {
        ar[i] = (ar[i]+1)%p ; 
      }
   }
   for(int i=1;i<=n;i++)
   {
     int x = ar[i] ; 
     if(pq[x]==0){co++;}
     pq[x] = 1 ;  
   }
   if(co==p){cout << ans << endl ; return ;}
   int x = ar[n] ; 
   for(int i=x-1;i>=0;i--)
   {
      if(pq[i]==0)
      {
         ans = (p-1)-(x-i) ; 
         cout << ans << endl ; return  ; 
      }
   }
   for(int i=p-1;i>x;i--)
   {
      if(pq[i]==0)
      {
         ans = i-x ; 
         cout << ans << endl ; return  ; 
      }
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