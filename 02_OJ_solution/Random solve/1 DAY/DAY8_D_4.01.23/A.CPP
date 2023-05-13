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
int l,r ;
bool op1(int a,int b,int n)
{
   int x = (a-b)*(n-2)+a+qq ;
   int y = (a-b)*(n-1)+a ; 
   if(l<0)
   {
      l = x ; r = y ; 
   }
   a = max(l,x) ; 
   b = min(r,y) ; 
   if(a<=b)
   {
      l = a ;
      r = b ; 
      return true ; 
   }
   return false ; 
} 
int calco(int a,int b,int L)
{
   int x = L-a ; 
   int y = a-b ; 
   int ans = x/y ;
   if(x%y!=0){ans++;}
   ans++ ; 
   return ans ;  
}
void solve()
{
   std::vector < int > v ;
   l = -mod ; 
   int q ;
   cin >> q ;
   while(q--)
   {
      int t,a,b,n ; 
      cin >> t ; 
      if(t==1)
      {
         cin >> a >> b >> n ; 
         if(n==1)
         {
            if(l<0)
            {
               l = 1 ; 
               r = a ; 
               v.push_back(1) ; 
            }
            else
            {
               if(l<=a)
               {
                  v.push_back(1) ; 
                  r = min(r,a) ; 
               }
               else
               {
                  v.push_back(0) ; 
               }
            }
         }
         else if(op1(a,b,n))
         {
            v.push_back(1) ; 
         }
         else
         {
            v.push_back(0) ;
         } 
      }
      else
      {
         cin >> a >> b ; 
         if(l<0)
         {
            v.push_back(-1) ; continue ; 
         }
         //cout << l << " " << r << "  " << a << endl ;
         if(r<=a)
         {
            v.push_back(1) ; continue ; 
         }
         int n = calco(a,b,r) ; 
         int x = (n-1)*(a-b)+1 ;
         int y = (n-2)*(a-b)+a ;
         //cout << l << " ? " << r << endl ;
         //cout << x << " " << y << endl ; 
         if(y<x)
         {
            v.push_back(n) ; 
         } 
         else
         {
            v.push_back(-1) ; 
         }
      }
   }
   for (int i = 0; i < v.size() ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << v[i] ; 
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