#include <bits/stdc++.h>
using namespace std;


long dist(pair<long, long> p1,
      pair<long, long> p2)
{
   long x0 = p1.first - p2.first;
   long y0 = p1.second - p2.second;
   return x0 * x0 + y0 * y0;
}

// Function to find the maximum
// distance between any two points
double maxDist(pair<long, long> p[], int n)
{
   double Max = 0;

   // Iterate over all possible pairs
   for(int i = 0; i < n; i++)
   {
      for(int j = i + 1; j < n; j++)
      {
         
         // Update max
         Max = max(Max, (double)dist(p[i],
                              p[j]));
      }
   }

   // Return actual distance
   return sqrt(Max);
}

// Driver code
int main()
{
   
   // Number of points
   int n = 5;

   pair<long, long> p[n];

   // Given points
   p[0].first = 4, p[0].second = 0;
   p[1].first = 0, p[1].second = 2;
   p[2].first = -1, p[2].second = -7;
   p[3].first = 1, p[3].second = 10;
   p[4].first = 2, p[4].second = -3;

   // Function call
   cout << fixed << setprecision(14)
      << maxDist(p, n) <<endl;

   return 0;
}

// This code is contributed by divyeshrabadiya07
