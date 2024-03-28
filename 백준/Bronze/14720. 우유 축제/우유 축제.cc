#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin>>n;

	int now=0;
	int res=0;
		
	for (int i = 0; i < n; i++)
	{
		int a;
		cin>>a;

		if(a==now)
		{
			res++;
			now++;
			if(now==3)
				now=0;
		}
	}
	
	cout<<res;

	
	return 0;
}