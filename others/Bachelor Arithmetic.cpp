#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc=1;
    double b,s;

    while(cin>>b>>s)
    {
        if(b==0 && s==0)
            break;

        double before=min(s/b,1.0);

        b--;
        s--;

        cout<<"Case "<<tc<<": ";

        if(b==0)
            cout<<":-\\"<<endl;
        else
        {
            double after=min(s/b,1.0);

            if(before==after)
                cout<<":-|"<<endl;
            else if(before<after)
                cout<<":-)"<<endl;
            else if(before>after)
                cout<<":-("<<endl;
        }

        tc++;
    }

    return 0;
}
