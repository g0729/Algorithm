#include<stdio.h>
int main()
{
	int N, i, A[200000] = { 0 };
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
	i = N - 2;
	while (i)
	{
		if (i == 1)
		{
			A[0]--;
			A[N - 1]--;
		}
		else
		{
			if (A[0] >= A[N - 1])
				A[0]--;
			else
				A[N - 1]--;
		}
		i--;
	}
	if (A[0] >= A[N - 1])
		printf("%d", A[0]);
	else
		printf("%d", A[N - 1]);
	return 0;
}