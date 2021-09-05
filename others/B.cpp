#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    while(cin>>s)
    {
        long long counter=0,mod=1e9+7;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='a')
                counter++;
        }

        stack<char>st;
        int flag=0;

        for(int i=0; i<s.size(); i++)
        {
            if(st.empty())
            {
                if(s[i]=='a')
                    st.push('a');
            }
            else if(!st.empty())
            {
                if(s[i]=='a')
                {
                    char temp=st.top();

                    if(temp=='b')
                    {
                        st.pop();
                        counter++;
                        flag=1;

                        counter%=mod;
                    }
                }
                else if(s[i]=='b')
                {
                    char temp=st.top();

                    if(temp=='a')
                    {
                        st.push('b');
                    }
                }
                else
                {
                    while(!st.empty())
                        st.pop();
                }
            }
        }
        cout<<counter%mod<<endl;
    }

    return 0;
}
