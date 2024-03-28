#include <bits/stdc++.h>
using namespace std;

int main()
{
    int res = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char temp;
            cin >> temp;
            if (temp == 'F')
            {
                if (i % 2 == 0)
                {
                    if(j%2==0)
                    {
                        res++;
                    }
                }
                else
                {
                    if(j%2==1)
                    {
                        res++;
                    }
                }
            }
        }
    }
    cout<<res;
}