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

    while (true) {
        string s;
        cin >> s;

        if (s == "animal")
            cout << "Panthera tigris\n";
        else if (s == "flower")
            cout << "Forsythia koreana\n";
        else if (s == "tree")
            cout << "Pinus densiflora\n";
        else if (s == "end")
            break;
    }
    return 0;
}