#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 1000010

vector<int> tree(4 * (MAX + 1));
vector<int> Sumtree(4 * (MAX + 1));

int Sumupdate(int start, int end, int node, int idx, int val)
{
    if (idx < start || idx > end)
        return Sumtree[node];

    if (start == end)
        return Sumtree[node] += val;

    int mid = (start + end) / 2;

    return Sumtree[node] = Sumupdate(start, mid, node * 2, idx, val) + Sumupdate(mid + 1, end, node * 2 + 1, idx, val);
}
int update(int start, int end, int node, int idx, int val)
{
    if (idx < start || idx > end)
        return tree[node];
    if (start == end)
        return tree[node] += val;

    int mid = (start + end) / 2;

    int leftChild = update(start, mid, node * 2, idx, val);
    int rightChild = update(mid + 1, end, node * 2 + 1, idx, val);

    if (leftChild >= 1 && rightChild >= 1)
        return tree[node] = 1;
    else
        return tree[node] = 0;
}

int search(int start, int end, int node)
{
    if (start == end)
        return start;

    int mid = (start + end) / 2;

    if (tree[node * 2] >= 1)
        return search(mid + 1, end, node * 2 + 1);
    else
        return search(start, mid, node * 2);
}
int sum(int start, int end, int node, int left, int right)
{
    if (right < start || left > end)
        return 0;

    if (left <= start && end <= right)
        return Sumtree[node];

    int mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a == 1)
        {
            update(1, MAX, 1, b, 1);
            Sumupdate(1, MAX, 1, b, 1);
        }
        else
        {
            update(1, MAX, 1, b, -1);
            Sumupdate(1, MAX, 1, b, -1);
        }
        int temp=search(1,MAX,1)-1;
        cout<<sum(1,MAX,1,1,temp)<<"\n";
    }

    return 0;
}