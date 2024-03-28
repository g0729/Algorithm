#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	cin >> a >> b;

	int idx = 0;

	string c;

	for (int i = 0; i < a.length(); i++)
	{
		if(a[i]<='9'&&a[i]>='0')
			continue;
		c.push_back(a[i]);
	}
	
	if(c.find(b)!=string::npos)
		cout<<"1";
	else
		cout<<"0";
}