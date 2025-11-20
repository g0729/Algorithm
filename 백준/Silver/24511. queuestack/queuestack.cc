#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque<int> q;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &a : v) cin >> a;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (v[i] == 0) q.push_back(a);
    }

    int m;
    cin >> m;

    while (m--) {
        int a;
        cin >> a;
        q.push_front(a);
        cout << q.back() << " ";
        q.pop_back();
    }

    return 0;
}