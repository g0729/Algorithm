#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

vector<ll> v;
bool check(ll num)
{
	for (ll i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
ll cal(ll num, ll pow)
{
	ll res = 0;
	pow /= 10;
	while (num)
	{
		res += (num % 10) * pow;
		num /= 10;
		pow /= 10;
	}
	return res;
}
void make_Pelin()
{
	v.push_back(2);
	v.push_back(5);
	v.push_back(7);
	v.push_back(11);
	ll dight = 1;
	ll Pow = 10;
	for (ll i = 1; i < 1000; i++)
	{
		if (i >= Pow)
		{
			Pow *= 10;
			dight++;
		}
		ll temp = i * 10 * Pow + cal(i, Pow);
		for (ll j = 0; j < 10; j++)
		{
			ll temp2 = temp + j * Pow;
			if (check(temp2))
				v.push_back(temp2);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll a, b;
	cin >> a >> b;
	make_Pelin();

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < a)
			continue;
		if (v[i] > b)
			break;
		cout << v[i] << "\n";
	}
	cout << "-1";
	return 0;
}