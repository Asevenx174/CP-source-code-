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
ll inv(ll x)
{
   ll idx = 0 ; 
   while( (qq << idx) <= x )
   {
      idx++ ; 
   }
   ll temp = qq << idx ; 
   temp-- ; 
   ll ans = temp^x ; 
   return ans ; 
}
ll ar[maxx+10],n,br[maxx+10],pos ; 
bool used[maxx+10] ; 
bool valid(ll val,ll as)
{
   for(int i=1;i<=n;i++)
   {
      //cout << val << " ??  " << ar[i] << " " << br[i] << endl ;
      if(used[i]){continue;}
      if((ar[i]&val)==val)
      {
         if(as){ br[pos++] = i ; used[i] = true ; } 
         return true ; 
      }
   }
   return false ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      pos = 1 ; 
      cin >> n ;
      ll best = 0 ; 
      ll idx = 0 ; 
      set < int > s ; 
      for (int i = 0; i < n ; ++i)
      {
         used[i+1] = false ; 
         s.insert(i+1) ; 
         br[i+1] = mod ; 
         cin >> ar[i+1] ; 
         if(ar[i+1]>best)
         {
            best = ar[i+1] ; 
            idx = i+1 ; 
         }
      }
      if(best==0)
      {
         for (int i = 0; i < n ; ++i)
         {
            if(i>0){cout << " " ;}
            cout << "0" ; 
         }
         cout << endl ;
         continue ; 
      }
      br[pos++] = idx ; 
      used[idx] = true ; 
      ll gap = inv(best),f=1 ; 
      //cout << gap << endl ;
      while(gap>0)
      {
         ll add = 0 ; 
         for(ll i=30;i>=0;i--)
         {
            ll temp = qq << i ; 
            if((gap&temp)!=zz)
            {
               //cout << gap << " --> " << add+temp << endl ;
               if(valid(add+temp,0))
               {
                  add+=temp ; 
               }
            }
         }
         if(add==zz){break;}
         bool hd = valid(add,1) ; 
         gap-=add ; 
      }
      idx = 0 ; 
      for(int i=1;i<=n;i++)
      {
         if(idx>0){cout << " ";}
         if(i<pos)
         {
            cout << ar[ br[i] ] ; 
            //cout << br[i] << endl ;
            s.erase(s.find(br[i])) ; 
         }
         else
         {
            auto it = s.begin() ; 
            cout << ar[*it] ; 
            s.erase(it) ; 
         }
         idx = 1 ; 
      }
      cout << endl ;
   }
   return 0 ;
}