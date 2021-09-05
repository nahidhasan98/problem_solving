#include<iostream>
using namespace std;

#define MaxSize 10

int n,arr[MaxSize],low=0,high=-1,counter=0;

struct qqueue
{
    void qpush()
    {
        if(counter==n)
            cout<<"Queue is full."<<endl;
        else
        {
            cout<<"Enter element to insert: "<<endl;

            int num;
            cin>>num;

            high++;
            high%=MaxSize;

            arr[high]=num;
            counter++;
        }
    }
    void qpop()
    {
        if(counter==0)
            cout<<"Queue is empty."<<endl;
        else
        {
            low++;
            low%=MaxSize;
            counter--;
            cout<<"Element Popped up successfully."<<endl;
        }
    }
    int qfront()
    {
        return arr[low];
    }
    int qback()
    {
        return arr[high];
    }
    bool qempty()
    {
        if(counter==0)
            return true;
        else
            return false;
    }
    int qsize()
    {
        return counter;
    }
    void qdisplay()
    {
        if(qempty())
            cout<<"No element in the queue. Queue is empty"<<endl;
        else
        {
            cout<<"Current element in the queue:"<<endl;

            int ind=low;
            for(int i=1; i<=counter; i++)
            {
                cout<<arr[ind]<<' ';

                ind++;
                ind%=MaxSize;
            }
            cout<<endl;
        }
    }
};

int main()
{
    qqueue q;

    cout<<"Enter the maximum size of queue: "<<endl;
    cin>>n;

    while(1)
    {
        cout<<"\n1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Front"<<endl;
        cout<<"4. Back"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Size"<<endl;
        cout<<"7. Empty\n"<<endl;
        cout<<"Current low= "<<low<<" & high= "<<high<<endl;

        int choice;
        cin>>choice;

        cout<<"---------------------------------------------"<<endl;

        if(choice==1)
            q.qpush();
        if(choice==2)
            q.qpop();
        if(choice==3)
        {
            if(q.qempty())
                cout<<"No front element in the queue. Queue is empty."<<endl;
            else
                cout<<q.qfront()<<endl;
        }
        if(choice==4)
        {
            if(q.qempty())
                cout<<"No back element in the queue. Queue is empty."<<endl;
            else
                cout<<q.qback()<<endl;
        }
        if(choice==5)
            q.qdisplay();
        if(choice==6)
            cout<<"Size of queue = "<<q.qsize()<<endl;
        if(choice==7)
        {
            if(q.qempty())
                cout<<"Queue is empty."<<endl;
            else
                cout<<"Queue is not empty."<<endl;
        }
    }
    return 0;
}
