#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	string a, b;
	for (int i = 0; i < t; i++)
	{
		int alp[26] = { 0 };
		int calp[26] = { 0 };
		cin >> a >> b;
		for (int i = 0; i < a.length(); i++)
		{
			alp[a[i] - 'a']++;
		}
		for (int i = 0; i < b.length(); i++)
		{
			calp[b[i] - 'a']++;
		}
		bool check = true;
		for (int i = 0; i < 26; i++)
		{
			if (alp[i] != calp[i])
			{
				check = false;
				break;
			}
		}
		if (check)
			cout << "Possible" << "\n";
		else
			cout << "Impossible" << "\n";
	}
}