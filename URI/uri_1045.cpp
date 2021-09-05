#include<bits/stdc++.h>
using namespace std;

int main()
{
    double z[3],a,b,c;

    while(cin>>z[0]>>z[1]>>z[2])
    {
        sort(z,z+3);

        a=z[2];
        b=z[1];
        c=z[0];

        if(a>=(b+c))
            cout<<"NAO FORMA TRIANGULO"<<endl;
        else
        {
            if((a*a)==((b*b)+(c*c)))
                cout<<"TRIANGULO RETANGULO"<<endl;
            if((a*a)>((b*b)+(c*c)))
                cout<<"TRIANGULO OBTUSANGULO"<<endl;
            if((a*a)<((b*b)+(c*c)))
                cout<<"TRIANGULO ACUTANGULO"<<endl;
            if((a==b)&&(a==c))
                cout<<"TRIANGULO EQUILATERO"<<endl;
            if(((a==b)&&(a!=c)) || ((b==c)&&(b!=a)) || ((c==a)&&(c!=b)))
                cout<<"TRIANGULO ISOSCELES"<<endl;
        }
    }

    return 0;
}
