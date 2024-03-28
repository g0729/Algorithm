#include<iostream>
#include<algorithm>
using namespace std;
int l, c;
char* arr;
int cnt = 0;
bool* sel;
void print()
{
	for (int i = 0; i < c; i++)
		if (sel[i] == true)
			cout << arr[i];
	cout << "\n";
}
void DFS(int idx,int a)
{
	if (a == l)
	{
		if (cnt == 0 || l- cnt < 2)
			return;
		print();
		return;
	}
	for (int i = idx;i<c; i++)
	{
		if (sel[i] == true)
			continue;
		sel[i] = true;
		if (arr[i] == 'a' || arr[i] == 'i' || arr[i] == 'e' || arr[i] == 'o' || arr[i] == 'u')
		{
			cnt++;
		}
		DFS(i, a + 1);
		if (arr[i] == 'a' || arr[i] == 'i' || arr[i] == 'e' || arr[i] == 'o' || arr[i] == 'u')
		{
			cnt--;
		}
		sel[i] = false;
	}
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> l>> c;
	arr = new char[c];
	sel = new bool[c];
	for (int i = 0; i < c; i++)
	{
		sel[i] = false;
	}
	for (int i = 0; i < c; i++)
		cin >> arr[i];
	sort(arr, arr + c);
	DFS(0, 0);
}