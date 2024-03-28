#include <bits/stdc++.h>
using namespace std;
#define lint long long
vector<lint> v1;
vector<lint> v2;
lint arr[30];
void dfs(int now, int end, lint sum, vector<lint> &v)
{
	if (now > end)
	{
		v.push_back(sum);
		return;
	}
	else
	{
		dfs(now + 1, end, sum,v);
		dfs(now + 1,end, sum + arr[now],v);
	}
}
int main()
{
	int n,c;
	cin >> n>>c;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	dfs(0,n/2,0,v1);
	dfs(n/2+1,n-1,0,v2);

	sort(v2.begin(),v2.end());

	lint res=0;

	for (int i = 0; i < v1.size(); i++)
	{
		lint temp=upper_bound(v2.begin(),v2.end(),c-v1[i])-v2.begin();
		res+=temp;
	}
	cout<<res;
}