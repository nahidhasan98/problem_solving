#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    while(cin>>s)
    {
        int sz=s.size();

        int arr[sz+5];
        memset(arr,0,sizeof(arr));

        int z[sz];
        z[0]=0;

        int l=1,r=1;

        for(int i=1;i<sz;i++)
        {
            if(i>=r)
            {
                l=i;
                r=i;
                int temp=i,sum=0;

                for(int j=0;j<sz;j++)
                {
                    if(s[j]==s[temp])
                    {
                        sum++;
                        temp++;
                    }
                    else
                        break;
                }
                z[i]=sum;
                arr[z[i]]++;
            }
            else
            {
                z[i]=min(z[i-l],r-i);

                if(z[i]>r-i)
                {
                    int temp=r-i,sum=0,j;

                    for(j=r;j<sz;j++)
                    {
                        if(s[temp]==s[j])
                        {
                            sum++;
                            temp++;
                        }
                        else
                            break;
                    }
                    z[i]=z[i]+sum;
                    r=j;
                    l=i;
                }
                arr[z[i]]++;
            }
        }
        int fix=-1,k=1;
        for(int i=sz-1;i>=1;i--)
        {
            if(sz-i==z[i])
            {
                if(arr[z[i]]>=2)
                {
                    fix=i;
                }
            }
        }
        if(fix==-1)
            cout<<"Just a legend"<<endl;
        else
        {
            string res=s.substr(fix);
            cout<<res<<endl;
        }
    }

    return 0;
}
