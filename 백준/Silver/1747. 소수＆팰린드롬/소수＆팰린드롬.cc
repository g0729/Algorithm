#include<iostream>
#include<vector>
using namespace std;
#define max 100000000
bool PrimeArr[max];
void eratos()
{
	PrimeArr[0] = PrimeArr[1] = true;
	for (int i = 2; i * i <= max; i++)
	{
		if (PrimeArr[i] == false)
		{
			for (int q = i * i; q < max; q += i)
			{
				PrimeArr[q] = true;
			}
		}
	}
}
bool check(int a)
{
	string s;
	while (a > 0)
	{
		s.push_back(a % 10);
		a /= 10;
	}
	for (int i = 0; i < s.length() / 2; i++)
	{
		if (s[i] != s[s.length() - i - 1])
			return false;
	}
	return true;
}
int main()
{
	int a;
	cin >> a;
	eratos();
		for (long long i = a;; i++)
		{
			if (PrimeArr[i])
				continue;
			if (check(i))
			{
				cout << i;
				break;
			}
		}
}