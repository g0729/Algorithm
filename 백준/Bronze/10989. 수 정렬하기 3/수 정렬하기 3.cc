#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count[10001] = { 0 };
	int a,n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		count[a]++;
	}
	for (int i = 1; n > 0; i++)
	{
		while (count[i] > 0)
		{
			cout << i << "\n";
			count[i]--;
			n--;
		}
	}
}