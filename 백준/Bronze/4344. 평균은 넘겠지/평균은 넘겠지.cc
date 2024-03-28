#include<stdio.h>
main()
{
	int c,n,ave,per;
	int score[1000] = {0};
	ave = per = 0;
	scanf("%d", &c);
	for (int i = 0; i < c; i++)
	{
		scanf("%d", &n);
		for (int q = 0; q < n; q++)
		{
			scanf("%d", &score[q]);
			ave += score[q];
		}
		ave = ave / n;
		for (int q = 0; q < n; q++)
		{
			if (score[q] > ave)
				per++;
		}
		printf("%.3lf%%\n", (double)per / n * 100);
		ave = per = 0;
	}
}