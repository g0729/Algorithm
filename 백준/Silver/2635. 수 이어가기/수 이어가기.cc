#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin>>n;

    int res=4;
    int res_value=n;

    int arr[3];
    arr[0]=n;

    for (int i = 1; i < n; i++)
    {
        int cnt=2;
        arr[0]=n;
        arr[1]=i;
        while(1)
        {
            arr[2]=arr[0]-arr[1];
            if(arr[2]<0)
            {
                break;
            }
            arr[0]=arr[1];
            arr[1]=arr[2];
            cnt++;
        }

        if(cnt>res)
        {
            res=cnt;
            res_value=i;
        }
    }
    
    cout<<res<<"\n";
    

    arr[0]=n;
    arr[1]=res_value;
    cout<<arr[0]<<" "<<arr[1]<<" ";
     while(1)
        {
            arr[2]=arr[0]-arr[1];
            if(arr[2]<0)
            {
                break;
            }
            arr[0]=arr[1];
            arr[1]=arr[2];
           cout<<arr[2]<<" ";
        }

}