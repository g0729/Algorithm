#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n,Top;
    scanf("%d",&n);
    char S[51];
    
    for(int i=0;i<n;i++)
    {
        Top=0;
        scanf("%s",S);
        int sLen=strlen(S);
        for(int j=0;j<sLen;j++)
        {
            if(S[j]=='(')Top++;
            else if(S[j]==')')Top--;
            if(Top<0)break;
        }
        if(Top==0)printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}