#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
main()
{
	int t,res;
	bool* PrimeArray=malloc(sizeof(bool)*10000);
	
	PrimeArray[1] = false;

	for (int i = 2; i <= 10000; i++)
		PrimeArray[i] = true;
	for (int i = 2; i * i <= 10000; i++)
	{
		if (PrimeArray[i])
		{
			for (int j = i * i; j <= 10000; j += i)
				PrimeArray[j] = false;
		}
	}

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		for (int j = 2; j <= n/2; j++)
		{
			if (PrimeArray[j] && PrimeArray[n - j])
				res = j;
		}
		printf("%d %d\n", res, n - res);
	}
}