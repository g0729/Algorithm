#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX 4000001
#define lint long long
lint fac[MAX];

lint mypow(lint a, lint n)
{
	if (n == 0)
		return 1;
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
	fac[0] = fac[1] = 1;
	int n,k;
	cin >> n>>k;
	for (int i = 2; i <= n; i++)
	{
		fac[i] = (i * fac[i - 1]) % MOD;
	}
	lint res = mypow(fac[n - k] * fac[k] % MOD, MOD - 2);
	lint ans = (res * fac[n]) % MOD;
	cout << ans;
}	