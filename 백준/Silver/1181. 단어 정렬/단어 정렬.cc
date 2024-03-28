#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(string s1,string s2)
{
	if (s1.length() == s2.length())
		return s1 < s2;
	else 
	{
		return s1.length() < s2.length();
	}
}
int main()
{
	int n;
	cin >> n;
	string* arr = new string[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n,cmp);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr[i + 1])
			continue;
		cout << arr[i] << endl;
	}
}