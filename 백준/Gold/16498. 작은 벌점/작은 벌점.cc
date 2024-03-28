#include <bits/stdc++.h>
using namespace std;
#define lint long long

lint res=1e12;

void f(vector<lint> &v1, vector<lint> &v2, vector<lint> &v3)
{
	for (lint i = 0; i < v1.size(); i++)
	{
		for (lint j = 0; j < v2.size(); j++)
		{
			lint MIN = v1[i];
			lint MAX = v2[j];
			if (MIN > MAX)
				continue;
			auto temp = lower_bound(v3.begin(), v3.end(), MIN);
			if(temp==v3.end())
			continue;
			if (*temp > MAX)
				continue;
			res=min(res,abs(MAX-MIN));
		}
	}
}
int main()
{
	vector<lint> v1, v2, v3;

	lint a, b, c;

	cin >> a >> b >> c;

	lint temp;

	for (lint i = 0; i < a; i++)
	{
		cin >> temp;
		v1.push_back(temp);
	}

	for (lint i = 0; i < b; i++)
	{
		cin >> temp;
		v2.push_back(temp);
	}

	for (lint i = 0; i < c; i++)
	{
		cin >> temp;
		v3.push_back(temp);
	}



	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	sort(v3.begin(),v3.end());

	f(v1,v2,v3);
	f(v1,v3,v2);
	f(v2,v1,v3);
	f(v2,v3,v1);
	f(v3,v1,v2);
	f(v3,v2,v1);

	cout<<res;

}