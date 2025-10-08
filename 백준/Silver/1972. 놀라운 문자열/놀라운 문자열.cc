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
        if (s == "*") break;

        bool flag = false;
        for (int i = 1; i < s.length(); i++) {
            set<string> se;

            for (int j = 0; j + i < s.length(); j++) {
                string temp;
                temp.push_back(s[j]);
                temp.push_back(s[j + i]);
                if (se.find(temp) != se.end()) {
                    flag = true;
                    break;
                }

                se.insert(temp);
            }

            if (flag) break;
        }

        cout << s << " is ";
        if (flag) cout << "NOT ";
        cout << "surprising.\n";
    }
    return 0;
}