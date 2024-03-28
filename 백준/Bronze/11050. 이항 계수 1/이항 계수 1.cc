#include<iostream>
using namespace std;

long long factorial(int a, int b)
{
	
	long long res = 1;
	for (int i = a; i > a-b; i--)
	{
		
		res =res* i / (a+1-i);
	}
	return res;
}

int main()
{
	int n, k;
	cin >> n >> k;

	cout << factorial(n, k);
}