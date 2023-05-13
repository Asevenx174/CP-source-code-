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
int ar[maxx+10],lr[maxx+10],rr[maxx+10],n ; 
void solve()
{
   cin >> n ; 
   rr[n+1] =  0 ;
   lr[n+1] = 0 ; 
   int sum = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      lr[i+1] = sum ; 
      sum+=ar[i+1] ; 
   }
   sum = 0 ; 
   for(int i=n;i>0;i--)
   {
      rr[i] = sum ;
      sum+=(!ar[i+1]) ; 
   }
   ll ans=0,add=0,pos=0 ; 
   for(int i=1;i<=n;i++)
   {
      if(ar[i]==0)
      {
         ans+=lr[i-1] ; 
         //add = max(add,rr[i+1]-lr[i-1]) ; 
         int temp = rr[i+1]-lr[i-1] ; 
         if(temp>add)
         {
            pos = i ; 
            add = temp ; 
         }
      }
      else
      { 
         ans+=rr[i+1] ; 
         //add = max(add,lr[i-1]-rr[i+1]) ;
         int temp = lr[i-1]-rr[i+1] ; 
         if(temp>add)
         {
            pos = i ; 
            add = temp ; 
         }
      }
   }
   int sub = 0 ; 
   if(ar[pos]==0)
   {
      sub+=lr[pos-1] ; 
   }
   else
   { 
      sub+=rr[pos+1] ; 
   }
   int req = ans+add-sub ; 
   cout << req << endl ;
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