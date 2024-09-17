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
    vector<int> x(n);
    vector<int> y(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        double k;
        cin >> k;
        int idx = lower_bound(x.begin(), x.end(), k) - x.begin();
        if (y[idx] == y[idx - 1] || k == x[idx])
            cout << "0";
        else if (y[idx] > y[idx - 1])
            cout << "1";
        else
            cout << "-1";
        cout << "\n";
    }
    return 0;
}