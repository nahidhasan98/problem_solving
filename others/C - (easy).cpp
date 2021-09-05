#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;

    while(cin>>n>>k)
    {
        int total=(n*(n-1))/2;

        if(k>=total)
            cout<<"no solution"<<endl;
        else
        {
            int counter=0,flag=0;
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    cout<<i<<' '<<j<<endl;
                    counter++;

                    if(counter==n)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    break;
            }
        }
    }

    return 0;
}
