	#include <bits/stdc++.h>
	using namespace std;

	int main()
	{
		double a,b,c;
		cin>>a>>b>>c;
		double temp1,temp2;
		temp1=a*b/c;
		temp2=a/b*c;

		cout<<(long long)max(temp1,temp2);
		
	}