#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[4];
	int sum=0;
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
		sum+=arr[i];
	}

	int res=1e9;
	for (int i = 0; i < 3; i++)
	{
		for (int j = i+1; j < 4; j++)
		{
			int temp=arr[i]+arr[j];
			int temp2=sum-temp;
			res=min(res,abs(temp2-temp));
		}
	}
	
	cout<<res;
	return 0;
}