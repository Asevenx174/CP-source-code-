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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,k,b,s ;
      cin >> n >> k >> b >> s ;
      ll l = b*k ; 
      ll ex = max(0LL,s-l) ; 
      if(l<=s && ex<=(k-1)*n)
      {
         ll temp = b ; 
         for(int i=1;i<n;i++)
         {
            ll add = 0 ; 
            if(temp>0){add=k;}
            ar[i] = add ; 
            temp-- ; 
         } 
         ll add = 0 ; 
         if(temp>0){add=temp*k;}
         ar[n] = add ;  
         for(int i=1;i<=n;i++)
         {
            add = min(k-1,ex) ; 
            ex-=add ; 
            ar[i]+=add ; 
         }
         for (int i = 0; i < n ; ++i)
         {
            if(i>0){cout << " " ;}
            cout << ar[i+1] ; 
         }
         cout << endl ; 
      }
      else
      {
         cout << "-1" << endl ;
      }
   }
   return 0 ;
}