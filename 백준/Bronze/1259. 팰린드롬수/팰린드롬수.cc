#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char symbol, str[100000];
    while (scanf("%s", str)) {

        if (str[0] == '0') break;
        int size = strlen(str), count = 0;
        for (int i = 0; i < size; i++) {
            symbol = str[i];
            if (symbol == str[size - i - 1]);
            else count++;
        }
        if (count != 0) printf("no\n");
        else printf("yes\n");
    }
}