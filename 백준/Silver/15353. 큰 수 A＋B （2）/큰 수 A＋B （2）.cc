#include<bits/stdc++.h>
using namespace std;

#define MAX 10001
char a[MAX];
char b[MAX];
char res[MAX+1];
void rev(char *a1)
{
    int len = strlen(a1);
    for(int i = 0 ; i<len/2;i++)
    {
        char temp=a1[i];
        a1[i]=a1[len-i-1];
        a1[len-i-1]=temp;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    rev(a);
    rev(b);
    int len = strlen(a)>strlen(b)?strlen(a):strlen(b);
    int carry= 0 ;
    for(int i = 0;i<len;i++)
    {
        int sum=a[i]-'0'+b[i]-'0'+carry;
        while(sum<0)
        {
            sum+='0';
        }
        if(sum>9)
        {
            carry=1;
        }
        else
        {
            carry=0;
        }
        res[i]=sum%10+'0';
    }
    if(carry==1)
    {
        res[len]='1';
    }
    rev(res);
    cout<<res;
}