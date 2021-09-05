#include<bits/stdc++.h>
using namespace std;

int main()
{
    int in,gr,d,count=0,infg=0,grfg=0,dr=0;

    while(1)
    {
        cin>>in>>gr;
        cout<<"Novo grenal (1-sim 2-nao)"<<endl;
        count++;

        if(in>gr)
            infg++;
        else if(gr>in)
            grfg++;
        else
            dr++;

        cin>>d;
        if(d==2)
            break;
    }

    cout<<count<<" grenais"<<endl;

    cout<<"Inter:"<<infg<<endl;
    cout<<"Gremio:"<<grfg<<endl;
    cout<<"Empates:"<<dr<<endl;

    if(infg>grfg)
        cout<<"Inter venceu mais"<<endl;
    else if(grfg>infg)
        cout<<"Gremio venceu mais"<<endl;
    else
        cout<<"Não houve vencedor"<<endl;

    return 0;
}
