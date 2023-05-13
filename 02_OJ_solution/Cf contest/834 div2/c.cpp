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
void solve()
{
   int l,r,x ;
   cin >> l >> r >> x ; 
   int a,b ; 
   cin >> a >> b ; 
   // a-->b 
   if(a==b){cout << "0" << endl ; return ;}
   if(a<b)
   {
      int d = abs(a-b) ; 
      if(d>=x)
      {
         cout << "1" << endl ; return  ; 
      }
      int add = x-d ; 
      if(l<=(a-x-add))
      {
         cout << "2" << endl ; return ; 
      }
      if(r-a>=x)
      {
         a = r ; 
         d = abs(a-b) ; 
         if(d>=x)
         {
            cout << "2" << endl ; return ; 
         }
         else
         {
            a = r ; 
            d = abs(a-b) ;
            if(d>=x)
            {
               d = abs(l-a) ; 
               if(d>=x)
               {
                  a = l ; 
                  d = abs(a-b) ; 
                  if(d>=x)
                  {
                     cout << "3" << endl ; return ;
                  }
               }
            } 
         }
      }
      cout << "-1" << endl ; return  ; 
   }

   if(b<a)
   {
      int d = abs(a-b) ; 
      if(d>=x)
      {
         cout << "1" << endl ; return  ; 
      }
      int add = x-d ; 
      if((a+x+add)<=r)
      {
         cout << "2" << endl ; return ; 
      }
      if( (a-l) >=x)
      {
         a = l ; 
         d = abs(a-b) ; 
         if(d>=x)
         {
            cout << "2" << endl ; return ; 
         }
         else
         {
            a = r ; 
            d = abs(a-b) ;
            if(d>=x)
            {
               d = abs(l-a) ; 
               if(d>=x)
               {
                  a = l ; 
                  d = abs(a-b) ; 
                  if(d>=x)
                  {
                     cout << "3" << endl ; return ;
                  }
               }
            } 
         }
      }
      cout << "-1" << endl ; return  ; 
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