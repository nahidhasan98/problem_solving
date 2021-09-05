#include<iostream>
using namespace std;

#define MaxSize 10

int n,arr[MaxSize],low=0,high=-1,counter=0;

struct sstack
{
    void spush()
    {
        if(counter==n)
            cout<<"stack is full."<<endl;
        else
        {
            cout<<"Enter element to insert: "<<endl;

            int num;
            cin>>num;

            high++;
            arr[high]=num;
            counter++;
        }
    }
    void spop()
    {
        if(counter==0)
            cout<<"stack is empty."<<endl;
        else
        {
            high--;
            counter--;
            cout<<"Element Popped up successfully."<<endl;
        }
    }
    int stop()
    {
        return arr[high];
    }
    bool sempty()
    {
        if(counter==0)
            return true;
        else
            return false;
    }
    int ssize()
    {
        return counter;
    }
    void sdisplay()
    {
        if(sempty())
            cout<<"No element in the stack. stack is empty"<<endl;
        else
        {
            cout<<"Current element in the stack (from low to top):"<<endl;

            for(int i=0; i<=high; i++)
                cout<<arr[i];

            cout<<endl;
        }
    }
};

int main()
{
    sstack s;

    cout<<"Enter the maximum size of stack: "<<endl;
    cin>>n;

    while(1)
    {
        cout<<"\n1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Top"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Size"<<endl;
        cout<<"6. Empty\n"<<endl;
        cout<<"Current low= "<<low<<" & high= "<<high<<endl;

        int choice;
        cin>>choice;

        cout<<"---------------------------------------------"<<endl;

        if(choice==1)
            s.spush();
        if(choice==2)
            s.spop();
        if(choice==3)
        {
            if(s.sempty())
                cout<<"No Top element in the stack. stack is empty."<<endl;
            else
                cout<<s.stop()<<endl;
        }
        if(choice==4)
            s.sdisplay();
        if(choice==5)
            cout<<"Size of stack = "<<s.ssize()<<endl;
        if(choice==6)
        {
            if(s.sempty())
                cout<<"stack is empty."<<endl;
            else
                cout<<"stack is not empty."<<endl;
        }
    }
    return 0;
}
