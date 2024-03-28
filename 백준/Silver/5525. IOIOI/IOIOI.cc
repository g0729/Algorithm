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

   int n, m;
   string s;
   cin >> n >> m >> s;

   int res = 0;
   for (int i = 0; i < s.length(); i++)
   {
      if (s[i] == 'O')
         continue;
      else
      {
         int cnt = 0;
         while (s[i + 1] == 'O' && s[i + 2] == 'I')
         {
            cnt++;
            if (cnt == n)
            {
               res++;
               cnt--;
            }
            i += 2;
         }
      }
   }

   cout << res;

   return 0;
}