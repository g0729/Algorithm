#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 30010

vector<int> cnt(4 * MAX);
vector<int> tree(4 * MAX);

struct cordi
{
    int x, y1, y2;
    bool isEnd;
    cordi(int x, int y1, int y2, bool isEnd) : x(x), y1(y1), y2(y2), isEnd(isEnd){};
};
void update(int start, int end, int node, int left, int right, int val)
{
    if (left > end || right < start)
        return;
    if (left <= start && end <= right)
        cnt[node] += val;
    else
    {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, left, right, val);
        update(mid + 1, end, node * 2 + 1, left, right, val);
    }
    if (cnt[node])
        tree[node] = (end - start + 1);
    else
    {
        if (start == end)
            tree[node] = 0;
        else
        {
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }
}
bool cmp(cordi &a, cordi &b)
{
    return a.x < b.x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<cordi> v;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        v.push_back(cordi(a, b, d - 1, false));
        v.push_back(cordi(c, b, d - 1, true));
    }

    sort(v.begin(), v.end(), cmp);

    int res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (i > 0)
        {
            int diff = v[i].x - v[i - 1].x;
            res += diff * tree[1];
        }
        int val = v[i].isEnd ? 1 : -1;
        update(0, MAX, 1, v[i].y1, v[i].y2, val);
    }

    cout << res;
    return 0;
}