#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, d, k;

	cin >> a >> d >> k;

	k -= a;


	if (k % d != 0||k/d<0)
		cout << "X";
	else
		cout << k / d + 1;
}