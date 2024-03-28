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

	int arr[4]={25,10,5,1};

	int t;
	cin>>t;

	while(t--)
	{
		int c;
		cin>>c;

		for (int i = 0; i < 4; i++)
		{
			cout<<c/arr[i]<<" ";
			c=c%arr[i];
		}
		cout<<"\n";
	}
	return 0;
}