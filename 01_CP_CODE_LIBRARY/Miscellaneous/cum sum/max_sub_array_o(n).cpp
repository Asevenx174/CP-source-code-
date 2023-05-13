#include<bits\stdc++.h>
using namespace std ;
int arr[10],s[10];
int main()
{
    int n,maxx=-10000,minn=10000,result=-1000; cin >> n ;
    for(int i=1;i<=n;i++)
    {
        int x ; cin >> x ; arr[i]=x;
        s[i]= s[i-1]+x;
        minn=min(minn,x);
        maxx=max(maxx,x);
    }
   /* for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            maxx=max(maxx,s[j]-s[i-1]);///if we find out the lowest s[i-1] dont need i loop
        }
    }*/
    /*for(int j=1;j<=n;j++)
    {
        result=max(result,s[j]-minn);
    }*/
    //cout << result << endl;
    cout << maxx-minn << endl;
    return 0;
}
