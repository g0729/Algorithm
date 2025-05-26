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
    vector<int> V(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> V[i];

    vector<pair<int, int>> ans;
    vector<int> v(V);
    for (int i = 0; i < 2; i++)
    {
        int left = 1;
        while (left <= n && v[left] == left)
            left++;
        int right = left;
        while (right <= n && v[right] != left)
            right++;

        if (left > n || right > n)
        {
            ans.push_back({1, 1});
            continue;
        }
        ans.push_back({left, right});
        for (int j = left; j < (left + right + 1) / 2; j++)
            swap(v[j], v[right - j + left]);
    }
    bool flag = true;

    for (int i = 1; i < n - 1; i++)
        if (v[i] + 1 != v[i + 1])
        {
            flag = false;
            break;
        }

    if (flag)
    {

        for (auto &[l, r] : ans)
            cout << l << " " << r << "\n";
        return 0;
    }
    v = V;
    ans.clear();

    for (int i = 0; i < 2; i++)
    {
        int left = 1, right = n;

        while (right >= 1 && v[right] == right)
            right--;

        left = right;

        while (left >= 1 && v[left] != right)
            left--;

        if (left < 0 || right < 0)
        {
            ans.push_back({1, 1});
            continue;
        }

        ans.push_back({left, right});
        for (int j = left; j < (left + right + 1) / 2; j++)
            swap(v[j], v[right - j + left]);
    }

    for (auto &[l, r] : ans)
        cout << l << " " << r << "\n";
    return 0;
}