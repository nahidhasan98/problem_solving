#include<bits/stdc++.h>
using namespace std;

int r,c;

bool valid(int row,int col)
{
    if(row>=0 && row<r && col>=0 && col<c)
        return true;
    else
        return false;
}

int main()
{
    while(cin>>r>>c)
    {
        string s[r];

        for(int i=0;i<r;i++)
            cin>>s[i];

        int x[8]={-1,-1,-1,0,0,+1,+1,+1};
        int y[8]={-1,0,+1,-1,+1,-1,0,+1};

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int counter=0;

                if(s[i][j]=='.')
                {
                    for(int k=0;k<8;k++)
                    {
                        int row=i+x[k],col=j+y[k];

                        if(valid(row,col) && s[row][col]=='*')
                            counter++;
                    }
                }
                if(counter>0)
                    s[i][j]=counter+48;
            }
        }
        for(int i=0;i<r;i++)
            cout<<s[i]<<endl;
    }

    return 0;
}
