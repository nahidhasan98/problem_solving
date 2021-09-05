#include<stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    if ( a == 0) {
        printf("0\n");
    } else {
        //digit separating process
        int arr[10], i = 1, totalDigit = 0;

        while( a > 0 ) {
            int lastDigit = a % 10;

            arr[10-i] = lastDigit;
            i++;
            totalDigit++;

            a = a / 10;
        }

        //comma printing process
        // 0 0 0 1 1 7 1 1 2 3

        char res[12], id = 0;
        int print = 0, comma = 0;

        for ( int k = 9; k >= 10 - totalDigit; k--) {
            res[id] = arr[k] + 48;
            print++;
            id++;

            if ( print % 3 == 0 ) {
                res[id] = ',';
                id++;
                comma++;
            }
        }

        for ( int k = totalDigit + comma - 1; k >= 0; k-- ) {
            if ( k == totalDigit + comma - 1 && res[k] == ',' ) {
                //no code here
            } else {
                printf("%c", res[k]);
            }
        }
        printf("\n");
    }

    return 0;
}
