#include<stdio.h>
#include<conio.h>
int insert_item();
int delete_item();

int data[15]={2,5,8,13,16,25,33,49};
int n=8,i,choice,item,item_pos=0;

int main()
{
    printf("data[15]={");
    for(i=0;i<8;i++)
        printf("%d,",data[i]);
    printf("\b}\n");

    printf("\nPlease select a choice:\t\n\n1. Insert an item/element\n2. Delete an item/element\n\n");
    scanf("%d",&choice);

    if(choice==1)
    {
        insert_item();
        getch();
    }

    else if(choice==2)
    {
        delete_item();
        getch();
    }

    else
        printf("\nInvalid selection. Please try again.\n");
}

insert_item()
{
    printf("\nPlease input an item you want to insert:\t");
    scanf("%d",&item);
    printf("\nIn which position you want to insert?:\t");
    scanf("%d",&item_pos);

    if(item_pos>=1 && item_pos<=n+1)
    {
        for(i=n-1;i>=item_pos-1;i--)
            data[i+1]=data[i];

        data[item_pos-1]=item;
        n=n+1;

        printf("\nModified array is data[15]={");
        for(i=0;i<n;i++)
            printf("%d,",data[i]);
        printf("\b}\n\n");
    }

    else
        printf("\nPosition you entered is out of bound. Please try again.\n");
}

delete_item()
{
    printf("\nWhat item do you want to delete:\t");
    scanf("%d",&item);

    for(i=0;i<n;i++)
    {
        if(data[i]==item)
            {
                item_pos=i;
                break;
            }
    }

    if(item_pos==i)
    {
        for(i=item_pos;i<n;i++)
            data[i]=data[i+1];

        n=n-1;

        printf("\nModified array is data[15]={");
        for(i=0;i<n;i++)
            printf("%d,",data[i]);
        printf("\b}\n\n");
    }

    else
        printf("\nThe item you want to delete is not present in the array.\n");
}
