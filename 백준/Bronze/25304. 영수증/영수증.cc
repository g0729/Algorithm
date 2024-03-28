#include<stdio.h>
using namespace std;
int main() 
{
	int a, b, c, d, result = 0;
	scanf("%d %d", &a,&b);
	for (int i = 0; i < b; i++)
	{
		scanf("%d %d", &c ,& d);
		int e = c * d;
		result += e;
	}
	if (a == result)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
    }
}