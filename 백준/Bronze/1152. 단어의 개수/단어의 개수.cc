#include <stdio.h>
#include <string.h>

main()
{
	char s[1000000];
    int c=1;
        


	scanf("%[^\n]", s);

	if (s[0] == ' ') c--;
	if (s[strlen(s) - 1] == ' ') c--;

	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ') c++;
	}

	printf("%d", c);
}