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
int ar[maxx+10] ; 
void solve()
{
   map < int ,int > f ; 
   int n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ; 
      if(x%4==0)
      {
         x = 4 ; 
      }
      else if(x%2==0)
      {
         x = 2 ;  
      }
      else
      {
         x = 1 ;
      }
      f[x]++ ; 
   }
   int idx = 2 ; 
   while(idx<=n && f[4]>0)
   {
      ar[idx] = 4 ; 
      f[4]-- ; 
      idx+=2 ; 
   }
   idx-- ; 
   while(idx<=n && f[2]>0)
   {
      ar[idx] = 2 ; 
      idx++ ; 
      f[2]-- ;  
   }
   for(int i=1;i<=n;i++)
   {
      if(ar[i]==0){ar[i]=1;}
   }
   int flag = 1 ;  
   for(int i=2;i<=n;i++)
   {
      int x = ar[i]*ar[i-1] ; 
      if(x%4!=0){flag=0;}
   }
   if(flag)
   {
      cout << "Yes" << endl ;
   }
   else
   {
      cout << "No" << endl ; 
   }
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