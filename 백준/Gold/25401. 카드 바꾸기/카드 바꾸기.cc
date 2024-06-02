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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int answer = 1e9;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = v[j] - v[i];
            if (diff % (j - i) != 0)
                continue;

            diff = (v[j] - v[i]) / (j - i);

            int start = v[i] - diff * i;
            int cnt = 0;
            for (int k = 0; k < n; k++)
            {
                int now = start + diff * k;
                if (v[k] != now)
                    cnt++;
            }
            answer = min(answer, cnt);
        }
    }

    cout << answer;
    return 0;
}