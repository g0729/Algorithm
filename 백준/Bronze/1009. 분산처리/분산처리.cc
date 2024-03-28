#include <stdio.h>
int f(int base,int n)
{
    if(n==0)
    return 1;
    int temp=f(base,n/2);
    int ans=(temp*temp)%10;
    if(n%2==0)
    return ans;
    else
    return (ans*base)%10;
}
int main(){
    int T, a, b, num;
    int i, j;
    scanf("%d", &T);
    for (i = 0; i < T; i++){
        scanf("%d %d", &a, &b);
        num = f(a,b);

        switch (num%10){
            case 1:
            printf("%d\n", 1);
            break;
            case 2:
            printf("%d\n", 2);
            break;
            case 3:
            printf("%d\n", 3);
            break;
            case 4:
            printf("%d\n", 4);
            break;
            case 5:
            printf("%d\n", 5);
            break;
            case 6:
            printf("%d\n", 6);
            break;
            case 7:
            printf("%d\n", 7);
            break;
            case 8:
            printf("%d\n", 8);
            break;
            case 9:
            printf("%d\n", 9);
            break;
            case 0:
            printf("%d\n", 10);
            break;
        }
    }
}