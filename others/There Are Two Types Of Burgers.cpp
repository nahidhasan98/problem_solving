#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int b,p,f,h,c,counter=0;
        cin>>b>>p>>f>>h>>c;

        if(h>=c)
        {
            if(b>=p*2)
            {
                counter+=h*p;
                b-=p*2;

                if(b>=f*2)
                    counter+=c*f;
                else
                    counter+=(b/2)*c;
            }
            else
                counter+=(b/2)*h;
        }
        else
        {
            if(b>=f*2)
            {
                counter+=c*f;
                b-=f*2;

                if(b>=p*2)
                    counter+=h*p;
                else
                    counter+=(b/2)*h;
            }
            else
                counter+=(b/2)*c;
        }

        cout<<counter<<endl;
    }

    return 0;
}
