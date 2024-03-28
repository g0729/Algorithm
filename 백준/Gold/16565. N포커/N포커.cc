#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

int combi[53][53];
int mod=10007;

void com()
{
	for (int i = 0; i <= 52; i++)
	{
		combi[i][i]=1;
		combi[i][0]=1;
	}
	for (int i = 1; i <= 52; i++)
	{
		for (int j = 1; j <=52; j++)
		{
			combi[i][j]=(combi[i-1][j-1]+combi[i-1][j])%mod;
		}
		
	}
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin>>n;

	int res=0;
	com();

	for (int i = 1; i<=13&&n >=4*i; i++)
	{
		if(i%2==1)
			res=(res+combi[13][i]*combi[52-4*i][n-4*i]%mod)%mod;
		else
			res=(res-combi[13][i]*combi[52-4*i][n-4*i]%mod+mod)%mod;
		
	}
	
	cout<<res;
	return 0;
}