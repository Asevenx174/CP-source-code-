#include<bits\stdc++.h>
using namespace std ;
void gener(char *arr,int n)
{
    int num= pow(2,n);
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i &(1 << j))
            {
                cout <<  " " << arr[j] ;
            }
        }
        cout << endl;
    }
}
int main()
{
   char arr[]={'a','b','c'};
   gener(arr,3);
   return 0 ;
}
