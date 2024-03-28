#include<stdio.h>
main()
{
	int n[8];
	int boo=0;
	
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &n[i]);
	}
	for (int i = 0; i < 7; i++)
	{
		n[i] = n[i + 1] - n[i];
	}
	for (int i = 0; i < 6; i++)
	{
		if (n[i] != n[i + 1])
		{
			boo = 2;
			break;
		}
	}
	if (boo == 2)
		printf("mixed");
	else
		if (n[0] == 1)
			printf("ascending");
		else
			printf("descending");
	
}