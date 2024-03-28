#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

lint n, m, k;
vector<lint> v;

lint init(lint start, lint end, lint node, vector<lint> &tree)
{
	if (start == end)
		return tree[node] = v[start];

	lint mid = (start + end) / 2;

	return tree[node] = init(start, mid, node * 2, tree) + init(mid + 1, end, node * 2 + 1, tree);
}

lint sum(lint start, lint end, lint node, lint left, lint right, vector<lint> &tree)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	lint mid = (start + end) / 2;

	return sum(start, mid, node * 2, left, right, tree) + sum(mid + 1, end, node * 2 + 1, left, right, tree);
}

void update(lint start, lint end, lint node, lint idx, lint dif, vector<lint> &tree)
{
	if (idx < start || idx > end)
		return;

	tree[node] += dif;

	if(start==end)
	return;
	lint mid = (start + end) / 2;

	update(start, mid, node * 2, idx, dif, tree);
	update(mid + 1, end, node * 2 + 1, idx, dif, tree);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (lint i = 0; i < n; i++)
	{
		lint a;
		cin >> a;
		v.push_back(a);
	}

	lint num = v.size();
	vector<lint> tree(num * 4);

	init(0, num - 1, 1, tree);

	for (lint i = 0; i < m + k; i++)
	{
		lint a, b, c;

		cin >> a >> b >> c;

		if (a == 1)
		{
			update(0, num - 1, 1, b-1, c - v[b - 1], tree);
			v[b - 1] = c;
		}
		else
			cout << sum(0, num - 1, 1, b-1, c-1, tree) << "\n";
	}

	return 0;
}