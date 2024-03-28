#include<stdio.h>
#include<math.h>
main()
{
	int n;
	scanf("%d", &n);
	int cnt = pow(2, n) - 1;
	printf("%d\n", cnt);
	hanoi(n, 1, 2, 3);

}
hanoi(int n, int from,int temp, int to)
{
	if (n == 1)
		printf("%d %d\n", from, to);
	else
	{
		hanoi(n - 1, from, to, temp);
		printf("%d %d\n", from ,to);
		hanoi(n - 1, temp, from, to);
	}
}