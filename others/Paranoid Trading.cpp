#include<bits/stdc++.h>
using namespace std;

int n,a[1010];
int memory[1010][2010][2];

int solve(int pos,int last_profit,int bag,int last_buy)
{
    if(pos>=n)
        return 0;

    if(memory[pos][last_profit][bag]!=-1)
    {
        //cout<<pos<<' '<<last_profit<<' '<<bag<<' '<<last_buy<<' '<<memory[pos][last_profit][bag]<<endl;
        return memory[pos][last_profit][bag];
    }

    int res1=0,res2=0,res3=0,res4=0;

    if(bag)
    {
        int profit=a[pos]-a[last_buy];

        if(profit>=last_profit)
        {
            cout<<"Profit "<<profit<<endl;
            res1=profit+solve(pos+1,profit,0,last_buy);
            cout<<"Selling at "<<pos<<' '<<last_buy<<endl;
        }
        res2=solve(pos+1,last_profit,1,last_buy);
    }
    else
    {
        res3=solve(pos+1,last_profit,1,pos);
        cout<<"buying from "<<pos<<endl;
        res4=solve(pos+1,last_profit,0,last_buy);
    }
    cout<<"memory "<<pos<<' '<<last_profit<<' '<<bag<<'='<<max(max(res1,res2),max(res3,res4))<<endl;
    return memory[pos][last_profit][bag]=max(max(res1,res2),max(res3,res4));
}

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        memset(memory,-1,sizeof(memory));

        cin>>n;

        for(int i=0;i<n;i++)
            cin>>a[i];

        cout<<solve(0,0,0,0)<<endl;
    }

    return 0;
}
