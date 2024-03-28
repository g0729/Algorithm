#include<bits/stdc++.h>
using namespace std;
#define MAX 10007
int fac[1001];
int n, k;
long long fuction(int n, long long mod)
{
	if (mod == 0)
		return 1;
	long long tmp = fuction(n, mod / 2);
	long long ans = (tmp * tmp) % MAX;
	if (mod % 2 == 0)
	{
		return ans;
	}
	else
	{
		return (n * ans) % MAX;
	}

}
int main()
{
	fac[0] = 1;
	fac[1] = 1;
	cin >> n >> k;
	for (int i = 2; i <= n; i++)
	{
		fac[i] = (fac[i - 1] * i) % MAX;
	}
	long long a = fuction((fac[k] * fac[n - k]) % MAX, MAX - 2);
	long long ans = (fac[n] * a) % MAX;
	cout << ans;
}