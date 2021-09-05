#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int n;
    cin>>n;

    cin.ignore();

    for(int t=1;t<=n;t++)
    {
        string s;
        getline(cin,s);

        if(s.size()<5)
            cout<<"OMG>.< I don't know!"<<endl;
        else
        {
            string left=s.substr(0,5);
            string right=s.substr(s.size()-5);

            if(left=="miao." && right=="lala.")
                cout<<"OMG>.< I don't know!"<<endl;
            else if(left=="miao.")
                cout<<"Rainbow's"<<endl;
            else if(right=="lala.")
                cout<<"Freda's"<<endl;
            else
                cout<<"OMG>.< I don't know!"<<endl;
        }
    }

    return 0;
}
