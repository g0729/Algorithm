#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,m;
	cin>>n>>k>>m;
	if(m-n*k>=0)
		cout<<"0";
	else
		cout<<n*k-m;
}