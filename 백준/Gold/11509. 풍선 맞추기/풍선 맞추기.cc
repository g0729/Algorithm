#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
vector<int>arrow;
int n;  
int res;
bool search(int target)
{
   for(int i= 0 ; i<arrow.size();i++)
   {
       if(arrow[i]<=0)
       continue;
       if(arrow[i]==target)
       {
           arrow[i]--;
           return true;
       }
   }
   return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        if(search(a))
        {
            continue;
        }
        else
        {
            res++;
            arrow.push_back(a-1);
        }
    }
    cout<<res;
}