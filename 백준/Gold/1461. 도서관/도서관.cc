#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main()
{
	int res=0;
	int n, k;
	int large;
	int mi = 0, pl = 0;
	int cnt = 0;
	cin >> n >> k;
	deque<int>arr;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a < 0)
			mi++;
		else
			pl++;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	large = abs(arr[0]) > abs(arr.back()) ? 0 : arr.size()-1;
	
	
	res += abs(arr[large]);
	if (n == 1)
	{
		cout << abs(arr[0]);
		return 0;
	}

	if (large == 0)
	{
		for (int i = 0; i < k; i++)
		{
			if (arr.front() < 0)
			{
				arr.pop_front();
				mi--;
			}
		}
	}	
	else
	{
		for (int i = 0; i < k; i++)
		{
			if (arr.back() > 0)
			{
				arr.pop_back();
				pl--;
			}
		}
	}
	while (mi > 0)
	{
		res += 2 * abs(arr.front());
		for (int i = 0; i < k; i++)
		{
			if (mi > 0)
			{
				arr.pop_front();
				mi--;
			}
		}
	}
	while (pl > 0)
	{
		res += 2 * arr.back();
		for (int i = 0; i < k; i++)
		{
			if (pl > 0)
			{
				arr.pop_back();
				pl--;
			}
		}
	}

	cout << res;
}