#include <bits/stdc++.h>
using namespace std;
#define lint unsigned long long 
#define tu tuple<int,int,lint> 
tu arr[100];
bool cmp(tu a,tu b)
{
	if(get<0>(a)==get<0>(b))
	return get<1>(a)>get<1>(b);
	else
	return get<0>(a)<get<0>(b);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		lint a;
		cin >> a;
		int cntt2 = 0, cntt3 = 0;
		lint ca = a;
		while (a % 2 == 0 || a % 3 == 0)
		{
			if (a % 2 == 0)
			{
				cntt2++;
				a /= 2;
			}
			if (a % 3 == 0)
			{
				cntt3++;
				a /= 3;
			}
		}
		arr[i]={cntt2,cntt3,ca};
	}
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++)
	{
		cout << get<2>(arr[i]) << " ";
	}
}