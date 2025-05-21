#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000001
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
set<int> se[MAX];
vector<int> lef(MAX, -1), righ(MAX, INF);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        se[a].insert(b);

        lef[a] = max(lef[a], b);
        righ[b] = min(righ[b], a);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        if (se[a].find(b) != se[a].end())
            cout << "1";
        else if ((lef[a] != -1 && lef[a] >= b) && (righ[b] != -1 && righ[b] <= a))
            cout << "2";
        else
            cout << "-1";

        cout << "\n";
    }

    return 0;
}