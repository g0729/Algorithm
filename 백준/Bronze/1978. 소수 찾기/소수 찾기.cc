#include <stdio.h>
int main()
{
int N, C, cnt, s;
cnt=0;
scanf("%d", &N);
while (N != 0)
{
	scanf("%d", &s);
	for (int i = s; i >= 1; i--)
	{
		if (s % i == 0)
			C++;
	}
if (C == 2)
	cnt++;
C = 0;
N--;
}
printf("%d\n", cnt);
return 0;
}