#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007
#define MAX 65535
vector<int> tree(4 * (MAX + 1));
int update(int start, int end, int node, int idx, int val)
{
	if (idx < start || idx > end)
		return tree[node];

	if (start == end)
		return tree[node] += val;

	int mid = (start + end) / 2;
	return tree[node] = update(start, mid, node * 2, idx, val) + update(mid + 1, end, node * 2 + 1, idx, val);
}
lint search(int start, int end, int node, int val)
{
	if (start == end)
		return start;

	int mid = (start + end) / 2;
	if (tree[node * 2] >= val)
		return search(start, mid, node * 2, val);
	else
		return search(mid + 1, end, node * 2 + 1, val - tree[node * 2]);
}
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
		cin >> v[i];
	}

	for (int i = 0; i < k; i++)
	{
		update(0, MAX, 1, v[i], 1);
	}

	int middle = (k + 1) / 2;
	lint res = search(0, MAX, 1, middle);
	for (int i = k; i < n; i++)
	{
		update(0, MAX, 1, v[i], 1);
		update(0, MAX, 1, v[i - k], -1);
		res += search(0, MAX, 1, middle);
	}

	cout << res;
	return 0;
}