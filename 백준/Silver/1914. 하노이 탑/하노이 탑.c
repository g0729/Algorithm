#include<stdio.h>
#include<math.h>
#include<string.h>
main()
{
	int n;
	char arr[1000] = { 0, };
	arr[0] = '1';
	scanf("%d", &n);
	calculator(arr, n);
	printf("\n");
	if (n <= 20)
		hanoi(n, 1, 2, 3);
}
hanoi(int n, int from, int temp, int to)
{
	if (n == 1)
		printf("%d %d\n", from, to);
	else
	{
		hanoi(n - 1, from, to, temp);
		printf("%d %d\n", from, to);
		hanoi(n - 1, temp, from, to);
	}
}
int calculator(char* arr[],int n)
{
	
	int q;
	char temp[1000];
	int carry=0;
	for (q = 0; arr[q] != 0; q++)
		temp[q] = arr[q];
	if (n == 0)
	{
		arr[0] -= 1;
		for (int i = q - 1; i >= 0; i--)
		{
			printf("%c", arr[i]);
		}
		return 0;
	}
	for (int i = 0; i < q; i++)
	{

		int sum = arr[i] - '0' + temp[i] - '0' + carry;
		if (sum > 9)
			carry = 1;
		else
			carry = 0;
		arr[i] = sum % 10 + '0';

	}
	if (carry == 1)
		arr[q] = '1';
	return calculator(arr, n - 1);
}