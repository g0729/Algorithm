#include<iostream>
using namespace std;

int main()
{
	int l, p, v;
	int t = 1;
	while (1)
	{
		cin >> l >> p >> v;
		if (l == 0)
			break;
		if (v % p > l)
		{
			cout <<"Case "<<t<<": "<< v / p * l + l << endl;
		}
		else
			cout << "Case " << t << ": "<< v / p * l + v % p<<endl;
		t++;
	}

}