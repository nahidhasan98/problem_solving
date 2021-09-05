#include<iostream>
#include<vector>
using namespace std;

int main()
{
    string s;
    vector<string>line;

    while(cin>>s)
    {
        if (s.size()>8)
            s = "#bigword";

        line.push_back(s);
    }
//        cout<<line.size()<<endl;
//        for (int i=0;i<line.size();i++){
//            cout<<line[i]<<' ';
//        }
//        cout<<endl;

    cout<<line[0];
    int last = line[0].size();

    for (int i = 1; i < line.size(); i++)
    {
        if (last + 1 + line[i].size() <= 8)
        {
            cout<<' '<<line[i];
            last += 1 + line[i].size();
        }
        else
        {
            cout<<'\n'<<line[i];
            last = line[i].size();
        }
    }
    return 0;
}