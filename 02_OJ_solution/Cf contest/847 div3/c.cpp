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
int ar[maxx+10][maxx+10],n,a,b,ans[maxx+10] ;  
void calco(int idx)
{
   map < int ,int > pq ; 
   a=0,b=0 ; 
   for(int i=1;i<=n;i++)
   {
      int x = ar[i][idx] ;
      pq[x]++ ; 
      if(a==0)
      {
         a = x ; 
      }
      else if(a!=x)
      {
         b = x ; 
      } 
   }
   if(pq[a]>pq[b])
   {
      swap(a,b) ; 
   }
}
void solve()
{
   //set < int > v[maxx+10] ; 
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      for (int j = 0; j < n-1 ; j++)
      {
         cin >> ar[i+1][j+1] ; 
      }
   }
   calco(1) ; 
   ans[1] = b ; 
   ans[2] = a ; 
   int idx = 2 ; 
   while(idx<n)
   {
      int x = a ; 
      int y = b ; 
      calco(idx) ; 
      if(a==x || a==y)
      {
         ans[idx+1] = b ;  
      }
      else
      {
         ans[idx+1] = a ; 
      }
      idx++ ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << ans[i+1] ; 
   }
   cout << endl ; 
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