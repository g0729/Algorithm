#include<bits/stdc++.h>
using namespace std;
#define MAX 250000
bool primeArr[MAX];
void eratos()
{
    memset(primeArr,true,sizeof(primeArr));
    primeArr[0]=primeArr[1]=false;

    for(int i =2 ; i*i <=MAX;i++)
    {
        if(primeArr)
        {
            for(int j=i*i;j<=MAX;j+=i)
            {
                primeArr[j]=false;
            }
        }
    }

}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   eratos();
   while(1)
   {
       int n;
       cin>>n;
       if(n==0)
       break;
       int cnt=0;
       for(int i =n+1;i<=2*n;i++)
       {
           if(primeArr[i])
           cnt++;
       }
       cout<<cnt<<"\n";
   }
}