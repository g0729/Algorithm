#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;

	if(b==1||!(a>=12&&a<=16))
	{
		cout<<"280";
	}
	else if(b==0&&(a>=12&&a<=16))
	{
		cout<<"320";
	}

	return 0;
}