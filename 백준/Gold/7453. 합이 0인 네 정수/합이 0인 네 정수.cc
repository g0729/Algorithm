#include <bits/stdc++.h>
using namespace std;
#define lint long long
int n;
lint arr[4][4000];
vector<lint>v1;
vector<lint>v2;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin>>arr[j][i];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v1.push_back(arr[0][i]+arr[1][j]);
			v2.push_back(arr[2][i]+arr[3][j]);
		}
	}
	sort(v2.begin(),v2.end());

	lint res=0;

	for (int i = 0; i < v1.size(); i++)
	{
		res+=upper_bound(v2.begin(),v2.end(),-v1[i])-lower_bound(v2.begin(),v2.end(),-v1[i]);
	}

	cout<<res;
}