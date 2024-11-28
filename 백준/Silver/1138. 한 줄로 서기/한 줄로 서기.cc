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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int idx = -1;
        for (int j = 0; j < n; j++)
        {
            if (v[j] == 0)
                idx++;
            if (idx == a)
            {
                v[j] = i + 1;
                break;
            }
        }
    }
    for (auto it : v)
        cout << it << " ";
    return 0;
}