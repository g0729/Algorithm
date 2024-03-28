#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < n; i++)
	{
		cout << v[i] << "\n";
	}

	return 0;
}