#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int n;
cin>>n;
vector<int>v(n);

for (int i = 0; i < n; i++)
{
	cin>>v[i];
}

int Min=1e8;
int num;
for (int i = 1; i <= 10000; i++)
{
	int sum=0;
	for (int j = 0; j < n; j++)
	{
		sum+=abs(v[j]-i);
	}
	
	if(sum<Min)
	{
		Min=sum;
		num=i;
	}
}

cout<<num;
return 0;
}