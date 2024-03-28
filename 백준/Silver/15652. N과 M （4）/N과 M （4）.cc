#include<iostream>
#include<vector>
using namespace std;
vector <int> v;
int n,m;
void print()
{
	for (int i = 0; i < m; i++)
		cout << v[i] << " ";
		cout<<"\n";
}
void DFS(int idx,int a)
{
	if (a == m)
	{
		print();
		return;
	}
	for (int i = idx; i < n; i++)
	{
		v.push_back(i + 1);
		DFS(i,a + 1);
		v.pop_back();
	}
}
int main()
{
	cin >> n >> m;
	DFS(0,0);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}