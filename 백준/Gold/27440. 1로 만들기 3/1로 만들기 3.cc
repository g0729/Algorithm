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

    ll n;
    cin >> n;
    set<ll> se;
    queue<ll> q;
    q.push(n);
    se.insert(n);
    int res = 0;
    while (!q.empty()) {
        bool flag = false;
        int size = q.size();
        while (size--) {
            ll cur = q.front();
            q.pop();

            if (cur == 1) {
                flag = true;
                break;
            }

            if (cur % 3 == 0 && se.find(cur / 3) == se.end()) {
                q.push(cur / 3);
                se.insert(cur / 3);
            }
            if (cur % 2 == 0 && se.find(cur / 2) == se.end()) {
                q.push(cur / 2);
                se.insert(cur / 2);
            }
            if (se.find(cur - 1) == se.end()) {
                q.push(cur - 1);
                se.insert(cur / 1);
            }
        }
        if (flag) break;
        res++;
    }

    cout << res;
    return 0;
}