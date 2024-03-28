#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
#define lint long long

vector<int> v[100000];
int arr[100000];
int n, k;
void bfs()
{
    queue<int> q;
    int depth = 0;
    q.push(0);

    while (!q.empty())
    {
        int size = q.size();

        for (int j = 0; j < size; j++)
        {
            int now = q.front();
            q.pop();
            if (arr[now] == k)
            {
                cout << depth;
                return;
            }
            for (int i = 0; i < v[now].size(); i++)
            {
                int node = v[now][i];
                q.push(node);
            }
        }

        depth++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bfs();

    return 0;
}