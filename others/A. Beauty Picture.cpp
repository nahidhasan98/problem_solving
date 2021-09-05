#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int counter[1010];

int getCount(int first, int second)
{
    cout<<first<<' '<<second<<endl;
    int res=0;

    //for(int i=first; i<v.size(); i++)
    {
        if(counter[first]==counter[second])
        {
            cout<<"Counter="<<counter[first]<<' '<<counter[second]<<endl;
            res+=counter[first];
            counter[first]=0;
            counter[second]=1;

            cout<<"In="<<res<<endl;
        }
        else if(counter[first]<counter[second])
        {
            res+=counter[first];

            counter[second]-=counter[first];
            counter[second]++;

            counter[first]=0;
        }
        else if(counter[first]>counter[second])
        {
            res+=counter[second];

            counter[first]-=counter[second];
            counter[second]=0;
        }
    }
    cout<<res<<endl;
    return res;
}

int main()
{
    int n;
    cin>>n;

    vector<int>v;
    int d,res=0;

    for(int i=0; i<n; i++)
    {
        cin>>d;

        if(counter[d]==0)
        {
            counter[d]++;
            v.push_back(d);
        }
        else
        {
            counter[d]++;
        }
    }

    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++)
        cout<<"vc="<<v[i]<<' '<<counter[v[i]]<<endl;

    int loop=v.size();

    while(loop>1)
    {
        int first,second,ind;

        for(int i=0; i<v.size(); i++)
        {
            if(counter[v[i]]>0)
            {
                first=v[i];
                ind=i;
                cout<<"F="<<first<<endl;
                break;
            }
        }
        for(int i=ind+1; i<v.size(); i++)
        {
            if(counter[v[i]]>0)
            {
                second=v[i];
                cout<<"S="<<second<<endl;
                break;
            }
        }

        cout<<"CCounter="<<counter[first]<<' '<<counter[second]<<endl;
        res+=getCount(first,second);
        loop--;
    }

    cout<<res<<endl;

    return 0;
}
