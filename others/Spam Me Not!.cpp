#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

struct com
{
    string type;
    int user;
    string notification;
};

map<int,map<string,bool>>userData;

int getLastDot(string notification)
{
    for(int i=notification.size()-1; i>=0; i--)
    {
        if(notification[i]=='.')
            return i;
    }
    return -1;
}

void setNotification(int user,string notification,bool type)
{
    notification+=".";

    int idx=1;
    while(idx>=0)
    {
        idx=getLastDot(notification);
        notification=notification.substr(0,idx);

        userData[user][notification]=type;
    }
}

void print(int user,string notification)
{
    notification+=".";
    string result="Yes";

    int idx=1;
    while(idx>=0)
    {
        idx=getLastDot(notification);
        notification=notification.substr(0,idx);

        if(!userData[user][notification])
        {
            result="No";
            break;
        }
    }

    cout<<result<<endl;
}

int main()
{
    int n;
    cin>>n;

    com command;

    for(int i=0; i<n; i++)
    {
        cin>>command.type>>command.user>>command.notification;

        if(command.type=="+")
            setNotification(command.user,command.notification,true);
        else if (command.type=="-")
            setNotification(command.user,command.notification,false);
        else
            print(command.user,command.notification);
    }

    return 0;
}
