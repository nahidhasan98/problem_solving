#include<stdio.h>
void TOWER(int N,char BEG,char END,char AUX);
int main()
{
    int N;
    printf("First enter the number of disks:\t");
    scanf("%d",&N);

    TOWER(N,'A','B','C');

    return 0;
}
TOWER(int N,char BEG,char AUX,char END)
{
    if(N==1)
    {
        printf("\nMove disk 1 from peg %c to peg %c",BEG,END);
        return;
    }

    TOWER(N-1,BEG,END,AUX);
    printf("\nMove disk %d from peg %c to peg %c",N,BEG,END);
    TOWER(N-1,AUX,BEG,END);
}
