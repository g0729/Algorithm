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
    set<int> se;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (i == 0) continue;

        bool flag = false;
        for (auto b : se) {
            if ((a - 1) % b == 0) {
                flag = true;
                break;
            }
        }

        if (!flag) se.insert(a - 1);
    }

    cout << (int)se.size();
    return 0;
}