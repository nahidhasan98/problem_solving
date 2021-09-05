#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

long long need(long long a,long long mod)
{
    long long res=0;

    res=mod/a;

    if(a*res!=mod)
        res++;

    return res;
}

int main()
{
    int n;
    long long a,b,k;

    while(cin>>n>>a>>b>>k)
    {
        long long hp,counter=0,mod,total=a+b,temp;
        vector<long long>v;

        for(int i=0; i<n; i++)
        {
            cin>>hp;

            mod=hp%total;

            if(mod==0)
            {
                temp=need(a,total-a);
                v.push_back(temp);
                //cout<<"temp="<<temp<<endl;
            }
            else if(mod!=0)
            {
                if(a>=mod)
                {
                    counter++;
                    //cout<<"hp="<<hp<<endl;
                }
                else if(a<mod)
                {
                    temp=need(a,mod-a);
                    v.push_back(temp);
                    //cout<<"temp="<<temp<<endl;
                }
            }
        }
        sort(v.begin(),v.end());

        //cout<<"pre="<<counter<<endl;
        for(int i=0;i<v.size();i++)
        {
            //cout<<"v="<<v[i]<<endl;
            if(v[i]<=k)
            {
                counter++;
                k-=v[i];
                //cout<<"k="<<counter<<endl;
            }
            else
                break;
        }
        cout<<counter<<endl;
    }

    return 0;
}
