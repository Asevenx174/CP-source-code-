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

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,q,pre[maxx+10],xr[maxx+10][40],f[40] ; 
bool allz(ll l,ll r)
{
   ll temp = pre[r]-pre[l-1] ; 
   if(temp==zz){return true;} return false ; 
}
ll flag = 0 ; 
ll getxor(ll l,ll r)
{
   ll ans = 0 ; 
   for (ll i = 0; i < 35 ; ++i)
   {
      ll k = xr[r][i]-xr[l-1][i] ; 
      if(k==(r-l+qq)){flag=1;}
      ll add = qq << i ; 
      if( (k%2LL)==qq )
      {
         ans+=add ; 
      }
   }
   return ans ; 
}
int main()
{
   debugMode();
   std::vector < pii > ques ;
   ll sum = 0 ; 
   cin >> n >> q ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      sum+=ar[i+1] ; 
      pre[i+1] = sum ; 
   }
   for (int i = 0; i < q ; ++i)
   {
       int l,r ;
       cin >> l >> r ; 
       ques.push_back({l,r}) ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      ll x = ar[i+1] ; 
      ll idx = 0 ; 
      while(idx<35)
      {
         ll temp = qq << idx ; 
         if( (x&temp)!=zz )
         {
            f[idx]++ ; 
         }
         idx++ ; 
      }
      for (int j = 0; j < 35 ; ++j )
      {
         xr[i+1][j] = f[j] ; 
      }
   }
   for(auto p : ques)
   {
      ll l = p.ff ; 
      ll r = p.ss ;
      if(allz(l,r))
      {
         cout << "0" << endl ; continue ; 
      }
      ll len = r-l+qq ; 
      ll val = getxor(l,r) ; 
      if((len%2LL)==qq)
      {
         if(val==zz)
         {
            cout << "1" << endl ;
         }
         else
         {
            if(len==q)
            {
               cout << "-1" << endl ;
            }
            else if(len>4LL)
            {
               cout << "2" << endl ;
            }
            else
            {
               flag = 0 ; 
               getxor(l,r) ; 
               if(flag)
               {
                  cout << "3" << endl ;
               }
               else
               {
                  cout << "2" << endl ;
               }
            }
         }
         continue ; 
      }
      if(len==2)
      {
         cout << "-1" << endl ; continue ; 
      }
      if(val==zz)
      {
         if(ar[l]==zz || ar[r]==zz)
         {
            cout << "1" << endl ;
         }
         else
         {
            cout << "2" << endl ; 
         }
      }
      else
      {

      }
   }
   return 0 ;
}