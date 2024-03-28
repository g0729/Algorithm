#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

int cal(string &a, string &b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int res = 0;
	while (a.length() != b.length())
	{
		if (a.length() < b.length())
			a.push_back('0');
		else
			b.push_back('0');
	}

	int carry = 0;
	for (int i = 0; i < a.length(); i++)
	{
		int sum = a[i] + b[i] - '0' * 2 + carry;

		if (sum >= 10)
		{
			carry = 1;
			res++;
		}
		else
			carry = 0;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		string a, b;
		cin >> a >> b;

		if (a == "0" && b == "0")
			break;
		
		cout<<cal(a,b)<<"\n";
	}
	return 0;
}