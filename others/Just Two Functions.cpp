#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

typedef vector<long long> oneD;
typedef vector<vector<long long> > twoD;

twoD matrixA=twoD(6,oneD(6,0));
twoD baseY=twoD(6,oneD(6,0));

twoD matrixMul(twoD A,twoD B,int mod)
{
    twoD res=twoD(6,oneD(6,0));
    long long temp;

    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        {
            temp=0;
            for(int k=0; k<6; k++)
                temp+=(A[i][k]*B[k][j])%mod;

            res[i][j]=temp%mod;
        }
    }

    return res;
}
twoD matrixExp(twoD matrix,int n,int mod)
{
    if(n==1) return matrix;

    twoD temp=twoD(6,oneD(6,0));
    twoD calc=twoD(6,oneD(6,0));

    temp=matrixExp(matrix,n/2,mod);
    calc=matrixMul(temp,temp,mod);

    if(n%2==1) calc=matrixMul(calc,matrix,mod);

    return calc;
}

int main()
{
    //FI FO

    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        long long a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2,mod,q,n;
        cin>>a1>>b1>>c1>>a2>>b2>>c2>>f0>>f1>>f2>>g0>>g1>>g2>>mod;

        baseY[0][0]=f2;
        baseY[1][0]=f1;
        baseY[2][0]=f0;
        baseY[3][0]=g2;
        baseY[4][0]=g1;
        baseY[5][0]=g0;

        matrixA[0][0]=a1;   matrixA[0][1]=b1;   matrixA[0][2]=0;    matrixA[0][3]=0;    matrixA[0][4]=0;    matrixA[0][5]=c1;
        matrixA[1][0]=1;    matrixA[1][1]=0;    matrixA[1][2]=0;    matrixA[1][3]=0;    matrixA[1][4]=0;    matrixA[1][5]=0;
        matrixA[2][0]=0;    matrixA[2][1]=1;    matrixA[2][2]=0;    matrixA[2][3]=0;    matrixA[2][4]=0;    matrixA[2][5]=0;
        matrixA[3][0]=0;    matrixA[3][1]=0;    matrixA[3][2]=c2;   matrixA[3][3]=a2;   matrixA[3][4]=b2;   matrixA[3][5]=0;
        matrixA[4][0]=0;    matrixA[4][1]=0;    matrixA[4][2]=0;    matrixA[4][3]=1;    matrixA[4][4]=0;    matrixA[4][5]=0;
        matrixA[5][0]=0;    matrixA[5][1]=0;    matrixA[5][2]=0;    matrixA[5][3]=0;    matrixA[5][4]=1;    matrixA[5][5]=0;

        cout<<"Case "<<t<<":"<<endl;

        cin>>q;
        for(int qr=1;qr<=q;qr++)
        {
            cin>>n;

            if(n==0) cout<<f0%mod<<' '<<g0%mod<<endl;
            else if(n==1) cout<<f1%mod<<' '<<g1%mod<<endl;
            else if(n==2) cout<<f2%mod<<' '<<g2%mod<<endl;
            else
            {
                twoD fn=twoD(6,oneD(6,0));
                twoD res=twoD(6,oneD(6,0));

                fn=matrixExp(matrixA,n-2,mod);
                res=matrixMul(fn,baseY,mod);

                cout<<res[0][0]<<' '<<res[3][0]<<endl;
            }
        }
    }

    return 0;
}
