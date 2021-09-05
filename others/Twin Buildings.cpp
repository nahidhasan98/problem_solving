#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

struct st
{
    long long l,w;
};

int main()
{
    int n;

    while(cin>>n)
    {
        st a[n];
        long long l,w;

        for(int i=0; i<n; i++)
        {
            cin>>l>>w;

            a[i].l=max(l,w);
            a[i].w=min(l,w);
        }

        if(n==1)
        {
            double ll=a[0].l;
            ll/=2.0;
            double res=ll*a[0].w;
            printf("%.1lf\n",res);
            continue;
        }

        st m1=a[0],m2=a[1],temp;

        double ml1=a[0].l,mw1=a[0].w;
        double resm1=(ml1*mw1)/2.0;

        double ml2=a[1].l,mw2=a[1].w;
        double resm2=(ml2*mw2)/2.0;
        double resm3=min(ml1,ml2)*min(mw1,mw2);
        double sum=max(resm1,max(resm2,resm3));
        //cout<<"1 "<<resm2<<' '<<resm2<<' '<<resm3<<endl;

        for(int i=2; i<n; i++)
        {
            temp=a[i];

            if(temp.l>ml1 && temp.w>mw1)
            {
                ml1=temp.l;
                mw1=temp.w;
                resm1=(ml1*mw1)/2.0;

                resm3=min(ml1,ml2)*min(mw1,mw2);
                sum=max(resm1,max(resm2,resm3));
                //cout<<"2 "<<resm2<<' '<<resm2<<' '<<resm3<<endl;
            }
            else if(temp.l>ml1 && temp.w>mw2)
            {
                ml2=temp.l;
                mw2=temp.w;
                resm2=(ml2*mw2)/2.0;

                resm3=min(ml1,ml2)*min(mw1,mw2);
                sum=max(resm1,max(resm2,resm3));
                //cout<<"3 "<<resm2<<' '<<resm2<<' '<<resm3<<endl;
            }
            else
            {
                long long tl1=min(ml1,temp.l);
                long long tw1=min(mw1,temp.w);
                long long tres1=tl1*tw1;

                long long tl2=min(ml2,temp.l);
                long long tw2=min(mw2,temp.w);
                long long tres2=tl2*tw2;

                if(tres1>=tres2 && tres1>resm3)
                {
                    m2.l=temp.l;
                    m2.w=temp.w;
                    resm2=(m2.l*m2.w)/2;

                    resm3=min(m1.l,m2.l)*min(m1.w,m2.w);
                    sum=max(resm1,max(resm2,resm3));
                    //cout<<"4 "<<resm2<<' '<<resm2<<' '<<resm3<<endl;
                }
                else if(tres1<tres2  && tres1>resm3)
                {
                    m1.l=temp.l;
                    m1.w=temp.w;
                    resm1=(m1.l*m1.w)/2;

                    resm3=min(m1.l,m2.l)*min(m1.w,m2.w);
                    sum=max(resm1,max(resm2,resm3));
                    //cout<<"5 "<<resm2<<' '<<resm2<<' '<<resm3<<endl;
                }
            }
        }
        cout<<fixed<<setprecision(1)<<sum<<endl;
    }

    return 0;
}
/*
6
1000 1
50 500
600 30
60 700
800 20
500 90
*/
