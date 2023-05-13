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
const ll maxx = 2e5+10,mod=30,imax=(1<<30),qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int sett(int idx,int mask )
{
   mask = mask | (1<< (idx-1)) ; 
   return mask ; 
}
bool check(int idx,int mask )
{
   if( (mask&(1<<(idx-1))) ==0 )
   {
      return false ; 
   }
   return true ; 
}
int n,q,lr[maxx+10],rr[maxx+10],xr[maxx+10] ; 
std::vector < pii > g[maxx+10] ;

std::vector< int > used(maxx+10,imax-1) ; 
bool ch[maxx+10][mod+10],oc[maxx+10] ; 
bool valid(int i,int j,int f)
{
   int temp = qq << j ; 
   for(auto p : g[i] )
   {
      int k = p.ff ; 
      int x = p.ss ; 
      if( (x&temp)!=0 )
      {
         if( (used[k]&temp)==0)
         {
            if(ch[k][j]){return false ;}
            if(f)
            {
               ch[k][j] = true ; 
               used[k]+=temp ; 
            }
         }
      }
   }
   return true ; 
}
int add[maxx+10] ; 
int main()
{
   debugMode();
   cin >> n >> q ;
   for (int i = 0; i < q ; ++i)
   {
      int l,r,x ;
      cin >> l >> r >> x ;  
      lr[i+1] = l ;
      rr[i+1] = r ; 
      xr[i+1] = x ; 
      oc[l] = true ; 
      oc[r] = true ;  

      if(l==r)
      {
         used[l] = x ; 
         for (int j = 0; j < 30 ; ++j)
         {
            ch[l][j] = true ; 
         }
      }
   }
   for(int i=1;i<=q;i++)
   {
      int l = lr[i] ; 
      int r = rr[i] ; 
      int x = xr[i] ; 
      if(l==r){continue;}
      for (int j = 0; j < 30 ; ++j)
      {
         int temp = qq << j ; 
         if( (x&temp)==0 )
         {
            if(!ch[l][j] && (used[l]&temp)!=0 )
            {
               used[l]-=temp ; 
               ch[l][j] = true ; 
            }
            if(!ch[r][j] && (used[r]&temp)!=0 )
            {
               used[r]-=temp ; 
               ch[r][j] = true ; 
            }
         }
      }
      g[l].push_back({r,x}) ;
      g[r].push_back({l,x}) ;
   }
   for(int i=1;i<=n;i++)
   {
      if(!oc[i])
      {
         used[i] = 0 ; 
      }
   }
   for(int i=1;i<=n;i++)
   {
      for (int j = 0; j < 30 ; ++j)
      {
         int temp = qq << j ; 
         if( (used[i]&temp)==0 )
         {
            ch[i][j] = true ;
         }
      }
   }
   for(int i=1;i<=n;i++)
   {
      if(g[i].size()==0){continue;}
      for (int j = 0; j < 30 ; ++j)
      {
         int temp = qq << j ; 
         if( (temp&used[i])==0 || ch[i][j]){continue;}
         if(valid(i,j,0))
         {
            bool st = valid(i,j,1) ; 
            used[i]-=temp ; 
            ch[i][j] = true ; 
         }
      }
   }
   for(int i=1;i<=n;i++)
   {
      if(i>1){cout << " " ;} 
      cout << used[i] ; 
   }
   cout << endl ; 
   return 0 ;
}