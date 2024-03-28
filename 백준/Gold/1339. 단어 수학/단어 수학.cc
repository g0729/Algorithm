#include<iostream>
#include<algorithm>
using namespace std;
int alpha[26];
bool cmp(int a, int b)
{
	return a > b;
}
int mypow(int k)
{
	int ca = 1;
	for (int i = 0; i < k; i++)
	{
		ca *= 10;
	}
	return ca;
}
int main()
{
	string s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int q = 0; q < s.length(); q++)
		{
			alpha[s[q] - 'A'] += mypow(s.length() - q-1);
		}
	}
	sort(alpha, alpha + 26, cmp);
	int j = 0;
	int res = 0;
	while (alpha[j] != 0)
	{
		res += alpha[j] * (9 - j);
		j++;
	}
	cout << res;
}