#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000001
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
    vector<int> v(MAX);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < b; j++)
            v[j]++;
    }
    int left = 0, right = 0, sum = 0;

    while (left <= right && right < MAX)
    {
        if (sum == k)
        {
            cout << left << " " << right;
            return 0;
        }
        else if (sum < k)
        {
            sum += v[right];
            right++;
        }
        else if (sum > k)
        {
            sum -= v[left];
            left++;
        }
    }
    cout << "0 0";
    return 0;
}