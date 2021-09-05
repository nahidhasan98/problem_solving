#include<bits/stdc++.h>
using namespace std;

struct st
{
    int pos,val;
};

bool operator < (st a,st b)
{
    if(a.val!=b.val)
        return a.val<b.val;
    else
        return a.pos>b.pos;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int p,n,d;
        cin>>p>>n;

        st a[n],temp;
        int total=0;

        for(int i=0; i<n; i++)
        {
            cin>>d;

            temp.pos=i;
            temp.val=d;

            a[i]=temp;

            total+=d;
        }
        if(total<p)
            cout<<"IMPOSSIBLE"<<endl;
        else
        {
            sort(a,a+n);
            int rest,avg,need;
            int res[n];

            for(int i=0; i<n; i++)
            {
                rest=n-i;
                avg=p/rest;

                if(a[i].val<=avg)
                {
                    p-=a[i].val;
                    res[a[i].pos]=a[i].val;
                }
                else
                {
                    p-=avg;
                    res[a[i].pos]=avg;
                }
            }
            for(int i=0;i<n;i++)
            {
                cout<<res[i];

                if(i<n-1)
                    cout<<' ';
            }
            cout<<endl;
        }
    }

    return 0;
}
