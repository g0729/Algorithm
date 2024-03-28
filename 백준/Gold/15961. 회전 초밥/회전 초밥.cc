#include <bits/stdc++.h>
using namespace std;

int cnt[3001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v;
	int res = 0;
	int now = 0;
	int n, d, k, c;
	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < k; i++)
	{
		if (cnt[v[i]]==0)
		{
			res++;
			now++;
		}
		cnt[v[i]]++;
	}

	now = res;

	for (int i = k; i < n; i++)
	{
		cnt[v[i - k]]--;
		if (cnt[v[i - k]]==0)
		{
			now--;
		}
		if (cnt[v[i]]==0)
		{
			now++;
		}
		cnt[v[i]]++;

			if (cnt[c] == 0)
				res = max(res, now+1);
			else
				res = max(res, now );
	}

	for (int i = 0; i < k - 1; i++)
	{
		cnt[v[i + n - k]]--;
		if (cnt[v[i + n - k]]==0)
		{
			now--;
		}
		if (cnt[v[i]]==0)
		{
			now++;
		}
		cnt[v[i]]++;
		
			if (cnt[c] == 0)
				res = max(res, now+1);
			else
				res = max(res, now );
		

	}

	cout<<res;
}