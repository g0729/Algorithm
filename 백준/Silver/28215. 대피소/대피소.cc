#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
vector<int> nums;
bool isSelected[50];
int n, k;
vector<pair<int, int>> v;
int answer = 1e9;
int dist(pair<int, int> &a, pair<int, int> &b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
void dfs(int idx, int cnt)
{
    if (cnt == k)
    {
        int res = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int temp = 1e9;
            for (int j = 0; j < k; j++)
            {
                temp = min(temp, dist(v[i], v[nums[j]]));
            }
            res = max(res, temp);
        }
        answer = min(answer, res);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (isSelected[i])
            continue;
        isSelected[i] = true;
        nums.push_back(i);
        dfs(i, cnt + 1);
        isSelected[i] = false;
        nums.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> a;
        cin >> a.first >> a.second;
        v.push_back(a);
    }

    dfs(0, 0);

    cout << answer;
    return 0;
}