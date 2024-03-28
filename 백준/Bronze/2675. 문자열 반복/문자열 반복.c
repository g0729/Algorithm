#include<stdio.h>
main() {
	int t, r,w;
	char s[20];
	w = 0;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%d%s", & r, s);
		while (s[w] != 0)
		{
			for (int q = 0; q < r; q++)
			{
				printf("%c", s[w]);
			}
			w++;
		}
		w = 0;
		printf("\n");
	}
	
}