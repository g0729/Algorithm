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

    int n, k;
    cin >> n >> k;

    if (n == 1)
    {
        for (int i = 0; i < k; i++)
            cout << "1 ";
    }
    else if (n == 2 && k == 1)
    {
        cout << "1 2";
    }
    else
    {
        cout << "-1";
    }

    return 0;
}