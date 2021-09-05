/*
Write a function named check. If the function has:
    - one parameter (an integer number) then it will return a string "even" if the number is even, or "odd" if the number is odd.
    - one parameter (a character) then it will return a string "vowel" if the character is vowel, or "consonant" if the character is consonant.
    - two parameter (two double number) it will return the multiplication of these two numbers.
    - three parameter (three integer number) it will return the summation of these three numbers.
You have to keep these four function with same name.
In main function, call these four function with different number/type of parameter and test the program. You can use any random value as arguments to pass for testing.
*/

#include<iostream>
using namespace std;

string check(int number) {
    if (number%2==0)
        return "even";
    else
        return "odd";
}

string check(char c) {
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return "vowel";
    else
        return "consonant";
}

double check(double number1, double number2) {
    return number1 + number2 ;
}

int check(int number1, int number2, int number3) {
    return number1 + number2 + number3;
}

int main() {
    cout << check(45) << endl;
    cout << check('h') << endl;
    cout << check(3.8, 4.5) << endl;
    cout << check(3, 4, 8) << endl;

    return 0;
}
