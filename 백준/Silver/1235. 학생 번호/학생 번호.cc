#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= v[0].length(); i++)
    {
        set<string> se;
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            string temp = v[j].substr(v[j].length() - i);
            if (se.find(temp) != se.end())
            {
                flag = false;
                break;
            }
            se.insert(temp);
        }
        if (flag)
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}