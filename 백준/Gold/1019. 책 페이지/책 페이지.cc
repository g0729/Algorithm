#include<iostream>
using namespace std;
long long cnt[10];
void cal(long long n, long long temp)
{
	while (n > 0)
	{
		cnt[n % 10] += temp;
		n /= 10;
	}
}
void solution(long long start, long long end, long long ten)
{
	while (start % 10 != 0 && start <= end)
	{
		cal(start, ten);
		start++;
	}
	if (start > end)
	{
		return;
	}
	while (end % 10 != 9 && end >= start)
	{
		cal(end, ten);
		end--;
	}
	long long res = (end / 10 - start / 10) + 1;
	for (int i = 0; i < 10; i++)
	{
		cnt[i] += res * ten;
	}
	solution(start / 10, end / 10, ten * 10);
}
int main()
{
	long long n;
	cin >> n;
	solution(1, n, 1);

	for (int i = 0; i < 10; i++)
	{
		cout << cnt[i] << " ";
	}
}