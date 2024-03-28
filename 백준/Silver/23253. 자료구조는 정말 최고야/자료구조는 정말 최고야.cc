#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    bool check =true;
    
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        for(int q= 0; q<a;q++)
        {
            int k,temp;
            if(q==0)
            {
                cin>>k;
                temp=k;
            }
            else
            {
                cin>>k;
                if(temp<k)
                check=false;
                temp=k;
            }
        }
    }
    if(check)
    cout<<"Yes";
    else
    cout<<"No";
}