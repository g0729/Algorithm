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

    int v[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

    int a, b;
    cin >> a >> b;
    int idx = (a - 1) * 2 + b;

    int k;
    cin >> k;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A')
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    swap(v[j][k], v[j + 2][k]);
                }
            }
        }

        else if (s[i] == 'B')
        {
            for (int j = 0; j < 4; j += 2)
            {
                swap(v[j][0], v[j + 1][1]);
                swap(v[j][1], v[j + 1][0]);
            }
        }
        else if (s[i] == 'C')
        {
            swap(v[0][0], v[3][1]);
            swap(v[0][1], v[3][0]);
            swap(v[1][0], v[2][1]);
            swap(v[1][1], v[2][0]);
        }
        else if (s[i] == 'D')
        {
            vector<vector<int>> temp(4, vector<int>(2));
            temp[0][0] = v[1][0];
            temp[0][1] = v[0][0];
            temp[1][0] = v[2][0];
            temp[1][1] = v[0][1];
            temp[2][0] = v[3][0];
            temp[2][1] = v[1][1];
            temp[3][0] = v[3][1];
            temp[3][1] = v[2][1];

            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    v[j][k] = temp[j][k];
                }
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (v[i][j] == idx)
            {
                cout << i + 1 << " " << j + 1;
                return 0;
            }
        }
    }

    return 0;
}