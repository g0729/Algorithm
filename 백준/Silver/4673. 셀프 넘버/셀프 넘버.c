#include<stdio.h>
int d(int n)
{
	int a;
	a = n;
	while (n > 0)
	{
		a = a + n % 10;
		n =n/ 10;
	}
	return a;
}

main()
{
	int arr[10001] = {0}, result = 0;
	for (int i = 0; i < 10001; i++) {
		result = d(i);
		if (result < 10001)
			arr[result] = 1;
	}
	for (int j = 0; j < 10001; j++) {
		if (arr[j] != 1)
			printf("%d\n", j);
	}


}
