#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v(32);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < b; j++)
            v[j]++;
    }

    int k;
    cin >> k;
    bool flag = true;
    for (int i = 1; i < 32; i++)
    {
        if (v[i] > k)
            flag = false;
    }
    cout << flag << endl;
    return 0;
}