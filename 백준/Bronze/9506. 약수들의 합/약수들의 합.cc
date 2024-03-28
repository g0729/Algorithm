#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int num = 0, sum = 0, count1 = 0, count2 = 0;

int main()
{
    while (1)
    {
        sum = 0;
        count2 = 0;
        count1 = 0;
        scanf("%d", &num);
        if (num == -1)
        {
            break;
        }
        for (int i = 1; i < num; i++)
        {
            if (num % i == 0)
            {
                sum += i;
                count1++;
            }
        }
        if (sum != num)
        {
            printf("%d is NOT perfect.\n", num);
        }
        else
        {
            printf("%d = ", num);
            for (int i = 1; i < num; i++)
            {
                if (num % i == 0)
                {
                    printf("%d ", i);
                    count2++;
                    if (count2 < count1)
                    {
                        printf("+ ");
                    }
                }
            }
            printf("\n");
        }
    }
}