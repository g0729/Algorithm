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

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vector<int> answer(n + 1);
    answer.back() = -1;
    int idx = -1;
    for (int i = n - 1; i > 0; i--)
    {
        if (v[i] == v[i + 1])
            answer[i] = idx;
        else
        {
            answer[i] = i + 1;
            idx = i + 1;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << answer[i] << " ";
    return 0;
}