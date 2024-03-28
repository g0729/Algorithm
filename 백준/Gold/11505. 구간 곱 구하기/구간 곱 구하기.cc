	#include <bits/stdc++.h>
	using namespace std;
	#define INF 987654321
	#define lint long long
	#define MOD 1000000007
	lint n, m, k;
	vector<lint> tree;
	vector<lint> v;

	lint init(lint start, lint end, lint node)
	{
		if (start == end)
			return tree[node] = v[start];

		lint mid = (start + end) / 2;

		return tree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % MOD;
	}
	lint Search(lint start, lint end, lint node, lint left, lint right)
	{
		if (left > end || right < start)
			return 1;
		if (left <= start && end <= right)
			return tree[node];

		lint mid = (start + end) / 2;

		return (Search(start, mid, node * 2, left, right) * Search(mid + 1, end, node * 2 + 1, left, right)) % MOD;
	}

	lint update(lint start, lint end, lint node, lint idx, lint val)
	{
		if (idx < start || idx > end)
			return tree[node];

		if(start==end)
			return tree[node]=val;

		lint mid=(start+end)/2;

		return tree[node]=(update(start,mid,node*2,idx,val)*update(mid+1,end,node*2+1,idx,val))%MOD;
	}
	int main()
	{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		cin >> n >> m >> k;

		v = vector<lint>(n);
		tree = vector<lint>(4 * n);

		for (lint i = 0; i < n; i++)
			cin >> v[i];

		init(0, n - 1, 1);

		for (lint i = 0; i < m + k; i++)
		{
			lint a, b, c;

			cin >> a >> b >> c;

			if (a == 1)
			{
				update(0, n - 1, 1, b - 1, c);
				v[b - 1] = c;
			}
			else
				cout << Search(0, n - 1, 1, b - 1, c - 1) << "\n";
		}

		return 0;
	}