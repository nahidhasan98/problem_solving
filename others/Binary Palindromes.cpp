#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;

    for(int t=1; t<=q; t++)
    {
        int n;
        cin>>n;

        string a[n];
        vector<int>ve,vo;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];

            if(a[i].size()%2==0)
                ve.push_back(a[i].size());
            else
                vo.push_back(a[i].size());
        }
        sort(ve.begin(),ve.end());
        sort(vo.begin(),vo.end());

        int one=0,zero=0,counter=0,ind=0,temp;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<a[i].size(); j++)
            {
                if(a[i][j]=='1')
                    one++;
                else
                    zero++;
            }
        }
        for(int i=0; i<ve.size(); i++)
        {
            if(one%2==0 && ve[i]<=one)
            {
                one-=v[i];
                counter++;
                ind=i;
            }
            else if(zero%2==0 && ve[i]<=zero)
            {
                zero-=v[i];
                counter++;
                ind=i;
            }
            else if(one%2!=0)
            {
                if(one%2!=0 && v[i]<=one)
                {
                    one-=v[i];
                    counter++;
                    ind=i;
                }
                else if(zero%2!=0 && v[i]<=zero)
                {
                    zero-=v[i];
                    counter++;
                    ind=i;
                }
                else if(v[i]<=one)
                {
                    one-=v[i];
                    counter++;
                    ind=i;
                }
                else if(v[i]<=zero)
                {
                    zero-=v[i];
                    counter++;
                    ind=i;
                }
            }
        }
        for(int i=ind+1; i<v.size(); i++)
        {
            if(v[i]%2==0)
            {
                if(one%2==0 && zero%2==0)
                    counter++;
            }
            else if(v[i]%2!=0)
            {
                counter++;
            }
        }
        cout<<counter<<endl;
    }

    return 0;
}
