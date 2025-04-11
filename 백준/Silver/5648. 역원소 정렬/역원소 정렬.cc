#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<ll> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        ll temp = stoll(s);
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for (auto it : v)
        cout << it << "\n";
    return 0;
}