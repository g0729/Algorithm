#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({b, c});
    }

    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<>> pq;

    int res = 0;

    for (int i = 0; i < n; i++) {
        int start = v[i].first;
        int end = v[i].second;

        while (!pq.empty() && pq.top() <= start) pq.pop();

        pq.push(end);

        res = max(res, (int)pq.size());
    }

    cout << res;
    return 0;
}