#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	string s;
	cin >> s;
	vector<int> v;
	for (int i = 0; i < s.length(); i++)
	{
		v.push_back(s[i] - '0');
	}
	sort(v.begin(),v.end(), cmp);
	if (v.back() != 0)
	{
		cout << "-1";
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}
	if (sum % 3 != 0)
	{
		cout << "-1";
		return 0;
	}
	else
	{
		for (int i = 0; i <v.size(); i++)
		{
			cout << v[i];
		}
	}
}