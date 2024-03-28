#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int arr[MAX];
bool visited[MAX];
int n;
int bfs()
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    while (!q.empty())
    {
        int now = q.front().first;
        int time = q.front().second;
        q.pop();
        int next[3];
        if (now % 3 == 0)
            next[0] = now / 3;
        else
            next[0] = -1;
        if (now % 2 == 0)
            next[1] = now / 2;
        else
            next[1] = -1;
        next[2] = now - 1;
        for (int i = 0; i < 3; i++)
        {
            if (next[i] != -1 && !visited[next[i]])
            {
                q.push({next[i], time + 1});
                visited[next[i]] = true;
                arr[next[i]] = now;
                if (next[i] == 1)
                    return time + 1;
            }
        }
    }
    return 0;
}
void print(int parent)
{
    if (arr[parent] == -1)
        return;

    print(arr[parent]);
    cout << arr[parent] <<" ";
}
int main()
{

    cin >> n;
    arr[n] = -1;
    visited[n] = true;

    int time = bfs();
    cout << time << "\n";
    print(1);
    cout<<"1";
}