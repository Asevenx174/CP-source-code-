#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> mp;
int main(){
    int t;
    cin>>t;
    while(t--){
        mp.clear();
        int n,k;
        cin>>n>>k;
        ll a[n+1][k+1];
        ll b[n+1][k+1];
        for(int i=1;i<=n;i++){
            ll hash=0;
            for(int j=1;j<=k;j++){
                cin>>a[i][j];
                b[i][a[i][j]] = j;
            }
            for(int j=1;j<=k;j++){
                hash = b[i][j] + 10*hash;
                mp[hash] = 1;
                //cout<<hash<<endl;
            }
        }
        for(int i=1;i<=n;i++){
            ll hash=0,ans=0;
            for(int j=1;j<=k;j++){
                hash = 10 * hash + a[i][j];
                if(mp[hash]==1) ans++;
                else break;
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}