#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

vector<lint> tree;
vector<lint>v;
lint sum(lint start, lint end, lint node, lint left, lint right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	lint mid = (start + end) / 2;

	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
void update(lint start, lint end, lint node, lint idx, lint dif)
{
	if (idx < start || idx > end)
		return;

	tree[node] += dif;

	if(start==end)
	return;
	lint mid = (start + end) / 2;

	update(start, mid, node * 2, idx, dif);
	update(mid + 1, end, node * 2 + 1, idx, dif);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	lint n, k;
	cin >> n >> k;

	v = vector<lint>(n);
	tree = vector<lint>(4 * n);

	
	for (int i = 0; i < k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0)
		{
			lint small=b<c?b:c;
			lint big=b>c?b:c;
			cout << sum(0, n - 1, 1,small-1, big-1) << "\n";
		}
		else
		{
			update(0, n - 1, 1, b - 1, c-v[b-1]);
			v[b - 1] = c;
		}
	}

	return 0;
}