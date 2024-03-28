#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000
map<string, float> ma = {{"A+", 4.3}, {"A0", 4.0}, {"A-", 3.7}, {"B+", 3.3}, {"B0", 3.0}, {"B-", 2.7}, {"C+", 2.3}, {"C0", 2.0}, {"C-", 1.7}, {"D+", 1.3}, {"D0", 1.0}, {"D-", 0.7}, {"F", 0.0}};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	float sum = 0;
	int sumA=0;
	for (int i = 0; i < n; i++)
	{
		string a,c;
		int b;
		cin>>a>>b>>c;
		sumA+=b;
		sum+=b*ma[c];
	}
	
	cout<<fixed;
	cout.precision(2);

	cout<<sum/sumA;
	return 0;
}