#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000
vector<int> v;

void postOrder(int start, int end)
{
	if (start >= end)
		return;
	int i;

	for (i = start + 1; i < end; i++)
		if (v[start] < v[i])
			break;
	postOrder(start + 1, i);
	postOrder(i, end);
	cout << v[start] << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		int a;
		cin >> a;
		if (cin.eof())
			break;
		v.push_back(a);
	}
	postOrder(0, v.size());
	return 0;
}