#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    queue<int> q;
    for (int i = 1; i < n + 1; i++)
    {
        q.push(i);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            q.push(q.front());
            q.pop();
        }
        v[q.front()] = i;
        q.pop();
    }

    for (int i = 1; i < n + 1; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}