#include<bits/stdc++.h>
using namespace std;

int knapSack(int capacity,int wt[],int val[],int n);

int main()
{
    int n,val[100],wt[100],capacity;

    cout<<"First enter the number of item: ";
    cin>>n;

    cout<<"\nNow enter "<<n<<" items weight one by one:\n";
    for(int i=0;i<n;i++)
        cin>>wt[i];

    cout<<"\nNow enter values/benefits one by one:\n";
    for(int i=0;i<n;i++)
        cin>>val[i];

    cout<<"\nNow enter the maximum capacity: ";
    cin>>capacity;

    knapSack(capacity,wt,val,n);

    return 0;
}
int knapSack(int capacity,int wt[],int val[],int n)
{
    int i,j,arr[100][100];

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=capacity;j++)
        {
            if(i==0 || j==0)
                arr[i][j]=0;

            else if(wt[i-1]<=j)
                arr[i][j]=max(val[i-1]+arr[i-1][j-wt[i-1]],arr[i-1][j]);
            else
                arr[i][j]=arr[i-1][j];
        }
    }
    cout<<"\nMaximum value/benefit is: ";
    cout<<arr[n][capacity]<<endl;

    int item[100],index=0;

    int a=n,b=capacity;

    while(a>0 && b>0)
    {
        if(arr[a][b]!=arr[a-1][b])
        {
            item[index]=wt[a-1];
            b=b-wt[a-1];
            a--;
            index++;
        }
        else
            a--;
    }
    cout<<"\nSelected items are:\n";
    for(i=0;i<index;i++)
        cout<<item[i]<<",";
    cout<<"\b whose total values/benefits is "<<arr[n][capacity]<<endl;
}
