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

    string a, b;
    cin >> a >> b;
    int res = 0;
    for (int i = 0; i <= b.length() - a.length(); i++) {
        int temp = 0;
        for (int j = 0; j < a.length(); j++) {
            if (a[j] == b[i + j]) temp++;
        }
        res = max(res, temp);
    }

    cout << a.length() - res;
    return 0;
}