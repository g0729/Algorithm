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
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    vector<int> leftMAX(n + 1), rightMAX(n + 2);

    for (int i = 1; i <= n; i++) leftMAX[i] = max(leftMAX[i - 1], v[i]);
    for (int i = n; i >= 1; i--) rightMAX[i] = max(rightMAX[i + 1], v[i]);

    int cntR = 0, cntB = 0;

    for (int i = 1; i < n; i++) {
        if (leftMAX[i] > rightMAX[i + 1])
            cntR++;
        else if (leftMAX[i] < rightMAX[i + 1])
            cntB++;
    }

    cout << (cntR == cntB ? "X" : (cntR > cntB ? "R" : "B"));

    return 0;
}