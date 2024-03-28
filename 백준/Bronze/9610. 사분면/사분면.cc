#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int cnt[5] = {};

	while (n--)
	{
		int x, y;

		cin >> x >> y;

		if (x == 0 || y == 0)
			cnt[4]++;
		else if (x > 0 && y > 0)
			cnt[0]++;
		else if (x < 0 && y > 0)
			cnt[1]++;
		else if (x < 0 && y < 0)
			cnt[2]++;
		else
			cnt[3]++;
	}

	for (int i = 1; i <= 4; i++)
	{
		cout<<"Q"<<i<<": "<<cnt[i-1]<<endl;
	}
	
	cout<<"AXIS: "<<cnt[4];
}