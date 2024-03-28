#include <bits/stdc++.h>
using namespace std;

int main()
{
	int cnt[10]={0};
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		cnt[s[i]-'0']++;
	}
	

	int MAX = 0;

	for (int i = 0; i < 10; i++)
	{
		if (i == 6 || i == 9)
			continue;
		MAX = max(MAX, cnt[i]);
	}

	int res=max(MAX,(cnt[6]+cnt[9]+1)/2);

	cout<<res;
}
