#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a_res, b_res;
    a_res = b_res = 0;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        a_res+=(n/30+1)*10;
        b_res+=(n/60+1)*15;
    }
    if(a_res==b_res)
    {
        cout<<"Y M "<<a_res;
    }
    else if(a_res>b_res)
    {
        cout<<"M "<<b_res;
    }
    else
    {
        cout<<"Y "<<a_res;
    }
}