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

int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n,m ;
      cin >> n >> m ;
      std::vector < vector < int > > ar ; 
      ar.resize(n+10, vector<int>(m+10));
      for (int i = 0; i < n ; ++i)
      {
         for (int j = 0; j < m ; ++j)
         {
            int temp ; 
            cin >> temp ; 
            ar[i+1][j+1] = temp ; 
         }
      }
    
      vector < int > pos ; 
      int ans = 0; 
      for(int c=2;c<=m;c++)
      {
         int g=0,l=0 ; 
         for(int r=1;r<=n;r++)
         {
            if(ar[r][c]>ar[r][c-1])
            {
                g = 1 ; 
            }
            else if( ar[r][c]<ar[r][c-1] )
            {
                l = 1 ; 
            }
         }
         if(min(g,l)==1){ans=-1;break;}
         if(l==1)
         {
            pos.push_back(c) ; 
         }
      }
      if(ans==-1 || pos.size()>2)
      {
         cout << "-1" << endl ; continue ; 
      }
      int l=1,r=1 ; 
      auto it = pos.begin() ; 
      if(pos.size()==1)
      {
         r = *it ;
         l = r-1 ; 
         if(l>1){l--;}
         if(r<m){r++;}
         bool sol = false ; 
         for(int i=l;i<r;i++)
         {
            for(int j=i+1;j<=r;j++)
            {
               int flag = 0 ; 
               for(int p=1;p<=n;p++)
               {
                 int a = ar[p][i] ; 
                 int b = ar[p][j] ; 
                 ar[p][i]=b ; 
                 ar[p][j]=a ; 
                 for(int k=l+1;k<=r;k++)
                 {
                    if(ar[p][k]<ar[p][k-1]){flag=1;}
                 }
                 ar[p][i]=a ; 
                 ar[p][j]=b ; 
               }
               if(flag==0){sol=true;l=i;r=j;break;}
            }
         }
         if(!sol){cout << "-1" << endl ; continue ; }
      }
      else if(pos.size()==2)
      {
         l = *it-1 ; 
         it++ ; 
         r = *it ; 
      }
      cout << l << " " << r << endl ;
   }
   return 0 ;
}