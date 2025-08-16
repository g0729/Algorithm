#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 30000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<int> tree(4 * MAX);
vector<int> lazy(4 * MAX);

void update_lazy(int start, int end, int node) {
    if (lazy[node] != 0) {
        tree[node] = lazy[node];
        if (start != end) {
            lazy[node * 2] = lazy[node];
            lazy[node * 2 + 1] = lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int start, int end, int node, int left, int right, int val) {
    update_lazy(start, end, node);
    if (left > end || right < start) return;

    if (left <= start && end <= right) {
        if (start != end) {
            lazy[node * 2] = val;
            lazy[node * 2 + 1] = val;
        }
        tree[node] = val;
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, node * 2, left, right, val);
    update(mid + 1, end, node * 2 + 1, left, right, val);
}
int search(int start, int end, int node, int idx) {
    update_lazy(start, end, node);
    int mid = (start + end) / 2;
    if (start == end) return tree[node];

    if (start <= idx && idx <= mid)
        return search(start, mid, node * 2, idx);
    else
        return search(mid + 1, end, node * 2 + 1, idx);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    vector<ll> points;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        points.push_back(v[i].first);
        points.push_back(v[i].second);
    }

    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    map<ll, int> ma;

    for (int i = 0; i < points.size(); i++) {
        ma[points[i]] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        update(1, points.size(), 1, ma[v[i].first], ma[v[i].second], i + 1);
    }
    set<int> se;
    for (int i = 0; i <= points.size(); i++) {
        int val = search(1, points.size(), 1, i);
        if (val == 0) continue;
        se.insert(val);
    }

    cout << se.size();
    return 0;
}