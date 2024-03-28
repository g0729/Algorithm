#include<stdio.h>

int main(void)
{
	char S[101];

	scanf("%s", S);

	for (int ascii = 97; ascii < 123; ascii++)
	{
		int count = 0;
		for (int i = 0; S[i] != NULL; i++)
		{
			if (S[i] == ascii)
			{
				printf("%d ", i);
				count++;
				break;
			}
		}
		if (count == 0) printf("-1 ");	
	}
	return 0;
}