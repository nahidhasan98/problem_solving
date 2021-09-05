#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        int a[n],b[n],flag=1;

        for(int i=0;i<n;i++)
        {
            cin>>a[i];

            if(a[i]%2==0)
                b[i]=a[i]/2;
            else
            {
                if(flag==1)
                {
                    if(a[i]>0)
                        b[i]=a[i]/2;
                    else
                        b[i]=(a[i]/2)-1;

                    flag=2;
                }
                else if(flag==2)
                {
                    if(a[i]>0)
                        b[i]=(a[i]/2)+1;
                    else
                        b[i]=a[i]/2;

                    flag=1;
                }
            }
        }
        for(int i=0;i<n;i++)
            cout<<b[i]<<endl;
    }

    return 0;
}
