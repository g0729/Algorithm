#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000000
#define INF 987654321
int A[MAX * 2 + 2];
int nums[MAX * 2 + 2];
int n;
void f()
{
    int r, p;
    r = p = 0;
    for (int i = 0; i < n; i++)
    {
        if (i <= r)
            A[i] = min(A[2 * p - i], r - i);
        else
            A[i] = 0;
        while ((i - A[i] - 1 >= 0 && i + A[i] + 1 <= n - 1) && nums[i - A[i] - 1] == nums[i + A[i] + 1])
            A[i]++;

        if (r < i + A[i])
        {
            r = i + A[i];
            p = i;
        }
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
        nums[i * 2] = 0;
        cin >> nums[i * 2 + 1];
    }
    n = 2 * n + 1;
    nums[n - 1] = 0;
    f();
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (A[a + b + 1] >= b - a + 1)
            cout << "1";
        else
            cout << "0";
        cout << "\n";
    }
    return 0;
}