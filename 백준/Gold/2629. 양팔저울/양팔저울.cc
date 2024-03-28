#include <bits/stdc++.h>
using namespace std;
#define MAX 15001
bool arr[30][MAX];
int weight[30];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    arr[0][weight[0]] = true;
    for (int i = 1; i < n; i++)
    {
        arr[i][weight[i]] = true;
        for (int j = 0; j < MAX; j++)
        {
            if (arr[i - 1][abs(j - weight[i])])
            {
                arr[i][j] = true;
            }
            if (arr[i - 1][j])
                arr[i][j] = true;
            if(arr[i-1][j+weight[i]])
            arr[i][j]=true;
        }
    }
   int k;
   cin>>k;
   for (int i = 0; i < k; i++)
   {
       int a;
       cin>>a;
       if(a>=MAX)
       cout<<"N ";
       else
       {
           if(arr[n-1][a])
           cout<<"Y ";
           else
           cout<<"N ";
       }
   }

   
}