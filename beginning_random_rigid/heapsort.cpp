#include <bits/stdc++.h>
using namespace std;

void heapSort(int arr[],int n);
void heapify(int arr[],int n,int parent);

int main()
{
    int arr[1000],n,i;

    cout<<"First enter the number of elements: ";
    cin>>n;
    cout<<"\nNow enter "<<n<<" elements one by one:"<<endl;

    for(i=0;i<n;i++)
        cin>>arr[i];

    heapSort(arr,n);

    cout<<"\nSorted array is:"<<endl;
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void heapSort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);

    for (int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);

        heapify(arr,i,0);
    }
}
void heapify(int arr[],int n,int parent)
{
    int largest=parent;
    int left=2*parent+1;
    int right=2*parent+2;

    if (left<n && arr[left]>arr[largest])
        largest=left;

    if (right<n && arr[right]>arr[largest])
        largest=right;

    if (largest!=parent)
    {
        swap(arr[parent],arr[largest]);

        heapify(arr,n,largest);
    }
}
