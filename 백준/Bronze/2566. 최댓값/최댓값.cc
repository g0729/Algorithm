#include <bits/stdc++.h>
using namespace std;

int main()
{
	int row,col,MAX;

	MAX=-1;

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			int a;

			cin>>a;

			if(a>MAX)
			{
				row=i;
				col=j;
				MAX=a;
			}

		}
		
	}
	
	cout<<MAX<<endl<<row<<" "<<col;
}