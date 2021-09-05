#include<iostream>
#include<vector>
using namespace std;

typedef vector<long long> oneD;
typedef vector<vector<long long> > twoD;

int powerCalc(int base,int pow)
{
    if(pow==0) return 1;
    if(pow==1) return base;
    return base*powerCalc(base,pow-1);
}
twoD matrixMul(twoD A,twoD B,int mod)
{
    twoD res=twoD(2,oneD(2));
    long long temp;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            temp=0;
            for(int k=0; k<2; k++)
                temp+=(A[i][k]*B[k][j])%mod;

            res[i][j]=temp%mod;
        }
    }

    return res;
}
twoD matrixExp(twoD matrix,int n,int mod)
{
    if(n==1) return matrix;

    twoD temp=twoD(2,oneD(2));
    twoD calc=twoD(2,oneD(2));

    temp=matrixExp(matrix,n/2,mod);
    calc=matrixMul(temp,temp,mod);

    if(n%2==1) calc=matrixMul(calc,matrix,mod);

    return calc;
}

int main()
{
    twoD matrix=twoD(2,oneD(2));
    twoD fn=twoD(2,oneD(2));

    matrix[0][0]=1; matrix[0][1]=1;
    matrix[1][0]=1; matrix[1][1]=0;

    int n,m;
    while(cin>>n>>m)
    {
        int mod=powerCalc(2,m);
        long long res;

        if (n==0) res=0;
        else if (n==1 || n==2) res=1;
        else
        {
            fn=matrixExp(matrix,n-1,mod);
            res=fn[0][0]%mod;
        }
        cout<<res<<endl;
    }

    return 0;
}
