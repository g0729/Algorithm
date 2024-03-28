#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[50];
vector<int>cra, box;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		cra.push_back(a);
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		box.push_back(a);
	}
	sort(cra.begin(), cra.end());
	sort(box.begin(), box.end());
	int idx = 0;
	if (cra[n-1] < box[k-1])
	{
		cout << "-1";
		return 0;
	}
	for (int i = 0; i < k; i++)
	{
		if (box[i] <= cra[idx])
		{
			arr[idx]++;
		}
		else
		{
			idx++;
			i--;
		}
	}
	int cnt = 0;
	int time = 0;
	while(1)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i; j >= 0; j--)
			{
				if (arr[j])
				{
					arr[j]--;
					cnt++;
					break;
				}
			}
			if (cnt == k)
				break;
		}
		time++;
		if (cnt == k)
			break;
	}
	
	cout << time;
}