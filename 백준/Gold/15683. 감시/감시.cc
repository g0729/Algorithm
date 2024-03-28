#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int, int>> cctv;
int MAP[8][8];
int CMAP[8][8];
int n, m;
int res = 10000;
void reset()
{
   for (int i = 0; i < n; i++)
   {
      for (int q = 0; q < m; q++)
      {
         CMAP[i][q] = MAP[i][q];
      }
   }
}
void simul2(int x, int y, int dir)
{
   if (dir == 0)
   {
      for (int i = x - 1; i >= 0; i--)
      {
         if (CMAP[i][y] == 6)
            break;
         if (CMAP[i][y] != 0)
            continue;
         CMAP[i][y] = -1;
      }
   }
   else if (dir == 1)
   {
      for (int i = y + 1; i < m; i++)
      {
         if (CMAP[x][i] == 6)
            break;
         if (CMAP[x][i] != 0)
            continue;
         CMAP[x][i] = -1;
      }
   }
   else if (dir == 2)
   {
      for (int i = x + 1; i < n; i++)
      {
         if (CMAP[i][y] == 6)
            break;
         if (CMAP[i][y] != 0)
            continue;
         CMAP[i][y] = -1;
      }
   }
   else if (dir == 3)
   {
      for (int i = y - 1; i >= 0; i--)
      {
         if (CMAP[x][i] == 6)
            break;
         if (CMAP[x][i] != 0)
            continue;
         CMAP[x][i] = -1;
      }
   }
}
void simul(int x, int y, int kind, int dir)
{
   if (kind == 1)
   {
      if (dir == 0)
      {
         simul2(x, y, 0);
      }
      else if (dir == 1)
      {
         simul2(x, y, 1);
      }
      else if (dir == 2)
      {
         simul2(x, y, 2);
      }
      else
      {
         simul2(x, y, 3);
      }
   }
   else if (kind == 2)
   {
      if (dir == 0 || dir == 2)
      {
         simul2(x, y, 0);
         simul2(x, y, 2);
      }
      else
      {
         simul2(x, y, 1);
         simul2(x, y, 3);
      }
   }
   else if (kind == 3)
   {
      if (dir == 0)
      {
         simul2(x, y, 0);
         simul2(x, y, 1);
      }
      else if (dir == 1)
      {
         simul2(x, y, 1);
         simul2(x, y, 2);
      }
      else if (dir == 2)
      {
         simul2(x, y, 2);
         simul2(x, y, 3);
      }
      else
      {
         simul2(x, y, 0);
         simul2(x, y, 3);
      }
   }
   else if (kind == 4)
   {
      if (dir == 0)
      {
         simul2(x, y, 0);
         simul2(x, y, 1);
         simul2(x, y, 2);
      }
      else if (dir == 1)
      {
         simul2(x, y, 1);
         simul2(x, y, 2);
         simul2(x, y, 3);
      }
      else if (dir == 2)
      {
         simul2(x, y, 2);
         simul2(x, y, 3);
         simul2(x, y, 0);
      }
      else
      {
         simul2(x, y, 3);
         simul2(x, y, 0);
         simul2(x, y, 1);
      }
   }
   else if (kind == 5)
   {
      simul2(x, y, 0);
      simul2(x, y, 1);
      simul2(x, y, 2);
      simul2(x, y, 3);
   }
}
int check()
{
   for (int i = 0; i < cctv.size(); i++)
   {
      int x = get<0>(cctv[i]);
      int y = get<1>(cctv[i]);
      int kind = get<2>(cctv[i]);
      int dir = get<3>(cctv[i]);
      simul(x, y, kind, dir);
   }
   int cnt = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (CMAP[i][j] == 0)
            cnt++;
      }
   }

   return cnt;
}
void dfs(int cnt)
{
   if (cnt == cctv.size())
   {
      int temp = check();
      res = min(res, temp);
      reset();
      return;
   }

   for (int i = 0; i < 4; i++)
   {
      get<3>(cctv[cnt]) = i;
      dfs(cnt + 1);
   }
   return;
}
int main()
{
   cin >> n >> m;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         cin >> MAP[i][j];
         if (MAP[i][j] >= 1 && MAP[i][j] <= 5)
         {
            cctv.push_back({i, j, MAP[i][j], 0});
         }
      }
   }
   reset();
   dfs(0);
   cout << res;
}