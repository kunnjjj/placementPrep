#include <iostream>
using namespace std;
// diff btw interfaces and classes in general
// A class describes the attributes and behaviors of an object.
// An interface contains behaviors that a class implements.
// C++ interfaces are implemented using abstract classes

// Abstract classes are the way to achieve abstraction in C++.
// Abstraction in C++ is the process to hide the internal details and showing functionality only.


// Data Abstraction is a programming technique that
// depends on the seperation of the interface and implementation details of the program.
// access specifiers implement abstraction
// header files also implement abstraction, eg we don't see implementation of pow fn



class Shape
{
public:
    virtual void draw() = 0;
};
class Rectangle : Shape
{
public:
    void draw()
    {
        cout << "drawing rectangle..." << endl;
    }
};
class Circle : Shape
{
public:
    void draw()
    {
        cout << "drawing circle..." << endl;
    }
};
int main()
{
    Rectangle rec;
    Circle cir;
    rec.draw();
    cir.draw();
    // Shape S; // this cant be made as it contains pure virtual function


    return 0;
}