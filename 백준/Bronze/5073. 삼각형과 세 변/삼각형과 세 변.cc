#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		vector<int> v(3);

		for (int i = 0; i < 3; i++)
		{
			cin >> v[i];
		}
		if(v[0]==0&&v[1]==0&&v[2]==0)
		break;
		sort(v.begin(), v.end());

		if (v[0] + v[1] <= v[2])
			cout << "Invalid";
		else if (v[0] == v[1] && v[1] == v[2])
			cout << "Equilateral";
		else if (v[0] == v[1] || v[1] == v[2] || v[0] == v[2])
			cout << "Isosceles";
		else
			cout << "Scalene";
		cout << endl;
	}
	return 0;
}