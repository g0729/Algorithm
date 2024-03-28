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

	map<string, int> ma;

	int sum=0;
	while (1)
	{
		string s;
		getline(cin,s);

		if (cin.eof())
			break;
		ma[s]++;
		sum++;
	}

	cout << fixed;
	cout.precision(4);

	vector<pair<string, int>> v(ma.begin(), ma.end());
	
	sort(v.begin(),v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout<<v[i].first<<" "<<((double)v[i].second/sum)*100<<"\n";
	}
	
	return 0;
}