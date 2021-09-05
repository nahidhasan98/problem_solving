/*
Take a number from user as input.
If the number is between 10 to 20 inclusive, display a message "success!".
If the number is lower than 10, then throw an exception and in the catch block print a message "Low" for this exception.
Similarly if the number is higher than 20, then throw an exception and in the catch block print a message "High" for this exception.
N.B:
    - You must have to check the number inside a try block as invalid(lower/higher) number will throw an exception.
    - You must have to use your programming skill to differentiate the exception which will be thrown from try block,
    and depending on the exception, you have to display the perspective message inside the catch block.
*/

#include<iostream>
using namespace std;

int main() {
    int number;
    cin >> number;

    try {
        if (number < 10) {
            throw 1;
        } else if (number > 20) {
            throw 2;
        } else {
            cout << "Success!" << endl;
        }
    }
    catch (int msg) {
        if (msg == 1)
            cout << "Low" << endl;
        else if (msg == 2)
            cout << "High" << endl;
    }

    return 0;
}
