#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int n, m;
vector<int> v[10001];
bool visited[10001];
int arr[10001];
int bfs(int start)
{
	int res=1;
	visited[start]=true;
	queue<int>q;
	q.push(start);

	while(!q.empty())
	{
		int now=q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++)
		{
			int next=v[now][i];

			if(visited[next])
			continue;

			q.push(next);
			visited[next]=true;
			res++;
		}
	}

	memset(visited,false,sizeof(visited));
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin>>n>>m;

	for (int i = 0; i < m; i++)
	{
		int a,b;
		cin>>a>>b;

		v[b].push_back(a);
	}


	int Max=0;
	for (int i = 1; i <= n; i++)
	{
		arr[i]=bfs(i);
		Max=max(Max,arr[i]);
	}
	
	for (int i = 1; i <= n; i++)
	{
		if(arr[i]==Max)
		cout<<i<<" ";
	}
	
	return 0;
}