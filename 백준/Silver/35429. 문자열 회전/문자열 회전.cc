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

    int n;
    string s;
    cin >> n >> s;

    vector<int> v(3);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'G')
            v[0]++;
        else if (s[i] == 'H')
            v[1]++;
        else if (s[i] == 'S')
            v[2]++;
    }

    cout << min(v[0], min(v[1], v[2] / 2));
    return 0;
}