#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007
vector<int> tree;

int init(int start, int end, int node)
{
	if (start == end)
		return tree[node] = 1;
	int mid = (start + end) / 2;

	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
int update(int start, int end, int node, int idx)
{
	if (idx < start || idx > end)
		return tree[node];

	if (start == end)
		return tree[node] = 0;

	int mid = (start + end) / 2;

	return tree[node] = update(start, mid, node * 2, idx) + update(mid + 1, end, node * 2 + 1, idx);
}

int search(int start, int end, int node, int val)
{
	if (start == end)
		return start;

	int mid = (start + end) / 2;

	if (tree[node * 2] > val)
		return search(start, mid, node * 2, val);
	else
		return search(mid + 1, end, node * 2 + 1, val - tree[node * 2]);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	tree = vector<int>(4 * (n + 1));
	vector<int> v(n + 1);
	init(0,n-1,1);

	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		int idx = search(0, n - 1, 1, a);
		update(0, n - 1, 1, idx);
		v[idx] = i;
	}
	
	for (int i = 0; i <n; i++)
	{
		cout<<v[i]<<"\n";
	}
	
	return 0;
}