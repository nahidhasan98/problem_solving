/*
Write a program to create a class named shape.
For this class, create three sub classes as circle, triangle and square.
Each of the four classes have two member functions named draw() and erase().
Each of these two member functions contain a message to output. The output message is like: perspective class name and function name.
For example, erase function from circle class should display this message: "circle erase function".
Create these using polymorphism concepts.

Also create one object for each class inside the main function and call each and every function using the objects created.
*/

#include<iostream>
using namespace std;

// Base class
class shape {
    public:
    void draw() {
        cout << "shape draw function" << endl;
    }
    void erase() {
        cout << "shape erase function" << endl;
    }
};

// Derived class
class circle : public shape {
    public:
    void draw() {
        cout << "circle draw function" << endl;
    }
    void erase() {
        cout << "circle erase function" << endl;
    }
};

// Derived class
class triangle : public shape {
    public:
    void draw() {
        cout << "triangle draw function" << endl;
    }
    void erase() {
        cout << "triangle erase function" << endl;
    }
};

// Derived class
class square : public shape {
    public:
    void draw() {
        cout << "square draw function" << endl;
    }
    void erase() {
        cout << "square erase function" << endl;
    }
};

int main()
{
    shape objShape;
    circle objCircle;
    triangle objTriangle;
    square objSquare;

    objShape.draw();
    objShape.erase();

    objCircle.draw();
    objCircle.erase();

    objTriangle.draw();
    objTriangle.erase();

    objSquare.draw();
    objSquare.erase();

    return 0;
}
