#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

bool arr[1001][1001];
struct FourInt{
    int a,b,c,d;
    FourInt(int a,int b,int c,int d) :a(a),b(b),c(c),d(d){};
};
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int n;
cin>>n;
vector<FourInt>v;

for(int i = 0; i < n; i++)

{
    int a,b,c,d;
    cin>>a>>b>>c>>d;    
    FourInt temp(a,b,c,d);
    v.push_back(temp);
}
stack<int>ans;
for(int k=v.size()-1; k>=0; k--)
{
    int a,b,c,d;
    a=v[k].a;
    b=v[k].b;
    c=v[k].c;
    d=v[k].d;    
    int res=c*d;
    for(int i=a;i<a+c;i++)
    {
        for(int j=b;j<b+d;j++)
        {
            if(arr[i][j])
                res--;
            arr[i][j]=true;
        }
    }
    ans.push(res);
}
while(!ans.empty())
{
    cout<<ans.top()<<"\n";
    ans.pop();
}
return 0;
}