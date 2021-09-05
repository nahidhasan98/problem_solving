#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

long long n,a,b,c,mod=10007;

struct twoD
{
    long long A[4][4];
    long long Y[4][1];
};

long long baseMul(twoD mExp,twoD Base)
{
    long long res=0;

    for(int i=0;i<4;i++)
        res+=(mExp.A[0][i]*Base.Y[i][0])%mod;

    return res;
}
twoD matMul(twoD A,twoD B)
{
    twoD res;
    long long temp;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            temp=0;
            for(int k=0;k<4;k++)
                temp+=(A.A[i][k]*B.A[k][j])%mod;

            res.A[i][j]=temp;
        }
    }
    return res;
}

twoD matExp(twoD matrix,long long n)
{
    if (n==1) return matrix;

    twoD temp=matExp(matrix,n/2);
    twoD res=matMul(temp,temp);

    if(n%2==1) res=matMul(res,matrix);

//    cout<<"n="<<n<<endl;
//    for(int i=0;i<4;i++)
//    {
//        for(int j=0;j<4;j++)
//            cout<<res.A[i][j]<<' ';
//        cout<<endl;
//    }

    return res;
}

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        cin>>n>>a>>b>>c;
        twoD matrix;

        matrix.A[0][0]=a; matrix.A[0][1]=0; matrix.A[0][2]=b; matrix.A[0][3]=c;
        matrix.A[1][0]=1; matrix.A[1][1]=0; matrix.A[1][2]=0; matrix.A[1][3]=0;
        matrix.A[2][0]=0; matrix.A[2][1]=1; matrix.A[2][2]=0; matrix.A[2][3]=0;
        matrix.A[3][0]=0; matrix.A[3][1]=0; matrix.A[3][2]=0; matrix.A[3][3]=1;

        matrix.Y[0][0]=0;
        matrix.Y[1][0]=0;
        matrix.Y[2][0]=0;
        matrix.Y[3][0]=1;

        long long res=0;

        if(n<=2) res=0;
        else
        {
            twoD f=matExp(matrix,n-2);
            res=baseMul(f,matrix);
        }
        cout<<"Case "<<t<<": "<<res<<endl;
    }

    return 0;
}
