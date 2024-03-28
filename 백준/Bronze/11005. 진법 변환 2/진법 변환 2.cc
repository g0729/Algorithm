#include <iostream>

int main()
{
    int n, b;
    std::cin >> n >> b;

    char result[100];
    int i=0;
    while(n!=0) {
        int temp = n%b;
        n/=b;
        result[i] = temp>9 ? temp-10+'A' : temp+'0';
        i++;
    }
    i--;
    for(; i>=0; i--)
        std::cout << result[i];
}