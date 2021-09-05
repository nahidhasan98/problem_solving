#include<iostream>
using namespace std;

int arr[30];
void mergesort(int left,int right);
void merge(int left, int mid, int right);

int main()
{
    int n,i;

    cout<<"Enter the number of elements in the array:\t";
    cin>>n;

    cout<<"\nNow enter "<<n<<" elements one by one:\n";
    for(i=0;i<n;i++)
        cin>>arr[i];

    cout<<"\nYour entered array is:\n";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    mergesort(0,n-1);

    cout<<"\nAfter merged the sorted array is:\n";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
void mergesort(int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;

        mergesort(left,mid);
        mergesort(mid+1,right);

        merge(left,mid,right);
    }
}
void merge(int left,int mid,int right)
{
    int h,i,j,temp[30],k;
    h=left;
    i=left;
    j=mid+1;

    while((h<=mid)&&(j<=right))
    {
        if(arr[h]<=arr[j])
        {
            temp[i]=arr[h];
            h++;
        }
        else
        {
            temp[i]=arr[j];
            j++;
        }
        i++;
    }

    if(h>mid)
    {
        for(k=j;k<=right;k++)
        {
            temp[i]=arr[k];
            i++;
        }
    }
    else
    {
        for(k=h;k<=mid;k++)
        {
            temp[i]=arr[k];
            i++;
        }
    }
    for(k=left;k<=right;k++)
        arr[k]=temp[k];
}
