#include<iostream>
using namespace std;
int n, m;
int arr[8];
bool sel[8];
void print()
{
	for (int i = 0; i < 8; i++)
		if (sel[i] == true)
			cout << arr[i] << " ";
		cout << endl;
}
void DFS(int idx, int a)
{
	if (a == m)
	{
		print();
		return;
	}
	for (int i = idx; i < n; i++)
	{
		if (sel[i] == true)
			continue;
		sel[i] = true;
		DFS(i,a + 1);
		sel[i] = false;
	}
}
int main()
{
	for (int i = 0; i < 8; i++)
		arr[i] = i + 1;
	cin >> n >> m;
	DFS(0,0);
}