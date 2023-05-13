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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx],br[maxx],cr[maxx],n,m ; 
set < int > used[maxx+5],so[maxx] ; 
int ans[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      for (int i = 0; i < maxx ; ++i)
      {
         used[i].clear() ; 
         so[i].clear() ;  
      }
      cin >> n >> m ;
      for(int i=1;i<=n;i++)
      {
         cin >> ar[i] ; 
         so[ar[i]].insert(i) ;  
      }
      for(int i=1;i<=n;i++)
      {
         cin >> br[i] ; 
         if(ar[i]!=br[i])
         {
            used[br[i]].insert(i) ; 
         }
      }
      for(int i=1;i<=m;i++)
      {
         cin >> cr[i] ; 
      }
      int idx = 0 ; 
      for(int i=1;i<=n;i++)
      {
         if(cr[m]==br[i]){idx=i;}
      }
      if(idx==0){cout << "NO" << endl;continue;}
      int f = 0 ; 
      for(int i=1;i<=m;i++)
      {
         int c = cr[i] ; 
         if(used[c].size()>0)
         {
            auto it = used[c].begin() ; 
            int temp = ar[*it] ; 
            ans[i] = *it ; 
            so[temp].erase(so[temp].begin());
            ar[*it]=c ; 
            so[c].insert(*it) ; 
            used[c].erase(it) ; 
         }
         else
         {
            if(so[c].size()==0 || (f==1 && i==m) )
            {
               ans[i]=idx ; 
               f = 1 ; 
               int temp = ar[idx] ;
               so[temp].erase(so[temp].begin());
               ar[idx]=c ; 
               so[c].insert(idx) ; 
            }
            else
            {
               auto it = so[c].begin() ; 
               ans[i] = *it ; 
            }
         }
      }
      int temp=0 ; 
      for(int i=1;i<=n;i++)
      {
         if(ar[i]!=br[i]){temp=1;}
      }
      if(temp==1)
      {
         cout << "NO" << endl ;
      }
      else
      {
         cout << "YES" << endl ;
         for(int i=1;i<=m;i++)
         {
            if(i!=1){cout << " " ; }
            cout << ans[i] ;
         }
         cout << endl ;
      }
   }
   return 0 ;
}