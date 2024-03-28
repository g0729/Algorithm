#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

struct Node
{
    char leftChild, rightChild;
};
vector<Node> v(26);


void Preorder(char node)
{
    if(node=='.')
    return;
    cout<<node;
    Preorder(v[node].leftChild);
    Preorder(v[node].rightChild);
}
void Inodrer(char node)
{
    if(node=='.')
    return;
    Inodrer(v[node].leftChild);
    cout<<node;
    Inodrer(v[node].rightChild);
}
void Postorder(char node)
{
    if(node=='.')
    return;
    Postorder(v[node].leftChild);
    Postorder(v[node].rightChild);
    cout<<node;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        char a,b,c;
        cin>>a>>b>>c;
        v[a].leftChild=b;
        v[a].rightChild=c;
    }

    Preorder('A');
    cout<<endl;
    Inodrer('A');
    cout<<endl;
    Postorder('A');

    return 0;
}