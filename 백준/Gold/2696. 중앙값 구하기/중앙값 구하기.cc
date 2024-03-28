#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int>min_heap;
    priority_queue<int,vector<int>,greater<int>>max_heap;

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<n/2+1<<"\n";
        for (int i = 0; i < n; i++)
        {
            int a;
            cin>>a;
            if(i%2==1)
                min_heap.push(a);
            else
                max_heap.push(a);
            if(!min_heap.empty()&&min_heap.top()>max_heap.top())
            {
                int temp1,temp2;
                temp1=min_heap.top();
                temp2=max_heap.top();
                min_heap.pop();
                max_heap.pop();
                min_heap.push(temp2);
                max_heap.push(temp1);
            }
            if(i%2==0)
            cout<<max_heap.top()<<" ";
        }
        while(!min_heap.empty())
        {
            min_heap.pop();
        }
        while(!max_heap.empty())
        {
            max_heap.pop();
        }
    }
}