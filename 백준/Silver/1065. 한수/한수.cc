#include <stdio.h>
int main() {
	int n, cnt = 0, one = 0, ten = 0, hund = 0;
	int thum[2] = { 0 };

	scanf("%d", &n);

	if (n <= 99) {
		for (int i = 0; i < n; i++) {
			cnt++;
		}
		printf("%d", cnt);
		return 0;
	} 
	for (int i = 1; i < 100; i++) {
		cnt++;
	}
	for (int i = 100; i <= n; i++) {
		one = i % 10;
		ten = (i % 100) / 10;
		hund = (i % 1000) / 100;

		thum[0] = hund - ten;
		thum[1] = ten - one;

		if (thum[0] == thum[1]) {
			cnt++;
		}
	}
	if(n==1000)
		cnt--;
	printf("%d", cnt);

	return 0;
}