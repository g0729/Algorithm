#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int cnt[2][7];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int n, k;

   cin >> n >> k;

   for (int i = 0; i < n; i++)
   {
      int s, y;
      cin >> s >> y;
      cnt[s][y]++;
   }

   int res = 0;

   for (int i = 0; i < 2; i++)
   {
      for (int j = 1; j <= 6; j++)
      {
         if (cnt[i][j] == 0)
            continue;
         res = res + ((cnt[i][j] - 1) / k+1);
      }
   }

   cout << res;
   return 0;
}  