#include<stdio.h>
#include<string.h>
#include<math.h>
main()
{
	int len,res=0;
	char a[7];
	scanf("%s", a);
	
	len = strlen(a);

	for (int i = 0; i <len; i++)
	{
		if (a[i] >= 'A')
		{
			res += (a[i]-'A'+10)*pow(16, len - 1 - i);
		}
		else
		{
			res += (a[i] - '0') * pow(16, len - 1 - i);
		}
	}

	printf("%d", res);
	
}