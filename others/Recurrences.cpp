#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

typedef vector<int> oneD;
typedef vector<vector<int> > twoD;

long long d,n,mod;

twoD matMul(twoD A,twoD B)
{
    twoD res=twoD(d,oneD(d,0));
    long long temp;

    for(int i=0; i<d; i++)
    {
        for(int j=0; j<d; j++)
        {
            temp=0;
            for(int k=0; k<d; k++)
                temp+=((A[i][k]%mod)*(B[k][j]%mod))%mod;

            res[i][j]=temp%mod;
        }
    }

    return res;
}

twoD matExp(twoD matrix,int n)
{
    if(n==1) return matrix;

    twoD temp=twoD(d,oneD(d,0));
    twoD calc=twoD(d,oneD(d,0));

    temp=matExp(matrix,n/2);
    calc=matMul(temp,temp);

    if(n%2==1) calc=matMul(calc,matrix);

    return calc;
}
int main()
{
    while(cin>>d>>n>>mod)
    {
        if(d==0 && n==0 && mod==0) break;

        int a[d],f[d];
        for(int i=0;i<d;i++) cin>>a[i];
        for(int i=0;i<d;i++) cin>>f[i];

        twoD matrixA=twoD(d,oneD(d,0));         // let, d=5: a1,a2,a3,a4,a5 & n=100
        for(int i=0;i<d;i++)                    // f(n)=a1*f(n-1)+a2*f(n-2)+a3*f(n-3)+a1*f(n-4)+a1*f(n-5)    , n>d
        {                                       //
            for(int j=0;j<d;j++)                //      matrixA         baseY       res
            {                                   // | a1 a2 a3 a4 a5 | | f(n-1) | | f(n)   |
                if(i==0) matrixA[i][j]=a[j];    // | 1  0  0  0  0  | | f(n-2) | | f(n-1) |
                if(i==j+1) matrixA[i][j]=1;     // | 0  1  0  0  0  |*| f(n-3) |=| f(n-2) |
            }                                   // | 0  0  1  0  0  | | f(n-4) | | f(n-3) |
        }                                       // | 0  0  0  1  0  | | f(n-5) | | f(n-4) |

        twoD baseY=twoD(d,oneD(d,0));
        for(int i=d-1;i>=0;i--)
            baseY[i][0]=f[i];

        if(n<=d) cout<<f[n-1]%mod<<endl;
        else
        {
            twoD fn=twoD(d,oneD(d,0));
            twoD res=twoD(d,oneD(d,0));

            fn=matExp(matrixA,n-d);
            res=matMul(fn,baseY);

            cout<<res[0][0]<<endl;
        }
    }

    return 0;
}
