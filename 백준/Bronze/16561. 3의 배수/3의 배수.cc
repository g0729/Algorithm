#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int res = 0;

	for (int i = 3; i <= n; i += 3)
	{
		for (int j = 3; j <= n; j += 3)
		{
			if(i+j<n&&(n-i-j)%3==0)
				res++;
		}
	}

	cout<<res;
	return 0;
}