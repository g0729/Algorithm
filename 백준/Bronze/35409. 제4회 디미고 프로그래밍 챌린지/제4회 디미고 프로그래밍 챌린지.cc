#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int t[8][2] = {{390, 540}, {590, 600}, {650, 660}, {710, 720}, {770, 830}, {880, 890}, {940, 950}, {1000, 1370}};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;
    int temp = a * 60 + b;

    for (int i = 0; i < 8; i++) {
        if (temp >= t[i][0] && temp <= t[i][1]) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
    return 0;
}