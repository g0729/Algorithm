#include<string.h>
#include<stdio.h>
main()
{
	char word[101];
	int len, i = 0, count = 0;
	scanf("%s", word);
	len = strlen(word);
	while (i < len)
	{
		if (word[i] == 'c' && word[i + 1] == '=') {
			i += 2;
			count++;
		}
		else if (word[i] == 'c' && word[i + 1] == '-') {
			i += 2;
			count++;
		}
		else if (word[i] == 'd' && word[i + 1] == 'z' && word[i + 2] == '=') {
			i += 3;
			count++;;	
		}
		else if (word[i] == 'd' && word[i + 1] == '-') {
			i += 2;
			count++;
		}
		else if (word[i] == 'l' && word[i + 1] == 'j') {
			i += 2;
			count++;
		}
		else if (word[i] == 'n' && word[i + 1] == 'j') {
			i += 2;
			count++;
		}
		else if (word[i] == 's' && word[i + 1] == '=') {
			i += 2;
			count++;
		}
		else if (word[i] == 'z' && word[i + 1] == '=') {
			i += 2;
			count++;
		}
		else {
			i++;
			count++;
		}
	}

	printf("%d", count);
}