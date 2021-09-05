#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,m,a[22];

    while(cin>>n>>k>>m)
    {
        int x=1,y=n,count=0;
        memset(a,0,22);

        if(n==0 && k==0 && m==0)
            return 0;
        else
        {
            for(int i=1;i<=n;i++)
                a[i]=i;

            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<k;j++)
                {
                    if(a[x]!=0)
                    {
                        x++;

                        if(x==n+1)
                            x=1;
                    }
                    else
                    {
                        x++;
                        j--;

                        if(x==n+1)
                            x=1;
                    }
                }
                while(a[x]==0)
                {
                    x++;

                    if(x==n+1)
                        x=1;
                }

                if(a[x]>9)
                    cout<<" "<<a[x];
                else
                    cout<<"  "<<a[x];

                count++;

                if(count==n)
                    break;

                for(int j=1;j<m;j++)
                {
                    if(a[y]!=0)
                    {
                        y--;

                        if(y==0)
                            y=n;
                    }
                    else
                    {
                        y--;
                        j--;

                        if(y==0)
                            y=n;
                    }
                }
                while(a[y]==0)
                {
                    y--;

                    if(y==0)
                        y=n;
                }
                if((a[y]==a[x]) && (count<n))
                    cout<<",";

                else if(count==n-1)
                {
                    if(a[y]>9)
                        cout<<" "<<a[y];
                    else
                        cout<<"  "<<a[y];

                    count++;
                }
                else
                {
                    if(a[y]>9)
                        cout<<" "<<a[y]<<",";
                    else
                        cout<<"  "<<a[y]<<",";

                    count++;
                }

                a[y]=0;
                y--;

                if(y==0)
                    y=n;

                a[x]=0;
                x++;

                if(x==n+1)
                    x=1;

                if(count==n)
                    break;
            }
        }
        cout<<endl;
    }

    return 0;
}

