#include<bits\stdc++.h>
using namespace std ;
int main()
{
    int N;
    int matrix[100][100]; //এই সর্বোচ্চ ১০০ নোডের গ্রাফ স্টোর করা যাবে।

 //ডিক্লেয়ার করার পরে ইনপুট নেবার পালা। খুব সহজ কাজ:
 ///here i=0 is neglected
    scanf("%d",&N);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            scanf("%d",&matrix[i][j]);
    return 0;
}
