#include<bits/stdc++.h>
using namespace std;
#define MAX 201

bool visited[MAX][MAX][MAX];
vector<int>res;
int A, B, C;

void bfs()
{
	queue<tuple<int, int, int>>q;
	q.push({ 0,0,C });
	while (!q.empty())
	{
		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int c = get<2>(q.front());
		q.pop();
		if(visited[a][b][c] == true)
		{
			continue;
		}
		visited[a][b][c] = true;
		if (a == 0)
		{
			res.push_back(c);
		}
		if (c + a > A)
			q.push({ A,b,c + a - A });
		else
			q.push({ c + a,b,0 });
		if (c + b > B)	
			q.push({ a,B,c + b - B });
		else
			q.push({ a,c + b,0 });
		if (a + b > B)
			q.push({ a + b - B,B,c });
		else
			q.push({ 0,a + b,c });
		if (a + c > C)
			q.push({ a + c - C,b,C });
		else
			q.push({ 0,b,a + c });
		if (b + a > A)
			q.push({ A,b + a - A,c });
		else
			q.push({ a + b, 0, c });
		if (b + c > C)
			q.push({ a,b + c - C,C });
		else
			q.push({ a,0,b + c });
	}

}
int main()
{
	cin >> A >> B >> C;
	bfs();
	sort(res.begin(),res.end());
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
}