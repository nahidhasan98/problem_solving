#include<stdio.h>

int maxSize=100000;

int main()
{
    char msg[maxSize];

    FILE *fptr;
    fptr =fopen("in.txt","r");  //.c file and in.txt file should be in same folder/directory for this path.

    if (fptr==NULL) //if file not found
    {
        printf("Error while File reading!!");
        return 0;   //Exiting program
    }

    int asciiValue;
    while (fgets(msg,maxSize,fptr)!=NULL)   //taking input from file one line at once with spaces. while for multiple lines input.
    {
        for(int i=0; msg[i]!='\0'; i++)
        {
            asciiValue=(int)msg[i];

            if (asciiValue==10 && i==0) //[if any line has only one character(i=0) && that character is a newline(ascii value=10), then ignore it.]
                continue;
            else
                printf("%c",msg[i]);    //otherwise print it.
        }
    }

    fclose(fptr);

    return 0;
}
