#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007
#define MAX 1000001

vector<int> tree(4 * MAX);

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

lint update(int start, int end, int node, int idx, int val)
{
	if (idx < start || idx > end)
		return tree[node];

	if (start == end)
		return tree[node] += val;
	int mid = (start + end) / 2;

	return tree[node] = update(start, mid, node * 2, idx, val) + update(mid + 1, end, node * 2 + 1, idx, val);
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
		int a, b, c;

		cin >> a;

		if (a == 1)
		{
			cin >> b;

			int res=search(1,MAX,1,b);
			cout<<res<<"\n";
			update(1,MAX,1,res,-1);
		}
		else
		{
			cin >> b >> c;

			update(1, MAX, 1, b, c);
		}
	}

	return 0;
}