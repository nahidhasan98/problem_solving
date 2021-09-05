#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, s[20][20],k,j,y=1;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int count=0;

        for(j=0;j<20;j++)
        {
            cin>>s[j][0]>>s[j][1];

            if(s[j][0]==0 && s[j][1]==0)
                break;
        }
        cout<<endl;

        for(int p=0;p<j-1;p++)
        {
            for(int x=0;x<j-1;x++)
            {
                if(s[x][0]>s[x+1][0])
                {
                    swap(s[x][0],s[x+1][0]);
                    swap(s[x][1],s[x+1][1]);
                }
            }
        }

        for(int x=0,y=1;y<j;x++,y++)
        {
            if(s[x][1]<=s[y][0])
                count++;
            else
                x--;
        }

        cout<<endl;
        for(int x=0;x<j;x++)
        {
            cout<<s[x][0]<<' '<<s[x][1];

            cout<<endl;
        }

        cout<<endl<<count+1<<endl;
    }

    return 0;
}
