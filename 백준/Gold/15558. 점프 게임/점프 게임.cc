#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int n, k;
int arr[2][100000];
bool visited[2][100000];

bool bfs()
{
    queue<pair<int, int>> q;
    int t = 0;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            pair<int, int> temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;

            if (y + 1 >= n || y + k >= n)
                return true;

            if (!visited[x][y + 1] && arr[x][y + 1] == 1)
            {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
            }
            if (!visited[x][y - 1] && arr[x][y - 1] == 1 && y - 1 > t)
            {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
            }
            if (!visited[(x + 1) % 2][y + k] && arr[(x + 1) % 2][y + k] == 1)
            {
                q.push({(x+1)%2, y + k});
                visited[(x+1)%2][y + k] = true;
            }
        }
        t++;
    }

    return false;
}
int main()
{

    cin >> n >> k;
    for (int i = 0; i < 2; i++)
    {
        string Inp;
        cin >> Inp;

        for (int j = 0; j < Inp.length(); j++)
        {
            arr[i][j] = Inp[j] - '0';
        }
    }

    cout << bfs();

    return 0;
}