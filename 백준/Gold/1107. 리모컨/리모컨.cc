#include<iostream>
#include<string>
#include<math.h>;
using namespace std;
#define ma 1000000
bool sel[10];
int n;
int min(int a,int b)
{
	if (a < b)
		return a;
	else
		return b;
}
bool check(int a)
{
	string s = to_string(a);
	for (int i = 0; i < s.length(); i++)
	{
		if (sel[s[i] - '0'] == false)
			return false;
	}
	return true;
}
int main()
{
	int k;
	cin >> n>>k;
	for (int i = 0; i < 10; i++)
	{
		sel[i] = true;
	}
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		sel[a] = false;
	}
	int res = abs(100 - n);
	for (int i = 0; i < ma; i++)
	{
		if (check(i))
		{
			string s = to_string(i);
			res = min(res, abs(i - n) + s.length());
		}
	}
	cout << res;
}