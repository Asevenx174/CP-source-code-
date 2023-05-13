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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
string a,b ;
int p,q ; 
bool valid()
{
   for (int i = 1 ; i < p ; ++i)
   {
      for (int j = 1 ; j < q ; ++j)
      {
         if(a[i]==b[j] && a[i-1]==b[j-1])
         {
            cout << "YES" << endl ; 
            string temp = "*" ;
            temp+=a[i-1] ; 
            temp+=a[i] ; 
            temp+="*" ; 
            cout << temp << endl ; 
            return true ; 
         }
      }
   }
   return false ; 
}
void solve()
{
   cin >> a >> b ; 
   p = a.size() ; 
   q = b.size() ; 
   if(a[0]==b[0])
   {
      cout << "YES" << endl ; 
      cout << a[0] << "*" << endl ;
   }
   else if(a[p-1]==b[q-1])
   {
      cout << "YES" << endl ;
      cout << "*" << a[p-1] << endl ;
   }
   else if(!valid())
   {
      cout << "NO" << endl ;
   }
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}