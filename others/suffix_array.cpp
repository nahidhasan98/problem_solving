#include<bits/stdc++.h>
using namespace std;

struct letter
{
    int index,f,s;
};
bool operator < (letter a,letter b)
{
    if(a.f!=b.f)
        return a.f<b.f;
    else
        return a.s<b.s;
}

int main()
{
    string s;

    while(cin>>s)
    {
        int sz=s.size();

        letter a[sz];

        for(int i=0;i<sz;i++)
        {
            a[i].index=i;
            a[i].f=s[i]-96;
            a[i].s=-1;
        }

        int sum=1,limit=0;
        while(limit<sz)
        {
            sum=sum*2;
            limit++;
        }

        for(int k=0;k<=limit;k++)
        {
            sort(a,a+sz);

            int identity[sz];
            memset(identity,0,sizeof(identity));

            for(int i=0;i<sz;i++)
            {
                identity[a[i].index]=i;
            }

            letter temp[sz];
            for(int i=0;i<sz;i++)
            {
                temp[i].f=a[i].f;
                temp[i].s=a[i].s;
            }

            int numbering=1;
            a[0].f=numbering;

            for(int i=1;i<sz;i++)
            {
                if(temp[i].f==temp[i-1].f && temp[i].s==temp[i-1].s)
                {
                    a[i].f=numbering;
                }
                else
                {
                    numbering++;
                    a[i].f=numbering;
                }
            }
            for(int i=0;i<sz;i++)
            {
                int next_index=(a[i].index+pow(2,k));

                if(next_index<sz)
                    a[i].s=a[identity[next_index]].f;
                else
                    a[i].s=-1;
            }
        }
        for(int i=0;i<sz;i++)
        {
            cout<<a[i].index<<endl;
        }
        cout<<endl;
    }

    return 0;
}
