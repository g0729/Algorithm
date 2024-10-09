#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
vector<int> v;
bool check(int target)
{
    int safe = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int left = v[i] - target, right = v[i] + target;
        if (safe < left)
            return false;
        else
            safe = right;
    }

    return safe >= n;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int left = 0, right = n;

    while (left + 1 < right)
    {
        int mid = (left + right) / 2;

        if (check(mid))
            right = mid;
        else
            left = mid;
    }

    cout << right;
    return 0;
}