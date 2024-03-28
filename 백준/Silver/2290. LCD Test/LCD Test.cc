#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin>>n>>s;
    for(int q = 0 ; q<s.length();q++)
    {
        switch (s[q])
        {
        case '1':
        case '4':
        for(int i= 0 ; i<n+2;i++)
        cout<<" ";
        cout<<" ";
        break;
        case '0':
        case '2':
        case '3':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        cout<<" ";
         for(int i = 0  ;i<n;i++)
        {
            cout<<"-";
        }
        cout<<" ";
        cout<<" ";
        break;
        }
    }
    cout<<"\n";
    for(int i = 0 ; i<n;i++)
    {
        for(int q = 0 ; q<s.length();q++)
        {
            switch (s[q])
            {
            case '1':
            case '2':
            case '3':
            case '7':
            for(int j = 0 ; j<n+1;j++)
            {
                cout<<" ";
            }
            cout<<"|";
            cout<<" ";
            break;
            case '4':
            case '8':
            case '9':
            case '0':
            cout<<"|";
            for(int j= 0;j<n;j++)
            {
                cout<<" ";
            }
            cout<<"|";
            cout<<" ";
            break;
            case '5':
            case '6':
            cout<<"|";
            for(int j = 0 ; j<n+1;j++)
            {
                cout<<" ";
            }
            cout<<" ";
            break;
            }
        }
        cout<<"\n";
    }
    for(int i = 0 ; i<s.length();i++)
    {
        switch (s[i])
        {
        case '1':
        case '7':
        case '0':
        for(int q = 0 ; q<n+2;q++)
        {
            cout<<" ";
        }
        cout<<" ";
        break;
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '8':
        case '9':
        cout<<" ";
        for(int q = 0 ; q<n;q++)
        {
            cout<<"-";
        }
        cout<<" ";
        cout<<" ";
        break;
        }
    }
    cout<<"\n";
    for(int i = 0 ; i<n;i++)
    {
        for(int q = 0 ; q<s.length();q++)
        {
            switch (s[q])
            {
            case '1':
            case '7':
            case '9':
            for(int j = 0 ; j<n+1;j++)
            {
                cout<<" ";
            }
            cout<<"|";
            cout<<" ";
            break;
            case '2':
            cout<<"|";
            for(int j=0;j<n+1;j++)
            {
                cout<<" ";
            }
            cout<<" ";
            break;
            case '3':
            case '4':
            case '5':
                for(int j = 0 ; j<n+1;j++)
            {
                cout<<" ";
            }
            cout<<"|";
            cout<<" ";
            break;
            case '6':
            case '8':

            case '0':
             cout<<"|";
            for(int j= 0;j<n;j++)
            {
                cout<<" ";
            }
            cout<<"|";
            cout<<" ";
            break;
            }
        }
        cout<<"\n";
    }
    for(int i = 0 ; i<s.length();i++)
    {
        switch (s[i])
        {
        case '1':
        case '4':
        case '7':

        for(int q = 0 ; q<n+2;q++)
        {
            cout<<" ";
        }
        cout<<" ";
        break;
        case '0':
        case '2':
        case '3':
        case '5':
        case '6':
        case '8':
        case '9':
        cout<<" ";
        for(int q = 0 ; q<n;q++)
        {
            cout<<"-";
        }
        cout<<" ";
        cout<<" ";
        break;
        }
    }
}