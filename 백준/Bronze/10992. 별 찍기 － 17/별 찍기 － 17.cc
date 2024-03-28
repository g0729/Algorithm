#include <stdio.h>
int main() {
    int num; scanf("%d", &num);
	if(num==1)
	{
		printf("*");
		return 0;
	}
    for (int i = 0; i < num - 1; i++)
        printf(" ");
    printf("* \n");
    
    int space1 = num - 2;
    int space2 = num - 1 - space1;
    for (int i = 0; i < num - 2; i++)
    {
        for (int i = 0; i < space1; i++)
            printf(" ");
        printf("*");
        for (int i = 0; i < space2; i++)
            printf(" ");
        printf("* \n");
        space1--;
        space2 += 2;
    }
    
    for (int i = 0; i < num * 2 - 1; i++)
        printf("*");
    printf("\n");
    return 0;
}