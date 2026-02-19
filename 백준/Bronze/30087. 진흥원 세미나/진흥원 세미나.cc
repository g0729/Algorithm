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

    map<string, string> m;
    m.insert({"Algorithm", "204"});
    m.insert({"DataAnalysis", "207"});
    m.insert({"ArtificialIntelligence", "302"});
    m.insert({"CyberSecurity", "B101"});
    m.insert({"Network", "303"});
    m.insert({"Startup", "501"});
    m.insert({"TestStrategy", "105"});

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << m[s] << "\n";
    }
    return 0;
}