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

string longDivision(string number, int divisor)
{
  string ans;

  int idx = 0;
  int temp = number[idx] - '0';
  while (temp < divisor)
    temp = temp * 10 + (number[++idx] - '0');

  while (number.size() > idx) {
    ans += (temp / divisor) + '0';

    temp = (temp % divisor) * 10 + number[++idx] - '0';
  }

  if (ans.length() == 0)
    return "0";

  return ans;
}



int main()
{
   debugMode();
   ll k ;
   cin >> k ;
  
   return 0 ;
}