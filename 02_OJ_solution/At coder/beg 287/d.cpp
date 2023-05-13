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
const ll maxx = 3e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
bool l[maxx],r[maxx] ; 
void solve()
{
   string s,t ; 
   cin >> s >> t ; 
   int a = s.size() ; 
   int b = t.size() ; 
   for (int i = 0; i < b ; ++i)
   {
      if(i==0)
      {
         if(s[i]==t[i] || s[i]=='?' || t[i]=='?')
         {
            l[i] = true ; 
         }
      }
      else if(l[i-1])
      {
         if(s[i]==t[i] || s[i]=='?' || t[i]=='?')
         {
            l[i] = true ; 
         }
      }
   }
   int i = a-1 ; 
   int temp = b ; 
   while(temp--)
   {
      if(i==a-1)
      {
         if(s[i]==t[temp] || s[i]=='?' || t[temp]=='?')
         {
            r[i] = true ; 
         }
      }
      else if(r[i+1])
      {
         if(s[i]==t[temp] || s[i]=='?' || t[temp]=='?')
         {
            r[i] = true ; 
         }
      }
      i-- ; 
   }
   for (int i = 0; i <=b  ; ++i)
   {
      int x = i-1 ; 
      int y = a-(b-i) ; 
      int f = 0 ; 
      if(i==0)
      {
         if(r[y]){f=1;}
      }
      else if(i==b)
      {
         if(l[x]){f=1;}
      }
      else
      {
         if(r[y] && l[x]){f=1;}
      }
      if(f)
      {
         cout << "Yes" << endl ;
      }
      else
      {
         cout << "No" << endl ; 
      }
   }
}
int main()
{
   debugMode();
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}