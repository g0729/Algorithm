#include<bits/stdc++.h>
using namespace std;

int main()

{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>v;

    while(1)
    {
        int n;
        cin>>n;
        if(cin.eof())
            break;
        v.push_back(n);
    }

    bool flag=true;
    for(int i = 0; i<v.size()-1;i++)
    {
        if(v[i]>v[i+1])
        {
            flag=false;
            break;
        }
    }

    if(flag)
        cout<<"Good";
    else
        cout<<"Bad";
}