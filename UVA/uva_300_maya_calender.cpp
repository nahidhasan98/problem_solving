#include<iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,day,year,m,sum=0,yr,dy;
    string month,mon;

    cin>>n;
    cout<<n<<endl;

    for(int i=1;i<=n;i++)
    {
        scanf("%d%.",&day);
        cin>>month>>year;

        if(month=="pop")
            m=1;
        else if(month=="no")
            m=2;
        else if(month=="zip")
            m=3;
        else if(month=="zotz")
            m=4;
        else if(month=="tzec")
            m=5;
        else if(month=="xul")
            m=6;
        else if(month=="yoxkin")
            m=7;
        else if(month=="mol")
            m=8;
        else if(month=="chen")
            m=9;
        else if(month=="yax")
            m=10;
        else if(month=="zac")
            m=11;
        else if(month=="ceh")
            m=12;
        else if(month=="mac")
            m=13;
        else if(month=="kankin")
            m=14;
        else if(month=="muan")
            m=15;
        else if(month=="pax")
            m=16;
        else if(month=="koyab")
            m=17;
        else if(month=="cumhu")
            m=18;
        else if(month=="uayet")
            m=19;

        sum=(year*365)+((m-1)*20)+(day+1);

        if((sum%260)==0)
            yr=(sum/260)-1;
        else
            yr=sum/260;

        sum=sum%260;

        int mn=(sum%20);

        if(mn==1)
            mon="imix";
        else if(mn==2)
            mon="ik";
        else if(mn==3)
            mon="akbal";
        else if(mn==4)
            mon="kan";
        else if(mn==5)
            mon="chicchan";
        else if(mn==6)
            mon="cimi";
        else if(mn==7)
            mon="manik";
        else if(mn==8)
            mon="lamat";
        else if(mn==9)
            mon="muluk";
        else if(mn==10)
            mon="ok";
        else if(mn==11)
            mon="chuen";
        else if(mn==12)
            mon="eb";
        else if(mn==13)
            mon="ben";
        else if(mn==14)
            mon="ix";
        else if(mn==15)
            mon="mem";
        else if(mn==16)
            mon="cib";
        else if(mn==17)
            mon="caban";
        else if(mn==18)
            mon="eznab";
        else if(mn==19)
            mon="canac";
        else if(mn==0)
            mon="ahau";

        if((sum%13)==0)
            dy=13;
        else
            dy=(sum%13);

        cout<<dy<<' '<<mon<<' '<<yr<<endl;

    }

    return 0;
}
