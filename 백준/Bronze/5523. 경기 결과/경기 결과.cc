#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a_res, b_res;
	a_res = b_res = 0;

	while (n--)
	{
		int a, b;
		cin >> a >> b;
		if (a > b)
			a_res++;
		else if (a < b)
			b_res++;
	}
	
	cout<<a_res<<" "<<b_res;
}