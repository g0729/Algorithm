#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout.precision(4);
    int t;
    cin>>t;
    while(t--)
    {
        double a;
        cin>>a;
        string s;
        cin>>s;
        cout<<fixed;
        if(s=="kg")
        {
            cout<<a*2.2046<<" lb\n";
        }
        else if(s=="l")
        {
            cout<<a*0.2642<<" g\n";
        }
        else if(s=="lb")
        {
            cout<<a*0.4536<<" kg\n";
        }
        else
        {
            cout<<a*3.7854<<" l\n";
        }

    }
    return 0;
}