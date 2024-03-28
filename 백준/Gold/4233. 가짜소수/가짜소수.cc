#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
#define lint long long

lint p;

lint myPow(lint a, lint n)
{
    if (n == 0)
        return 1;
    lint temp = myPow(a, n / 2);
    lint ans = (temp * temp) % p;
    if (n % 2 == 0)
    {
        return ans;
    }
    else
    {
        return (ans * a) % p;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1)
    {
        lint a;
        cin>>p>>a;

        if(p==0&&a==0)
        return 0;

        bool flag=true;
        for(int i=2 ; i*i<=p;i++)
        {
            if(p%i==0)
            {
                flag=false;
                break;
            }
        }

        if(flag)
        {
            cout<<"no\n";
            continue;
        }

        lint MOD=myPow(a,p);

        if(MOD==a)
        cout<<"yes\n";
        else
        cout<<"no\n";
    }
    return 0;
}