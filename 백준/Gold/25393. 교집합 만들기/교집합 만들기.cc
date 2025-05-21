#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000001
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
set<int> se[MAX];
vector<int> L(MAX, -1), R(MAX, INF);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        int a, b;
        cin >> a >> b;
        se[a].insert(b);

        L[a] = max(L[a], b);
        R[b] = min(R[b], a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        if (se[a].find(b) != se[a].end())
            cout << "1";
        else if ((L[a] >= b && R[b] <= a))
            cout << "2";
        else
            cout << "-1";

        cout << "\n";
    }

    return 0;
}