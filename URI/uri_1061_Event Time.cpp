#include<bits/stdc++.h>
using namespace std;

int main()
{
    int d1,h1,m1,s1,d2,h2,m2,s2;
    string str;

    cin>>str>>d1;
    scanf("%d : %d : %d",&h1,&m1,&s1);

    cin>>str>>d2;
    scanf("%d : %d : %d",&h2,&m2,&s2);


    int res1=(d1*24*60*60)+(h1*60*60)+(m1*60)+s1;
    int res2=(d2*24*60*60)+(h2*60*60)+(m2*60)+s2;

    int res=res2-res1;

    int s=res%60;
    res=res/60;

    int m=res%60;
    res=res/60;

    int h=res%24;
    res=res/24;

    int d=res;

    cout<<d<<" dia(s)"<<endl<<h<<" hora(s)"<<endl<<m<<" minuto(s)"<<endl<<s<<" segundo(s)"<<endl;

    return 0;
}

