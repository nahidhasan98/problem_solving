#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int minimumNumber(int n, string password)
{
    // Return the minimum number of characters to make the password strong
    string temp="!@#$%^&*()-+";

    map<char,bool>special;
    for(int i=0; i<temp.size(); i++)
        special[temp[i]]=true;

    bool hasNumbers=false,hasLower_case=false,hasUpper_case=false,hasSpecial_characters=false;

    for(int i=0; i<password.size(); i++)
    {
        if(password[i]>='0' && password[i]<='9')
            hasNumbers=true;
        else if(password[i]>='a' && password[i]<='z')
            hasLower_case=true;
        else if(password[i]>='A' && password[i]<='Z')
            hasUpper_case=true;
        else if(special[password[i]])
            hasSpecial_characters=true;
    }

    int result=0,passLength=0;
    if(!hasNumbers)
        result++;
    if(!hasLower_case)
        result++;
    if(!hasUpper_case)
        result++;
    if(!hasSpecial_characters)
        result++;

    if((password.size()+result)<6)
        result+=6-(password.size()+result);

    return result;
}
int main()
{
    FI

    int n;
    string s;

    cin>>n>>s;
    cout<<minimumNumber(n,s)<<endl;

    return 0;
}
