#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

long long arr[MAX];
long long node[MAX * 4];

long long initSegment(int left, int right, int nodeIdx)
{
	if (left == right)
	{
		return node[nodeIdx] = arr[left];
	}

	int mid = (left + right) / 2;

	return node[nodeIdx] = (initSegment(left, mid, nodeIdx * 2) + initSegment(mid + 1, right, nodeIdx * 2 + 1));
}

long long query(int left, int right, int nodeIdx, int leftNode, int rightNode)
{
	if (rightNode < left || leftNode > right)
	{
		return 0;
	}

	if (leftNode >= left && rightNode <= right)
	{
		return node[nodeIdx];
	}

	int mid = (leftNode + rightNode) / 2;

	return (query(left, right, nodeIdx * 2, leftNode, mid) + query(left, right, nodeIdx * 2 + 1, mid + 1, rightNode));
}

void update(int nodeIdx, int idx, int left, int right, long long value)
{
	if (idx < left || idx > right)return;

	node[nodeIdx] += value;

	if (left == right)
		return;

	int mid = (left + right) / 2;

	update(nodeIdx * 2, idx, left, mid, value);
	update(nodeIdx * 2 + 1, idx, mid + 1, right, value);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, Q;

	cin >> N >> Q;

	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
	}

	initSegment(1, N, 1);

	for (int i = 1; i <= Q; ++i)
	{
		int x, y;

		long long a, b;
		cin >> x >> y >> a >> b;

		if (x > y) swap(x, y);

		cout << query(x, y, 1, 1, N) << "\n";
		update(1, a, 1, N, b - arr[a]);
		arr[a]=b;
	}

	return 0;
}