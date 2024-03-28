#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int n, m, k;
   cin >> n >> m >> k;

   int sum = 0;

   for (int i = 0; i < m; i++)
   {
      int a, b;
      cin >> a >> b;

      sum += b;

      if (sum > k)
      {
         cout << i + 1 << " 1";
         return 0;
      }
   }

   cout << "-1";
   return 0;
}