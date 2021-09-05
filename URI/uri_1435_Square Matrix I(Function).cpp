#include<bits/stdc++.h>
using namespace std;

int arr[110][110];
void process(int start,int end,int d)
{
    for(int p=start;p<=end;p++)
    {
        for(int q=start;q<=end;q++)
            arr[p][q]=d;
    }
}

int main()
{
    int n;

    while(cin>>n)
    {
        memset(arr,0,sizeof(arr));

        if(n==0)
            return 0;
        else
        {
            for(int i=0;i<=(n/2);i++)
                process(i,(n-1)-i,i+1);

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(j!=n-1)
                        cout<<setw(3)<<arr[i][j]<<' ';
                    else
                        cout<<setw(3)<<arr[i][j];
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }

    return 0;
}
