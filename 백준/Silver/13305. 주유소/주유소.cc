#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long>price;
	vector<long long>dis;
	long long res=0;
	for (int i = 0; i < n - 1; i++)
	{
		long long a;
		cin >> a;
		dis.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		long long a;
		cin >> a;
		price.push_back(a);
	}
	int start = 0;
	int next=0;
	for (int i = 0; i < n - 1; i=next)
	{
		while (price[i] <= price[next]&&next<n-1)
		{
			next++;
		}
		for (int q = i; q < next; q++)
		{
			res += price[i] * dis[q];
		}
		
	}
	cout << res;
}