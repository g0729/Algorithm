#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 500000

vector<ll> tree(4 * MAX);
ll update(int start, int end, int node, int idx)
{
    if (idx < start || idx > end)
        return tree[node];

    if (start == end)
        return tree[node] = 1;

    int mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, idx) + update(mid + 1, end, node * 2 + 1, idx);
}

ll sum(int start, int end, int node, int left, int right)
{
    if (right < start || left > end)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k;

    cin >> n >> k;

    vector<pair<int, int>> v1;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v1.push_back({a, i});
    }

    vector<pair<int, int>> v2 = v1;

    sort(v2.begin(), v2.end());

    vector<int> v3(n);

    for (int i = 0; i < n; i++)
        v3[v2[i].second] = i;

    ll now = 0;

    for (int i = 0; i < n; i++)
    {
        update(0, MAX, 1, v3[i]);
        int temp = sum(0, MAX, 1, v3[i] + 1, MAX);
        if (temp == 0)
            continue;
        if (now + temp + 1 < k)
            now += temp + 1;
        else
        {
            vector<int> temp2;
            int temp3 = k - now;
            for (int j = 0; j < i ; j++)
                temp2.push_back(v1[j].first);
            sort(temp2.begin(), temp2.end());

            for (int j = i; j < n; j++)
                temp2.push_back(v1[j].first);

            int cnt = 0;
            int temp4 = temp2[i];
            int idx;
            for (idx = i - 1; idx >= 0 && cnt < temp3; idx--, cnt++)
            {
                if (temp3 < temp2[idx])
                    temp2[idx + 1] = temp2[idx];
                else
                    break;
            }
            if (cnt < temp3)
                temp2[idx+1] = temp4;

            cout<<temp2[idx+1];
            return 0;
        }
    }

    cout << "-1";

    return 0;
}