#include <bits/stdc++.h>
using namespace std;

int main()
{
	while (1)
	{
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)
			return 0;
		cout << n / m << " " << n % m << " / " << m<<endl;
	}
}