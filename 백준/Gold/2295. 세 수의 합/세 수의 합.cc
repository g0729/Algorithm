#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> v;
bool binsearch(int target)
{
	int start=0;
	int end=v.size()-1;
	while(start<end)
	{
		int mid=(start+end)/2;
		if(v[mid]<target)
		{
			start=mid+1;
		}
		else if(v[mid]>target)
		{
			end=mid-1;
		}
		else
		{
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			v.push_back(arr[i] + arr[j]);
		}
	}

	sort(arr.begin(), arr.end());
	sort(v.begin(), v.end());

	for (int i = n-1; i >=0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if(binsearch(arr[i]-arr[j]))
			{
				cout<<arr[i];
				return 0;
			}
		}
		
	}
	
}