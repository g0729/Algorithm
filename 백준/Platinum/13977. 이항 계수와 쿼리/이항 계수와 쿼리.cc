#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define MAX 4000001
#define MOD 1000000007

lint fac[MAX];
lint mypow(lint a, lint n)
{
	if (n == 1)
		return a;
	lint temp = mypow(a, n / 2);
	lint ans = (temp * temp) % MOD;
	if (n % 2 == 0)
	{
		return ans;
	}
	else
	{
		return (a * ans) % MOD;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fac[0] = fac[1] = 1;
	for (int i = 2; i < MAX; i++)
	{
		fac[i] = (fac[i - 1] * i) % MOD;
	}
	int m;
	cin >> m;
	while (m--)
	{
		int n, k;
		cin >> n >> k;
		lint a = mypow((fac[k] * fac[n - k])%MOD, MOD - 2);
		lint res = (fac[n] * a) % MOD;
		cout << res << "\n";
	}
}