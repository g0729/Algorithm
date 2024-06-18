#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    set<string> se;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        string temp = s;
        sort(temp.begin(), temp.end());
        if (se.find(temp) == se.end())
        {
            se.insert(temp);
            v.push_back(s);
        }
    }

    for (auto it : v)
        cout << it << "\n";
    return 0;
}