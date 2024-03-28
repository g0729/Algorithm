#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define lint long long
bool PrimeArr[MAX];
lint gcd(lint a,lint b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
void eratos()
{
	PrimeArr[0] = true;
	PrimeArr[1] = true;
	for (int i = 2; i * i <= MAX; i++)
	{
		if (PrimeArr[i] == false)
		{
			for (int q = i * i; q <= MAX; q += i)
			{
				PrimeArr[q] = true;
			}
		}
	}
}
int main()
{
	vector<lint> v;
	eratos();
	int n;
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		if (!PrimeArr[a])
			v.push_back(a);
	}
	if(v.empty())
	{
		cout<<"-1";
		return 0;
	}
	lint res=(v[0]*v[1])/gcd(v[0],v[1]);
	for (int i = 2; i < v.size(); i++)
	{
		res=(res*v[i])/gcd(res,v[i]);
	}
	cout<<res;
}