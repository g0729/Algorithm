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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[i] = (a + 1) % 2;
    }
    int start = 0, end = 0, sum = 0, length = 0;
    int res = 0;
    while (end < n)
    {
        if (v[end] == 0)
        {
            if (sum < k)
            {
                sum++;
                end++;
            }
            else
            {
                if (v[start] == 0)
                    sum--;
                else
                    length--;
                start++;
            }
        }
        else
        {
            end++;
            length++;
        }

        res = max(res, length);
    }

    cout << res;
    return 0;
}