#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr1[9];
    int arr2[9];

    for (int i = 0; i < 9; i++)
    {
        cin>>arr1[i];
    }
     for (int i = 0; i < 9; i++)
    {
        cin>>arr2[i];
    }

    int sum1,sum2;
    sum1=sum2=0;

    for (int i = 0; i < 9; i++)
    {
        sum1+=arr1[i];

        if(sum1>sum2)
        {
            cout<<"Yes";
            return 0;
        }
        sum2+=arr2[i];
    }
    
    cout<<"No";
    return 0;
}
