#include<bits/stdc++.h>
using namespace std;
#define lint long long
lint alpha[10];
bool check[10];
bool cmp(lint a,lint b)
{
	return a>b;
}
lint mypow(int n)
{
	lint res=1;
	for (int i = 0; i < n; i++)
	{
		res*=10;
	}
	return res;
}
int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin>>s;
		check[s[0]-'A']=true;
		for (int q = 0; q < s.length(); q++)
		{
			alpha[s[q]-'A']+=mypow(s.length()-q-1);
		}
		
	}
	lint res=0;
	lint min_i;
	lint min=1e13;

	for (int i = 0; i < 10; i++)
	{
		if(min>alpha[i]&&!check[i])
		{
			min=alpha[i];
			min_i=i;
		}
	}

	alpha[min_i]=0;
	sort(alpha,alpha+10,cmp);
	for (int i = 0; i < 10; i++)
	{
		res+=alpha[i]*(9-i);
	}
	cout<<res;
}