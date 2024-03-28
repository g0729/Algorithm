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

int t;
t=1;

while(1)
{
	int n0,n1,n2,n3,n4;
	cin>>n0;

	if(n0==0)
		break;
	n1=3*n0;
	n2=n1/2;
	n3=3*n2;
	n4=n3/9;

	cout<<t<<". ";
	if(n1%2==0)
		cout<<"even ";
	else
		cout<<"odd ";
	cout<<n4<<"\n";
	t++;
}
return 0;
}
