#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
int length;
void f(int level, vector<vector<char>> &v)
{
    if (level == n)
        return;

    int x = level * 2;
    int cur_len = length - level * 4;

    for (int i = x; i < x + cur_len; i++)
    {
        v[x][i] = '*';
        v[i][x] = '*';
        v[x + cur_len - 1][i] = '*';
        v[i][x + cur_len - 1] = '*';
    }

    f(level + 1, v);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    length = n * 4 - 3;
    vector<vector<char>> v(length, vector<char>(length, ' '));
    f(0, v);
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << v[i][j];
        }
        cout << "\n";
    }

    return 0;
}