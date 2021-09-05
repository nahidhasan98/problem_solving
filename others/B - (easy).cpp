#include<bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c,d;

    while(cin>>a>>b>>c>>d)
    {
        double sr=a/b;
        double counter=1;

        double za=c/d;
        double counter2=1;

        while(sr<1 && za<1)
        {
            sr+=a/b;
            counter++;

            za+=c/d;
            counter2++;
        }

        double res=1;

        if(sr>=1)
        {
            double total=(counter*2)-1;

            //cout<<total<<' '<<counter<<endl;
            res=counter/total;
        }
        else if(za>=1)
        {
            double total2=counter2*2;

            double res2=counter2/total2;

            res=1-res2;
        }


        cout<<fixed<<setprecision(8)<<res<<endl;
    }

    return 0;
}
