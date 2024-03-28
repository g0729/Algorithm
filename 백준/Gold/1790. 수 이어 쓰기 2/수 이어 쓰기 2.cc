#include<bits/stdc++.h>
using namespace std;
#define lint  long long
lint n, k;
lint mypow(lint a)
{
    lint res = 9;
    lint mo = a - 1;
    while (mo--)
    {
        res *= 10;
    }
    return a * res;
}
lint ppow(int a)
{
    lint res = 1;
    for (int i = 0; i < a; i++)
    {
        res *= 10;
    }
    return res;
}
int main()
{
    lint sum = 0;
    cin >> n >> k;
    int digit = 1;
    while (sum < k)
    {
        sum += mypow(digit);
        digit++;
    }

    digit -= 1;
    sum -= mypow(digit);
    k -= sum;
    
    lint temp;
    if (k % digit == 0)
    {
        temp = ppow(digit - 1) + k / digit - 1;
    }
    else
    {
       temp= ppow(digit - 1) + k/ digit;
    }
    if (n < temp)
    {
        cout << "-1";
        return 0;
    }

    lint remain = k% digit;
    string s = to_string(temp);
    if (remain == 0)
    {
        cout << s.back();
    }
    else
    {
        cout << s[remain-1];
    }

}