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
    vector<int> v(MAX + 1);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[a]++;
    }

    int temp = (n + 1) / 2;
    for (int i = 1; i <= MAX; i++)
    {
        if (temp < v[i])
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}