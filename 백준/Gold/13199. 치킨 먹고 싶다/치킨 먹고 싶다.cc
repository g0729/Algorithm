#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int p,m,f,c;
		cin>>p>>m>>f>>c;
		int chi=m/p;
		int cup=chi*c;
		int duy=chi+cup/f;
		int san=chi;
		int temp=cup;
		if(temp>=f)
		{
			san+=(temp-f)/(f-c)+1;
		}
		cout<<san-duy<<"\n";
	}
}