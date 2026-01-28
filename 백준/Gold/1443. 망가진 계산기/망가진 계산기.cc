#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int d, p;
ll maxLimit, res;
set<ll> se[31];
void dfs(int cur, ll num) {

    if (cur == p) {
        res = max(res, num);
        return;
    }

    for (int i = 2; i <= 9; i++) {
        ll next = num * i;

        if (next >= maxLimit) break;

        if (se[cur].find(next) != se[cur].end()) continue;

        se[cur].insert(next);
        dfs(cur + 1, next);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> d >> p;

    maxLimit = pow(10LL, d);

    dfs(0, 1);

    cout << (res == 0 ? -1 : res);
    return 0;
}