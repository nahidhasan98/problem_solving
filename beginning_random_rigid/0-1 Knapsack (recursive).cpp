#include<bits/stdc++.h>
using namespace std;

int max(int a, int b);
void knapSack(int capacity,int wt[],int val[],int n);

int main()
{
    int n,val[1000],wt[1000],capacity;

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

    cout<<"\nMaximum value/benefit is: ";
    knapSack(capacity,wt,val,n);

    return 0;
}
void knapSack(int capacity,int wt[],int val[],int n)
{
    int i,j,arr[1000][1000];

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
    cout<<i<<' '<<j<<endl;
    cout<< arr[n][capacity];
}
int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
