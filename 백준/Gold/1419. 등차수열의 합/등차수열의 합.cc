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

   ll l, r, k;

   cin >> l >> r >> k;

   if (k == 2)
   {
      ll temp;
      if (r < 3)
         temp = 0;
      else if (l < 3)
         temp = r - 2;
      else
         temp = r - l + 1;
      cout << temp;
   }
   if (k == 3)
   {
      ll temp;
      if (r < 6)
         temp = 0;
      else if (l < 6)
         temp = r / 3 - 1;
      else
         temp = r / 3 - (l - 1) / 3;
      cout << temp;
   }
   if (k == 5)
   {
      ll temp;
      if (r < 15)
         temp = 0;
      else if (l < 15)
         temp = r / 5 - 2;
      else
         temp = r / 5 - (l - 1) / 5;
      cout << temp;
   }
   if (k == 4)
   {
      ll temp = 0;
      if (r < 10)
         temp = 0;
      else if (l < 10)
         temp = r / 2 - 4;
      else
      {
         temp = r / 2 - (l - 1) / 2;
      }

      if (l <= 12 && r >= 12)
         temp -= 1;
      cout << temp;
   }
   return 0;
}