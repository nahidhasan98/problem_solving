#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d;

    while(cin>>a>>b>>c>>d)
    {
        int x=(a*60)+b;
        int y=(c*60)+d;

        if(x==y)
            cout<<"O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)"<<endl;
        else if(x<y)
            cout<<"O JOGO DUROU "<<((y-x)/60)<<" HORA(S) E "<<((y-x)%60)<<" MINUTO(S)"<<endl;
        else
        {
            int h=24*60;
            int g=(a*60)+b;

            int e=(c*60)+d;

            int r=h-g+e;

            cout<<"O JOGO DUROU "<<r/60<<" HORA(S) E "<<r%60<<" MINUTO(S)"<<endl;
        }
    }

    return 0;
}
