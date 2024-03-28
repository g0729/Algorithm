#include "stdio.h"
int main()
{
	int n,a;
	int arr[1000] = { 0 };
	int max = 0;
	double ave;
	int total = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a > max)
			max = a;
		total += a;
	}

	ave = (double)total/n;
	ave = (double)ave / max * 100;

	printf("%f",ave);

}
