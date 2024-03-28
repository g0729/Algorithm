#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int cnt2, cnt5;
	cnt2 = cnt5 = 0;
	for (int i = 1; i <= n; i++)
	{
		int q = i;
		while (q % 2 == 0)
		{
			q /= 2;
			cnt2++;
		}
		while (q % 5 == 0)
		{
			q /= 5;
			cnt5++;
		}
	}
	int res = cnt2 < cnt5 ? cnt2 : cnt5;
	cout << res;
}