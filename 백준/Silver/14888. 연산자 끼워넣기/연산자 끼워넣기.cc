#include<iostream>
#include<vector>
#define max 1000000000;
using namespace std;
int big = -max
int small = max;
vector <int> v;
int n;
int ope[4];
int sum=0;

int cal(int a, int b, int i)
{
	if (i == 0)
		return a + b;
	if (i == 1)
		return a - b;
	if (i == 2)
		return a * b;
	return a / b;
}
void DFS(int a)
{
	if (a == n-1)
	{
		if (sum > big)
			big = sum;
		if (sum < small)
			small = sum;
		return;
	}
	int csum = sum;
	for (int i = 0; i < 4; i++)
	{
		if (ope[i] != 0)
		{
			sum = cal(sum, v[a + 1], i);
			ope[i]--;
			DFS(a + 1);
			ope[i]++;
			sum = csum;
		}
	}
}
int main()
{
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sum = v[0];
	for (int i = 0; i < 4; i++)
	{
		cin >> ope[i];
	}
	DFS(0);

	cout << big << endl << small;
}