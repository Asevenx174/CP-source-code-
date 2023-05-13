#include<bits\stdc++.h>
using namespace std ;
int main()
{
    int n,len,q;
    cin >> n >> q;
    len = (int)sqrt(n+.0)+1;
    vector < int > a(n+2);
    vector < int > b(len,0);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x ;
        a[i]=x;
        b[i/len]+=x;
    }
    while(q--)
    {
        int l,r,left,right,sum=0;
        cin >> l >> r ;
        left=l/len,right=r/len;
        if(left==right)
        {
            for(int i=l;i<=r;i++){sum+=a[i];}
        }
        else
        {
            for(int i=l;i<(left+1)*len;i++){sum+=a[i];}
            for(int i=left+1;i<right;i++){sum+=b[i];}
            for(int i=right*len;i<=r;i++){sum+=a[i];}
        }
        cout << sum << endl;
    }
    return 0;
}
