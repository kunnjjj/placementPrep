#include <iostream>
using namespace std;
// ABOUT struct
// A structure will by default not hide its implementation details from whomever uses it in code,
// while a class by default hides all its implementation details and will therefore
// by default prevent the programmer from accessing them, generally structs are used for lightweight objects
struct abc
{
    int a,b,c;
    abc()
    {
        cout<<"hello"<<endl;
    }
};

// ABOUT enum
// Enum in C++ is a data type that contains fixed set of constants.
// take only one value out of a set of values
// are only integral values

enum daysOfWeek
{
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday
};

// ABOUT friend function
// A friend function of a class is defined outside that class' scope but it has the right
// to access all private and protected members of the class. Even though the prototypes for
// friend functions appear in the class definition, friends are not member functions.

// A friend can be a function, function template, or member function,
// or a class or class template, in which case the entire class and all of its members are friends.
class Box
{
    double width;
    friend void printWidth(Box box);
public:
    
    void setWidth(double wid);
};

// Member function definition
void Box::setWidth(double wid)
{
    width = wid;
}
// Note: printWidth() is not a member function of any class.
void printWidth(Box box)
{
    cout << "Width of box : " << box.width << endl; 
}




int main()
{

    daysOfWeek d = tuesday;
    cout << d << endl;
    cout << sizeof(daysOfWeek) << endl; // 4 bytes : because its just an int


    Box b;
    b.setWidth(30);
    printWidth(b); // printing pvt member
    abc obj;


    return 0;
}