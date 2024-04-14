#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int arr[4];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[a]++;
        v.push_back(a);
    }
    int u, d;
    cin >> u >> d;
    int left = max(0, u - arr[1]) + max(0, d - arr[2]);
    if (left > arr[3])
    {
        cout << "NO";
        return 0;
    }
    else
        cout << "YES\n";
    string s(n, ' ');
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            s[i] = 'U';
            u--;
        }
        else if (v[i] == 2)
        {
            s[i] = 'D';
            d--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 3)
        {
            if (u)
            {
                s[i] = 'U';
                u--;
            }
            else
            {
                s[i] = 'D';
            }
        }
    }

    cout << s;
    return 0;
}