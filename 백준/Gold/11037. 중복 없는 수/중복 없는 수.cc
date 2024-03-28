#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

bool isUsed[10];
vector<lint> v;
void dfs(int cnt, lint now)
{
	if (cnt == 9)
		return;

	for (int i = 1; i < 10; i++)
	{
		if (isUsed[i])
			continue;

		isUsed[i] = true;
		lint temp = now * 10 + i;
		v.push_back(temp);
		dfs(cnt + 1, temp);
		isUsed[i] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	dfs(0,0);

	sort(v.begin(),v.end());
	while(1)
	{
		lint n;
		cin>>n;

		if(cin.eof())
		break;

		auto temp=upper_bound(v.begin(),v.end(),n);

		if(temp==v.end())
			cout<<"0";
		else
			cout<<*temp;

		cout<<"\n";
	}
	return 0;
}