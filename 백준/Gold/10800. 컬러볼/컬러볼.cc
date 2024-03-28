#include <bits/stdc++.h>
using namespace std;
#define MAX 200001
int ans[MAX];
int colsum[MAX];
bool cmp(tuple<int, int, int>& a, tuple<int, int, int>& b)
{
	int a2 = get<1>(a);
	int b2 = get<1>(b);
	int a1 = get<0>(a);
	int b1 = get<0>(b);
	if (a2 == b2)
		return a1 < b1;
	return a2 < b2;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<tuple<int, int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({a, b, i});
	}
	sort(v.begin(), v.end(), cmp);
	int sum =get<1>(v[0]);
	colsum[get<0>(v[0])]=sum;

	int str = 0;
	for (int i = 1; i < n; i++)
	{
		int color = get<0>(v[i]);
		int wei = get<1>(v[i]);
		int index = get<2>(v[i]);
		if (wei == get<1>(v[i - 1]))
			str++;
		else
			str = 0;
		sum += wei;
		colsum[color] += wei;
		ans[index] = sum - colsum[color] - str * wei;
		if(get<0>(v[i-1])==color&&get<1>(v[i-1])==wei)
		ans[index]=ans[get<2>(v[i-1])];
	}
	for (int i = 0; i < n; i++)
	{
		cout<<ans[i]<<"\n";
	}
	
}