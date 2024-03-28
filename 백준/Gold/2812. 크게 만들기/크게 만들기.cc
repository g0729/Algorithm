#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, k;
	string s;
	vector<char>res;
	cin >> n >> k >> s;

	for (int i = 0; i < s.size(); i++)
	{

		while (k > 0 && !res.empty()&&s[i] > res.back() )
		{
			res.pop_back();
			k--;
		}
		res.push_back(s[i]);
	}
	while (k--)
	{
		res.pop_back();
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
	}

}