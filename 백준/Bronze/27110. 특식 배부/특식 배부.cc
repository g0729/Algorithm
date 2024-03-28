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

	int a,b,c;
	cin>>a>>b>>c;

	int res=min(a,n)+min(b,n)+min(c,n);

	cout<<res;
	 
	return 0;
}