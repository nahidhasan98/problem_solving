#include<bits/stdc++.h>
using namespace std;

struct student
{
    int roll,marks;
    string name;
};

bool operator < (student a,student b)
{
    if(a.marks!=b.marks)
        return a.marks>b.marks;
    else
        return a.roll<b.roll;
}

int main()
{
    int n;

    while(cin>>n)
    {
        student a[n];

        for(int i=0;i<n;i++)
            cin>>a[i].roll>>a[i].name>>a[i].marks;

        sort(a,a+n);

        cout<<"Roll | Name       | Marks"<<endl;
        cout<<"-------------------------"<<endl;

        for(int i=0;i<n;i++)
        {
            cout.width(4); cout<<right<<a[i].roll<<" | ";
            cout.width(10); cout<<left<<a[i].name<<" | ";
            cout<<a[i].marks<<endl;
        }
    }

    return 0;
}
