#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,q,pos,best=0,br[maxx+10] ; 
int calco(ll idx,ll ex)
{  
   ll temp=q,f=1,ans=0 ; 
   for(int i=idx;i<=n;i++)
   {
      if(ar[i]<=q && temp==0){return -1;}
      
      if(ar[i]>temp)
      {
         if(temp>0)
         {
            temp
         }
      }
   }
   return ans ; 
}
bool valid(ll ex)
{
   ll temp = q  ; 
   for(int i=n;i>0;i--)
   {
      
      if(ex==0){return true;}
   }
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      pos = mod ; 
      best = 0 ;
      ll ex = 0 ; 
      cin >> n >> q ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         if(ar[i+1]>q){ex++;}
      }
      ll l=1,r=ex+10,add=0 ; 
      while(l<=r)
      {
         ll mid = (l+r)/2 ;
         if(valid(mid))
         {
            add = mid ; 
            l = mid+1 ;  
         }
         else
         {
            r = mid-1 ; 
         }
      }
      //cout << n-(ex-add) << endl ;
      //cout << pos << endl ;
      ll temp = q ; 
      for(int i=1;i<=n;i++)
      {
          if(i>=pos)
          {
             if(ar[i]>temp && temp>0)
             {
                temp-- ; 
                br[i] = 1 ; 
             }
             else if (ar[i]>temp)
             {
                br[i] = 0 ; 
             }
             else
             {
               br[i] = 1 ; 
             }
          }
          else
          {
             if(ar[i]>temp)
             {
                 br[i] = 0 ; 
             }
             else
             {
                 br[i] = 1 ; 
             }
          }
          cout << br[i] ; 
      }
      cout << endl ;
   }
   return 0 ;
}