#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i = 1;
	string s;
	while (1)
	{
		getline(cin, s);
		if (s == "0")
			break;
		cout<<"Case "<<i<<": Sorting... done!\n";
		i++;
	}
}