#include <bits/stdc++.h>
using namespace std;

int main()
{
    int index = 1;

    int now;
    double proper;

    while (1)
    {
        cin >> proper >> now;

        if (now == 0 && proper == 0)
            return 0;

        char command;
        int n;
        bool dead=false;

        while (1)
        {

            cin >> command >> n;

            if (command == '#')
                break;
            
            if(command=='F')
                now+=n;
            else
            {
             now-=n;   
            }       
            if(now<=0)
                dead=true;        
        }

        cout<<index<<" ";
        if(dead)
            cout<<"RIP\n";
        else
        {
            if(now<=proper/2||now>=proper*2)
                cout<<":-(\n";
            else
                cout<<":-)\n";
        }    
        index++;
    }
}