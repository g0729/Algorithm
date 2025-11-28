#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
vector<int> dp(MAX + 1);
vector<int> before(MAX + 1);
void makeCandidates(vector<string> &v, int len, int idx, string s) {
    if (idx == len) {
        v.push_back(s);
        return;
    }

    string temp = s + "4";
    makeCandidates(v, len, idx + 1, temp);
    temp = s + "7";
    makeCandidates(v, len, idx + 1, temp);
}

void bfs(vector<int> &candidates) {

    queue<int> q;

    for (auto &a : candidates) q.push(a);

    while (!q.empty()) {
        int size = q.size();

        int cur = q.front();
        q.pop();

        for (auto &candidate : candidates) {
            int next = cur + +candidate;

            if (next <= 0 || next > MAX) continue;

            if (dp[next] != 0) continue;
            dp[next] = dp[cur] + 1;
            before[next] = cur;
            q.push(next);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> v;

    for (int i = 1; i <= 6; i++) makeCandidates(v, i, 0, "");

    vector<int> candidates;
    for (auto &s : v) candidates.push_back(stoi(s));

    for (auto &a : candidates) dp[a] = 1;

    bfs(candidates);

    vector<int> orders;
    int now = n;
    while (before[now] != 0) {
        int diff = now - before[now];
        orders.push_back(diff);
        now = before[now];
    }
    orders.push_back(now);

    if (dp[n] == 0) {
        cout << "-1";
        return 0;
    }
    sort(orders.begin(), orders.end());

    for (auto &a : orders) cout << a << " ";
    return 0;
}