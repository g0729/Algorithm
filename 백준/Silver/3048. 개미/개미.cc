#include <bits/stdc++.h>
using namespace std;

struct ant{

	char name;
	bool dir;
};
int main()
{
	int n1,n2,t;
	string a,b;
	cin>>n1>>n2;
	cin>>a>>b;
	cin>>t;

	for (int i = 0; i < a.length()/2; i++)
	{
		char temp=a[i];
		a[i]=a[a.length()-i-1];
		a[a.length()-i-1]=temp;
	}

	ant ants[n1+n2];
	
	for (int i = 0; i < n1; i++)
	{
		ants[i].name=a[i];
		ants[i].dir=false;
	}
	
	for (int i = n1; i < n1+n2; i++)
	{
		ants[i].name=b[i-n1];
		ants[i].dir=true;
	}


	for (int i = 0; i < t; i++)
	{
		for (int i = 0; i < n1+n2-1; i++)
		{
			if(ants[i].dir==0&&ants[i+1].dir==1)
			{
				ant temp=ants[i];
				ants[i]=ants[i+1];
				ants[i+1]=temp;
				i++;
			}
		}
	}
	
	for (int i = 0; i < n1+n2; i++)
	{
		cout<<ants[i].name;
	}
	
}