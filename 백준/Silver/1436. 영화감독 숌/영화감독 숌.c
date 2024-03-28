#include<stdio.h>
main()
{
	int n,i=666;
	int i_;
	int count = 0;
	scanf("%d", &n);
	
	while (count != n)
	{
		int s = 0;
		i_ = i;
		while (i_ > 0)
		{
			if (i_ % 10 == 6)
				s++;
			else
				s = 0;
			if (s == 3)
			{
				count++;
				break;
			}
			i_ /= 10;
		}
		i++;
	}
	printf("%d", i-1);
}