#include <iostream>
using namespace std;
// AGGREGATION COVERED LATER
class Animal
{
    int x;

public:
    int y;
    void eat()
    {
        cout << "eating" << endl;
    }
};
class Dog : public Animal
{
    int p;

public:
    int z;
    void bark()
    {
        cout << "barking" << endl;
    }
};

// AGGREGATION: HAS-A relationship
class Address
{
public:
    string street, houseno;
    Address(string street, string houseno)
    {
        this->street = street;
        this->houseno = houseno;
    }
    void print()
    {
        cout << "street: " << street << endl;
        cout << "house: " << houseno << endl;
    }
};
class Employee
{
   
    Address *add; // apparently only pointers can be used 
public:

    string name;
    Employee(string name, Address *add)
    {
        this->add = add;
        this->name=name;
    }
    void print()
    {
        cout << "name: " << this->name << endl;
        (*(this->add)).print();
    }
}; 
int main()
{

    Dog d;
    d.bark();
    d.eat();

    Dog *d1 = new Dog;
    d1->bark();
    d1->eat();
    int *x = new int;
    cout << x << endl;
    // size of pointers can be 4 bytes or 8 bytes
    cout << "size of x " << sizeof(x) << endl;
    cout << "size of d1 pointer " << sizeof(d1) << endl;

    cout << "size of dog obj " << sizeof(d) << endl;
    cout << "size of dog class " << sizeof(Dog) << endl;
    cout << "size of animal obj" << sizeof(Animal) << endl;
    cout<<"----------AGG-----"<<endl;
    Address add("one","j-1");
    Employee E("kunj",&add);

    E.print();

    return 0;
}

// single, multilevel
// multiple class A: public B,private C{}; may cause ambiguity at times
// hybrid: more than one type of inheritance
// hierarchichal: one base class and multiple derived classes
