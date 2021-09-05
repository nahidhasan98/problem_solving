#include<iostream>
#include<stdio.h>
using namespace std;

int a[8],mark[8][8];

void markFunc(int row,int col,int markSymbol){
    //cout<<"row="<<row<<" col="<<col<<endl;

    //self-cell marking
    mark[row][col]+=markSymbol;

    //col marking
    for(int i=0; i<8; i++)
        if(i!=col) mark[row][i]+=markSymbol;

    //row marking
    for(int i=0; i<8; i++)
        if(i!=row) mark[i][col]+=markSymbol;

    int i=0,j=0;

    //upper-left marking
    for((i=row-1,j=col-1); (i>=0 && j>=0); (i--,j--)){
        mark[i][j]+=markSymbol;
    }

    //lower-right marking
    for((i=row+1,j=col+1); (i<8 && j<8); (i++,j++)){
        mark[i][j]+=markSymbol;
    }
    //upper-right marking
    for((i=row-1,j=col+1); (i>=0 && j<8); (i--,j++)){
        mark[i][j]+=markSymbol;
    }
    //lower-left marking
    for((i=row+1,j=col-1); (i<8 && j>=0); (i++,j--)){
        mark[i][j]+=markSymbol;
    }

    //printf("1\n");
}

int solve(int col){
    if(col==8) return 0;

    int x,res=100;

    for(int i=0; i<8; i++){
        if(mark[i][col]==0){
            markFunc(i,col,1);

            if(i==a[col]) x=solve(col+1);
            else x=1+solve(col+1);

            markFunc(i,col,-1);
        }
        res=min(res,x);
    }
    return res;
}

int main()
{
    int test=0,d;

    while(cin>>d){
        test++;

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++)
                mark[i][j]=0;
        }

        a[0]=d-1;

        for(int i=1; i<8; i++){
            cin>>d;
            a[i]=d-1;
        }

        cout<<"Case "<<test<<": "<<solve(0)<<endl;
    }

    return 0;
}
