#include<iostream>
#include<stdio.h>
#include<vector>
#include<list>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

list<int>lst;
struct command
{
    string type;
    int value;
};

void findAndDelete(int need)
{
    list<int>::iterator it;

    for(it=lst.begin(); it!=lst.end(); it++)
    {
        if(need==*it)
        {
            lst.erase(it);
            break;
        }
    }
}

int main()
{
    int p,c,tc=0;

    while(cin>>p>>c)
    {
        if(p==0 && c==0)
            return 0;

        lst.clear();

        vector<command>v;
        command temp;
        string s;
        int d=0;

        for(int i=0; i<c; i++)
        {
            cin>>s;

            if(s=="E")
                cin>>d;

            temp.type=s;
            temp.value=d;

            v.push_back(temp);
        }

        for(int i=1; i<=min(p,1000); i++)
            lst.push_back(i);

        cout<<"Case "<<++tc<<":"<<endl;
        for(int i=0; i<c; i++)
        {
            if(v[i].type=="N")
            {
                cout<<lst.front()<<endl;
                lst.push_back(lst.front());
                lst.pop_front();
            }
            else if(v[i].type=="E")
            {
                findAndDelete(v[i].value);
                lst.push_front(v[i].value);
            }

//            cout<<"List="<<endl;
//            list<int>::iterator it;
//            for(it=lst.begin(); it!=lst.end(); it++)
//                cout<<*it<<endl;
//            cout<<endl;
        }
    }

    return 0;
}
