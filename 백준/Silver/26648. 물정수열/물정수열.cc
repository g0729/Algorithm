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
    vector<int> a(n), b(n), c(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
        cin >> c[i];

    int num = min(a[0], min(b[0], c[0]));
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        vector<int> temp;
        temp.push_back(a[i]);
        temp.push_back(b[i]);
        temp.push_back(c[i]);

        sort(temp.begin(), temp.end());

        if (temp[2] <= num)
        {
            flag = false;
            break;
        }
        num = max(temp[0], num + 1);
    }

    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}