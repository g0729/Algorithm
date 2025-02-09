#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
vector<vector<int>> v;

int f(int x, int y, int len)
{
    if (len == 2)
    {
        vector<int> temp;
        for (int i = x; i < x + len; i++)
        {
            for (int j = y; j < y + len; j++)
                temp.push_back(v[i][j]);
        }
        sort(temp.begin(), temp.end());
        return temp[1];
    }
    else
    {
        vector<int> temp;
        temp.push_back(f(x, y, len / 2));
        temp.push_back(f(x + len / 2, y, len / 2));
        temp.push_back(f(x, y + len / 2, len / 2));
        temp.push_back(f(x + len / 2, y + len / 2, len / 2));
        sort(temp.begin(), temp.end());
        return temp[1];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        v.push_back(temp);
    }
    if (n == 1)
    {
        cout << v[0][0];
        return 0;
    }
    cout << f(0, 0, n);
    return 0;
}