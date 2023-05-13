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
const ll maxx = 1e5+10,mod=6,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],pr[maxx+10][mod+10],sum[mod+5] ; 
bool valid(ll l,ll r,ll k)
{
   ll x = 0 ; 
   if(k==0)
   {
      x = ar[l] ; 
   }
   else
   {
      x = ar[r] ; 
   }
   ll idx = 0 ; 
   while(idx<=mod)
   {
      ll temp = qq << idx ; 
      if(temp>x){break;}
      if( (temp&x)!=zz )
      {
         ll f = pr[r][idx]-pr[l-1][idx] ; 
         //if(f==0 && l==1){cout << l << " " << r << " " << idx << " " << f << endl ;}
         if(f%2LL==zz){return false;}
      }
      else if(f==0 && l==1)
      {
         cout << l << " " << r << " " << idx << endl ;
      }
      idx++ ; 
   }
   return true ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,q ;
      cin >> n >> q ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      for (int i = 0; i < n+5 ; ++i)
      {
         for (int  j=0; j < mod+2; ++j )
         {
             pr[i][j] = 0 ;
             sum[j] = 0 ; 
         }
      } 
      ll l,r ;
      cin >> l >> r ; 
      for(int i=1;i<=n;i++)
      {
         ll x = ar[i] ; 
         ll idx = 0 ; 
         //cout << i << "->>" << endl ;
         while(idx<=mod)
         {
            ll temp = qq << idx ; 
            if(temp>x){break;}
            ll add = 0 ; 
            if( (temp&x)!=zz )
            {
               add = qq ; 
            }
            pr[i][idx] = sum[idx]+add ; 
            sum[idx]+=add ;
            idx++ ; 
         }
         //cout << sum[0] << " " << sum[1] << " " << sum[2] << " " << sum[3] << endl ;
      }
      while(l<r)
      {
         if(valid(l,r,0))
         {
            l++ ; 
         }
         else{break;}
      }
      while(l<r)
      {
         if(valid(l,r,1))
         {
            r-- ; 
         }
         else{break;}
      }
      cout << l << " " << r << endl ; 
      for (int i = 0; i < mod ; ++i)
      {
         int val = pr[r][i]-pr[l-1][i] ; 
         //cout << i << " " << val << endl ; 
      }
   }
   return 0 ;
}