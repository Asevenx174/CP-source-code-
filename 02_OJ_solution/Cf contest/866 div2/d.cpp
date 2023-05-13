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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,l,r,m ; 
int getmax()
{
   set < int > s ; 
   for (int i = 0; i < n ; ++i)
   {
      s.insert(ar[i+1]) ; 
   } 
   int ans = 0 ; 
   while(s.find(ans)!=s.end()){ans++;}
   return ans ; 
}
void get()
{
   l = 0 ; 
   r = 0 ; 
   for(int i=1;i<=n;i++)
   {
      if(ar[i]==m+1)
      {
         if(l==0)
         {
            l = i ; 
            r = i ; 
         }
         else
         {
            r = i ; 
         }
         //ar[i] = m ; 
      }
   }
   //cout << l << " " << r << endl ;
}
void solve()
{
   map < int ,int > f ; 
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      //f[ ar[i+1] ]++ ; 
   }
   m = getmax() ; 
   get() ; 
   if(l==0)
   {
      for(int i=1;i<=n;i++)
      {
         int x = ar[i] ; 
         f[x]++ ; 
         if(f[x]>1 || x>m)
         {
            //cout << i << " " << m << endl ; 
            ar[i] = m ; break ; 
         }
      }
   }
   while(l>0 && l<=r){ar[l]=m;l++;}
   if(m+1==getmax())
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
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}