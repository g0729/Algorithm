#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    int i=1;
    while(t--)
    {
        int arr[3];

        cin>>arr[0]>>arr[1]>>arr[2];

        sort(arr,arr+3);

        cout<<"Scenario #"<<i<<":\n";
        if(arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2])
        cout<<"yes\n";
        else
        cout<<"no\n";

        cout<<endl;
        i++;
    }
}