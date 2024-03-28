#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int n, m;
vector<int> MinTree;
vector<int> MaxTree;
vector<int> v;

int MinInit(int start, int end, int node)
{
	if (start == end)
		return MinTree[node] = v[start];

	int mid = (start + end) / 2;

	return MinTree[node] = min(MinInit(start, mid, node * 2), MinInit(mid + 1, end, node * 2 + 1));
}
int MaxInit(int start, int end, int node)
{
	if (start == end)
		return MaxTree[node] = v[start];

	int mid = (start + end) / 2;

	return MaxTree[node] = max(MaxInit(start, mid, node * 2), MaxInit(mid + 1, end, node * 2 + 1));
}

int MaxSearch(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return MaxTree[node];

	int mid = (start + end) / 2;

	return max(MaxSearch(start, mid, node * 2, left, right), MaxSearch(mid + 1, end, node * 2 + 1, left, right));
}
int MinSearch(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 1e9;

	if (left <= start && end <= right)
		return MinTree[node];

	int mid = (start + end) / 2;

	return min(MinSearch(start, mid, node * 2, left, right), MinSearch(mid + 1, end, node * 2 + 1, left, right));
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	MaxTree = vector<int>(4 * n);
	MinTree = vector<int>(4 * n);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	MaxInit(0, n - 1, 1);
	MinInit(0, n - 1, 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;
		cout << MinSearch(0, n - 1, 1, a - 1, b - 1) << " " << MaxSearch(0, n - 1, 1, a - 1, b - 1) << "\n";
	}

	return 0;
}