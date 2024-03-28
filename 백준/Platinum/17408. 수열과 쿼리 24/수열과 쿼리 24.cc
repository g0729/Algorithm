#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000
vector<pair<int, int>> tree(4 * MAX);

pair<int, int> update(int start, int end, int node, int idx, int val)
{
    if (idx < start || idx > end)
        return tree[node];
    if (start == end)
        return tree[node] = {val, 0};

    int mid = (start + end) / 2;

    pair<int, int> leftChild, rightChild;
    leftChild = update(start, mid, node * 2, idx, val);
    rightChild = update(mid + 1, end, node * 2 + 1, idx, val);

    vector<int> temp = {leftChild.first, leftChild.second, rightChild.first, rightChild.second};

    sort(temp.begin(), temp.end(), greater<int>());

    return tree[node] = {temp[0], temp[1]};
}
pair<int, int> search(int start, int end, int node, int left, int right)
{
    if (right < start || left > end)
        return {0, 0};
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;

    pair<int, int> leftChild, rightChild;
    leftChild = search(start, mid, node * 2,left,right);
    rightChild = search(mid + 1, end, node * 2 + 1,left,right);

    vector<int> temp = {leftChild.first, leftChild.second, rightChild.first, rightChild.second};

    sort(temp.begin(), temp.end(), greater<int>());

    return {temp[0], temp[1]};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i =1 ; i<=n;i++)
    {
        int a;
        cin>>a;
        update(1,n,1,i,a);
    }
    int m;
    cin>>m;

    for (int i = 0; i < m; i++)
    {
        int op,a,b;
        cin>>op>>a>>b;

        if(op==1)
            update(1,n,1,a,b);
        else
        {
            pair<int,int>res=search(1,n,1,a,b);
            ll temp=(ll)res.first+res.second;

            cout<<temp<<"\n";
        }
    }
    
    return 0;
}