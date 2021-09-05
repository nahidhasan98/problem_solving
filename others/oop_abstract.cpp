/*
Create an abstract class named Box which has the following properties:
    - two attributes: a & b (double data type)
    - one method: setValue (which takes two double value as parameters and set the value to a & b)
    - and one pure virtual method: operation.
Create a subclass of Number class named Sum which implements operation(), this method will display the sum of a & b.
Create another subclass of Number class named Multiply which implements operation(), this method will display the multiplication of a & b.
For simplicity, you can keep all the class properties as public.

Now in the main function, create two separate object of Sum & Multiply class.
Set any random double value to a & b using setValue method for each object. Finally call the operation method via each object.
*/

#include<iostream>
using namespace std;

class Number {
    public:
    double a, b;
    void setValue(double num1, double num2) {
        a = num1;
        b = num2;
    }

    virtual void operation() = 0;
};

// This class inherits from Number and implements operation()
class Sum: public Number {
    public:
    void operation() {
        cout << a + b << endl;
    }
};

// This class inherits from Number and implements operation()
class Multiply: public Number {
    public:
    void operation() {
        cout << a * b << endl;
    }
};

int main()
{
    Sum objS;
    objS.setValue(2, 3);
    objS.operation();

    Multiply objM;
    objM.setValue(2, 3);
    objM.operation();

    return 0;
}
