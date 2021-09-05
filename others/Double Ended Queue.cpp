#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int n,m;
        cin>>n>>m;

        string s="";
        int x;
        stack<int>right,left;

        cout<<"Case "<<t<<":"<<endl;

        for(int i=1;i<=m;i++)
        {
            int sz=left.size()+right.size();

            cin>>s;

            if(s[1]=='u')
            {
                cin>>x;

                if(sz==n)
                    cout<<"The queue is full"<<endl;
                else
                {
                    if(s[4]=='L')
                    {
                        cout<<"Pushed in left: "<<x<<endl;
                        left.push(x);
                    }
                    else if(s[4]=='R')
                    {
                        cout<<"Pushed in right: "<<x<<endl;
                        right.push(x);
                    }
                }
            }
            else
            {
                if(sz==0)
                    cout<<"The queue is empty"<<endl;
                else
                {
                    if(s[3]=='L')
                    {
                        cout<<"Popped from left: ";

                        if(left.size()==0)
                        {
                            stack<int>temp;

                            while(right.size()!=1)
                            {
                                temp.push(right.top());
                                right.pop();
                            }
                            cout<<right.top()<<endl;
                            right.pop();

                            while(!temp.empty())
                            {
                                right.push(temp.top());
                                temp.pop();
                            }
                        }
                        else
                        {
                            cout<<left.top()<<endl;
                            left.pop();
                        }
                    }
                    else if(s[3]=='R')
                    {
                        cout<<"Popped from right: ";

                        if(right.size()==0)
                        {
                            stack<int>temp;

                            while(left.size()!=1)
                            {
                                temp.push(left.top());
                                left.pop();
                            }
                            cout<<left.top()<<endl;
                            left.pop();

                            while(!temp.empty())
                            {
                                left.push(temp.top());
                                temp.pop();
                            }
                        }
                        else
                        {
                            cout<<right.top()<<endl;
                            right.pop();
                        }
                    }
                }
            }
        }
    }

    return 0;
}
