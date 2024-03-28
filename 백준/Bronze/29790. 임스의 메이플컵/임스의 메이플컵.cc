#include<bits/stdc++.h>
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
int n,l,u;
cin>>n>>u>>l;

if(n>=1000)
{
	if(u>=8000||l>=260)
		cout<<"Very Good";
	else
		cout<<"Good";
}
else
	cout<<"Bad";
return 0;
}