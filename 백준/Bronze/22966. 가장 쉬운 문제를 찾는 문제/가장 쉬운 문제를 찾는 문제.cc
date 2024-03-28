#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int min=5;
    string res;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a;
        string temp;
        cin>>temp>>a;
        if(a<min)
        {
            min=a;
            res=temp;
        }
    }
    cout<<res;
}