#include<stdio.h>

int main()
{
    int a[10],index=0,counter=0,number;
    int smallest=1000000000,largest=-1;
    double hSum=0,hMean=0;

    while(counter<10)
    {
        scanf("%d",&number);

        if(number>=1)
        {
            a[index]=number;

            index++;
            counter++;

            if(number<smallest)
                smallest=number;
            if(number>largest)
                largest=number;

            hSum+=1.0/number;
        }
    }

    hMean=10.0/hSum;

    printf("Largest number: %d\n",largest);
    printf("Smallest number: %d\n",smallest);
    printf("Harmonic Mean: %lf\n",hMean);

    return 0;
}
