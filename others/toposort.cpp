#include<bits/stdc++.h>
using namespace std;

int count(int arr[100][100],int n);
int indeg[100],topo[100];

int main()
{
    int arr[100][100],i,j,n=6,k=0,flag,flag2;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>arr[i][j];
    }

    count(arr,n);

    cout<<endl<<"Indegrees of these nodes are:\n";
    for(i=0;i<n;i++)
        cout<<indeg[i]<<" ";

    for(i=0;i<n;i++)
        topo[i]=999;

    for(int d=0;d<n;d++)
    {
        for(i=0;i<n;i++)
        {
            flag2=1;
            flag=0;

            if(indeg[i]==0)
            {
                flag=1;

                for(int f=0;f<n;f++)
                {
                    if(i==topo[f])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==1)
                {
                    flag2=0;

                    for(j=0;j<n;j++)
                    {
                        if(arr[i][j]==1)
                            arr[i][j]--;
                    }

                    topo[k]=i;
                    k++;

                    count(arr,n);

                    break;
                }

            }
        }
        if(flag2==1 && flag==0)
            break;
    }

    cout<<endl;

    if(flag2==1)
        cout<<endl<<"There exists a cycle. So topological sorting is not possible."<<endl;
    else
    {
        cout<<endl<<"After Topological sorting:\n";
        for(i=0;i<n;i++)
            cout<<topo[i]<<" ";
        cout<<endl;
    }

    return 0;
}
int count(int arr[100][100],int n)
{
    int x,y;

    for(x=0;x<n;x++)
    {
        int count=0;

        for(y=0;y<n;y++)
        {
            if(arr[y][x]==1)
                count++;
        }
        indeg[x]=count;
    }
}

/* inputs are:
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 1 1 1
0 0 0 0 1 1
0 0 0 0 0 0
0 0 0 0 1 0
*/
