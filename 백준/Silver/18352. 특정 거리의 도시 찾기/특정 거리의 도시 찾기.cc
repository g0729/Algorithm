#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

vector<int> v[300001];
bool visited[300001];
int n, m, k, x;

void bfs()
{
	queue<int>q;

	q.push(x);
	visited[x]=true;
	int cnt=0;
	while(cnt<k)
	{
		int size=q.size();

		while(size--)
		{
			int now=q.front();
			q.pop();

			for (int i = 0; i < v[now].size(); i++)
			{
				int next=v[now][i];

				if(visited[next])
					continue;

				visited[next]=true;
				q.push(next);
			}
		}
		cnt++;
	}
	if(q.empty())
		cout<<"-1";
	else
	{
		vector<int>temp;
		while(!q.empty())
		{
			temp.push_back(q.front());
			q.pop();
		}

		sort(temp.begin(),temp.end());

		for (int i = 0; i < temp.size(); i++)
		{
			cout<<temp[i]<<"\n";
		}
		
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	bfs();
	return 0;
}