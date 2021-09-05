#include<bits/stdc++.h>
#include<cstring>
using namespace std;

void lcs( char *X, char *Y, int m, int n );

int main()
{
    char X[100],Y[100];
    int m,n;

    cout<<"Enter first string: ";
    cin>>X;
    cout<<"Enter second string: ";
    cin>>Y;

    m=strlen(X);
    n=strlen(Y);

    lcs(X, Y, m, n);

    return 0;
}

void lcs( char *X, char *Y, int m, int n )
{
    int L[m+1][n+1];

    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1]+1;

            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    cout<<endl<<"LCS is "<<L[m][n]<<endl;

    int index = L[m][n];

    char lcs[index+1];
    lcs[index]='\0';

    int i=m, j=n;

    while (i>0 && j>0)
    {
        if (X[i-1] == Y[j-1])
        {
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }

        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }

    if(L[m][n]==0)
        cout<<"There is no LCS in "<<X<<" and "<<Y<<endl;
    else
        cout << "LCS of "<<X<<" and "<<Y<<" is "<<lcs<<endl;
}
