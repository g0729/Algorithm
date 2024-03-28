#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int arr[4]={0,1,2,3};

    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;

        swap(arr[a],arr[b]);
    }
    
    for (int i = 1; i <= 3; i++)
    {
        if(arr[i]==1)
        cout<<i;
        
    }
    
    return 0;
}