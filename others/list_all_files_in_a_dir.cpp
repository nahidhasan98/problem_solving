#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <dirent.h>
#include <fstream>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

typedef vector<string> stringvec;

void read_directory(const string& name, stringvec& v)
{
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL)
    {
        v.push_back(dp->d_name);
    }
    closedir(dirp);
}
int main()
{
    stringvec v;
    read_directory("./New folder", v);
    //copy(v.begin(), v.end(),ostream_iterator<string>(cout, "\n"));

    for(int i=0; i<v.size(); i++)
    {
        string fileName=v[i];

        cout<<fileName<<endl;
    }
}
