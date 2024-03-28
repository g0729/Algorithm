#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[3];
    int arr2[3];

    for (int i = 0; i < 3; i++)
    {
        cin>>arr1[i];
    }
    
    for (int i = 0; i < 3; i++)
    {
        cin>>arr2[i];
    }
    
    int arr3[3];

    arr3[0]=arr2[0]-arr1[0];

    
    if(arr1[1]>arr2[1])
    {
        arr3[0]--;
    }
    else if(arr1[1]==arr2[1])
    {
        if(arr1[2]>arr2[2])
        arr3[0]--;
    }

    arr3[1]=arr2[0]-arr1[0];

    cout<<arr3[0]<<endl<<arr3[1]+1<<endl<<arr3[1];
}