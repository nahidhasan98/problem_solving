#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int n;

    while(cin>>n)
    {
        int a1,b1,c1,a2,b2,c2;
        cin>>a1>>b1>>c1>>a2>>b2>>c2;

        int counter=0,diff11,diff12,diff21,diff22,diff31,diff32,ii,jj,kk;

        for(int i=1; i<=n; i++)
        {
            if(i==n)
                ii=0;
            else if(i==n-1)
                ii=-1;
            else
                ii=i;

            diff11=abs(ii-a1);
            diff12=abs(ii-a2);

            for(int j=1; j<=n; j++)
            {
                if(j==n)
                    jj=0;
                else if(j==n-1)
                    jj=-1;
                else
                    jj=j;

                diff21=abs(j-b1);
                diff22=abs(j-b2);

                for(int k=1; k<=n; k++)
                {
                    if(k==n)
                        kk=0;
                    else if(k==n-1)
                        kk=-1;
                    else
                        kk=k;

                    diff31=abs(kk-c1);
                    diff32=abs(kk-c2);

                    cout<<i<<' '<<j<<' '<<k<<' '<<diff11<<' '<<diff21<<' '<<diff31<<endl;
                    if(diff11<=2 && diff21<=2 && diff31<=2)
                    {
                        counter++;
                        cout<<ii<<' '<<jj<<' '<<kk<<endl;
                    }
                    else if(diff12<=2 && diff22<=2 && diff32<=2)
                    {
                        counter++;
                        cout<<"counter= "<<counter<<' '<<ii<<' '<<jj<<' '<<kk<<endl;
                    }
                }
            }
        }
        cout<<counter<<endl;
    }

    return 0;
}
