#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

double n,d;

int getRes(int day)
{
//    cout<<"-------------"<<endl;
//    cout<<"Day="<<day<<endl;
//    cout<<day+ceil(d/(day+1))<<endl;
    return day+ceil(d/(day+1));
}

int ternary()
{
    int low=1,high=n,range,mid1,mid2,res1,res2,res=1e9+7;

    while(low<=high)
    {
        range=high-low+1;

        mid1=low+(range/3),mid2=high-(range/3);

        //cout<<"low="<<low<<" high="<<high<<" mid1="<<mid1<<" mid2="<<mid2<<endl;

        res1=getRes(mid1);
        res2=getRes(mid2);

        //cout<<"res1="<<res1<<" res2="<<res2<<endl;

        if(res1==res2)
        {
            res=min(res,res1);

            high=mid2-1;
        }
        else if(res1<res2)
        {
            res=min(res,res1);
            high=mid2-1;
        }
        else if(res1>res2)
        {
            res=min(res,res2);
            low=mid1+1;
            //cout<<"l="<<low<<endl;
        }
        //cout<<"before end="<<low<<endl;
    }

    //cout<<"Not found"<<endl;
    return res;
}

int main()
{
    FI FO

    int t;
    cin>>t;

    for(int T=1; T<=t; T++)
    {
        cin>>n>>d;

        if(d<=n)
            cout<<"YES"<<endl;

        else
        {
            if(ternary()<=n)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }

    return 0;
}
