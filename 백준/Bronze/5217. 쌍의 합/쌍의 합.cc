#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;
		bool check=false;
		cout<<"Pairs for "<<n<<": ";
		for (int i = 1; i <=n/2; i++)
		{
			if(i==n-i)
			continue;
			if(check)
			cout<<", ";
			cout<<i<<" "<<n-i;
			check=true;
		}
		cout<<endl;
	}
}