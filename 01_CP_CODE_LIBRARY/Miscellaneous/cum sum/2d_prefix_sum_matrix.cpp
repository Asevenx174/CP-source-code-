#include<bits\stdc++.h>
using namespace std ;
/*
10 20 30     10 30 60
5  10 20 ->  15 45 95
2  4   6     17 51 107
*/
int arr[5][5],arr2[5][5];
int main()
{
    int n;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x ; cin >> x ; arr[i][j]=x;
            arr2[i][j]= x + arr2[i][j-1] + arr2[i-1][j]-arr2[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
