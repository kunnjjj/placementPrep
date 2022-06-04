#include <iostream>
using namespace std;
// polymorphism= "poly" meaning many,  "morphs" meaning morphs, mother wala example

// compile time, achieved by function or operator overloading
// early or static binding

class node
{
public:
    int d, e;
    node(int d, int e)
    {
        this->d = d;
        this->e = e;
    }
    void print()
    {
        cout << "d: " << d << endl;
        cout << "e: " << e << endl;
        cout << endl;
    }
    void operator+=(int x) // another method we just need to pass the argument in right
    {
        d += x;
        e += x;
    }
};
ostream &operator<<(ostream &o, node a)
{
    a.print();
    return o;
}

// RUNTIME polymorphism
// dynamic or late binding, achieved with help of virtual functions
class Animal
{
public:
    int x;
    void eat()
    {
        cout << "Eating...\n";
    }
    virtual void makingNoise()
    {
        cout<<"General Animal is making noise"<<endl;
    }
};
class Dog : public Animal
{
public:
    int y;
    void eat()
    {
        cout << "Dog is eating...\n";
    }
    void makingNoise()
    {
        cout<<"Dog is barking"<<endl;
    }
};
class Cat: public Animal
{
    public:
    int x;
    void eat()
    {
        cout<<"cat is eating...\n";
    }
    void makingNoise()
    {
        cout<<"Cat is meowing"<<endl;
    }
};
int main()
{

    node a = node(26, 40);
    node b = a;
    cout << a;
    operator<<(cout, a);
    // this acts similar to a function
    a += 5;
    cout << a << b;
    cout << "\n---------runtime poly--------\n";
    // over riding
    
    // C++  allows derived class to base class pointers
    // good analogy: https://stackoverflow.com/questions/4937180/a-base-class-pointer-can-point-to-a-derived-class-object-why-is-the-vice-versa
    // good usecase explanation: https://stackoverflow.com/questions/59022414/why-use-a-parent-pointer-to-point-to-a-child-class#:~:text=With%20inheritance%20each%20descendant%20inherits,also%20called%20%22dynamic%20binding%22.
    Dog d;
    Cat c;
    Animal A;
    d.eat();
    d.makingNoise();

    c.eat();
    c.makingNoise();

    A.eat();
    A.makingNoise(); 

    Animal *x= new Dog; //allowed
    x->eat(); 
    x->makingNoise();

    Dog *D=new Dog;
    D->eat();
    D->makingNoise();
    
    // parent class pointer to derived class is allowed
    // if you simply do assignment then it doesnt happen

    A=d;  // allowed
    A.eat(); // prints acc to animal
    A.makingNoise(); // prints acc to animal

    A=c; // allowed
    A.eat(); //prints acc to animal
    A.makingNoise(); // acc to animal only 

    



    return 0;
}