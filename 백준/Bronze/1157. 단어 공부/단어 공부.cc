#include<stdio.h>

int main()
{
	char word[1000001];
	int alpha[27] = { 0, };
	int i, max = 0, maxi = 0;
	int count = 0;

	scanf("%s", word);

	for (i = 0;  word[i] != 0; i++)
	{
		if (word[i] >= 65 && word[i] <= 90) {
			alpha[word[i] - 65]++;
		}
		else if (word[i] >= 97 && word[i] <= 122) {
			alpha[word[i] - 97]++;
		}
	}

	for (i = 0; i < 27; i++)
	{
		if (alpha[i] > max)
		{
			max = alpha[i];
			maxi = i;
		}
	}


	for (i = 0; i < 27; i++)
	{
		if (max == alpha[i]) count++;
	}


	if (count >= 2) printf("?");
	else if (count == 1) printf("%c", maxi + 65);

}