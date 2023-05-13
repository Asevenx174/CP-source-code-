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
ll lr[55],rr[55],qr[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,c,q ;
      cin >> n >> c >> q ; 
      string s ;
      cin >> s ; 
      ll len = s.size() ; 
      for (int i = 0; i < c ; ++i)
      {
         cin >> lr[i+1] >> rr[i+1] ; 
         ll add = rr[i+1]-lr[i+1]+1 ; 
         len+=add ; 
      }
      for(int i=1;i<=q;i++)
      {
         cin >> qr[i] ; 
      }
      ll temp = len ; 
      for(int i=1;i<=q;i++)
      {
         ll k = qr[i] ;
         ll idx = c ; 
         len = temp ; 
         while(idx>0)
         {
               //cout << len << " " << k << endl ;
               if(k<=n)
               {
                  break ; 
               }
               ll add = rr[idx]-lr[idx]+1 ;
               if(len-add>=k)
               {
                  len-=add ; idx-- ; continue ; 
               }
               len-=add ; 
               ll ex = k-len ; 
               k = lr[idx]+ex-1 ;  
               idx-- ;  
         }
         cout << s[k-1] << endl ;
      }
   }
   return 0 ;
}