#include<iostream>
#include<algorithm>
using namespace std;

struct People {
	int age;
	string name;
};
bool cmp(const People&p1,const People&p2)
{
	return p1.age < p2.age;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	People* arr = new People[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i].age>>arr[i].name;
	stable_sort(arr, arr + n, cmp);
	
	for (int i = 0; i < n; i++)
		cout << arr[i].age << " " << arr[i].name << "\n";

}