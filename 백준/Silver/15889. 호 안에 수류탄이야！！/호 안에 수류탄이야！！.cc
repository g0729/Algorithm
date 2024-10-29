#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "권병장님, 중대장님이 찾으십니다";
        return 0;
    }
    vector<int> v(n);
    vector<int> range(n - 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> range[i];
    }
    range.push_back(0);
    int reach = range[0];

    for (int i = 1; i < n; i++)
    {
        if (reach < v[i])
        {
            cout << "엄마 나 전역 늦어질 것 같아";
            return 0;
        }
        reach = max(reach, v[i] + range[i]);
    }

    cout << "권병장님, 중대장님이 찾으십니다";
    return 0;
}