#include <bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);

vector<string> split_string(string);

// Complete the designerPdfViewer function below.
int designerPdfViewer(vector<int> h, string word)
{
    int high = 0;

    for(int i=0; i<word.size(); i++)
        high=max(high,h[word[i]-97]);

    return high*word.size();
}

int main()
{
    FI

    vector<int>v;
    int num;

    for(int i=0; i<26; i++)
    {
        cin>>num;
        v.push_back(num);
    }
    string s;
    cin>>s;

    cout<<designerPdfViewer(v,s)<<endl;

    return 0;
}
