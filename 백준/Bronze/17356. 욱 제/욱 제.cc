#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{

	int a, b;
	cin >> a >> b;

	double m = (double)(b - a) / 400;

	printf("%.20f", 1 / (1 + pow(10, m)));

	return 0;
}