#include<bits/stdc++.h>
using namespace std;
#define lint long long
lint LCM[50];
lint acnt[50];
lint A, B;
lint mul[50];
lint gcd(lint a, lint b)
{
	lint large = a > b ? a : b;
	lint small = a < b ? a : b;
	lint c = large % small;
	while (c != 0)
	{
		large = small;
		small = c;
		c = large % small;
	}
	return small;
}
lint getLCM(lint a, lint b)
{
	return a * b / gcd(a, b);
}
int main()
{
	cin >> A >> B;
	LCM[1] = 1;
	for (int i = 2; i < 44; i++)
	{
		lint cLCM = 1;
		for (int q = 1; q < i; q++)
		{
			cLCM = cLCM * q / gcd(cLCM, q);

		}
		LCM[i] = cLCM;
	}
	for (int i = 2; LCM[i] <= B; i++)
	{
		if (LCM[i] % i == 0)
			continue;
		acnt[i] += B / LCM[i] - B / getLCM(i, LCM[i]);
	}
	for (int i = 2; LCM[i] < A; i++)
	{
		if (LCM[i] % i == 0)
			continue;
		acnt[i] -= (A-1) / LCM[i] - (A-1) / getLCM(i, LCM[i]);
	}
	for (int i = 2; i < 43; i++)
	{
		int cnt=1;
		int q = 2;
		int temp = i;
		while (1)
		{
			if (temp % q != 0)
			{
				cnt++;
				temp = q;
				q = 2;
			}
			else
			{
				q++;
			}
			if (temp == 2)
			{
				mul[i] = cnt+1;
				break;
			}
		}
	}
	lint res=0;
	for (int i = 2; i < 43; i++)
	{
		res += mul[i] * acnt[i];
	}
	cout << res;
}