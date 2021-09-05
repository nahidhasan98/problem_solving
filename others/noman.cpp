#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

//declaring global variable
int x,n,arr[1010],memory[1010][1010];

//function that will do the main process
int solve(int index,int remainder)
{
    //base case/out of range/no element left in vector
    if(index>=n)
        return 0;

    //got a result
    if(remainder==0)
        return 1;

    //if current DP state calculated before
    if(memory[index][remainder]!=0)
        return memory[index][remainder];

    int x,y;

    //if current element can be taken
    if(arr[index]<=remainder)
        x=solve(index,remainder-arr[index]);

    //go to next element
    y=solve(index+1,remainder);

    return x+y;
}

int main()
{
    //taking input from file & printing output to file
    //FI FO

    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        //vector clearing for each test case
        memset(memory,0,sizeof(memory));

        //variable value input
        cin>>x>>n;

        //vector value input
        for(int i=0; i<n; i++)
            cin>>arr[i];


        //printing the result
        cout<<solve(0,x)<<endl;
    }

    return 0;
}
/*
1
49 4
5 6 23 25
*/
