#include <iostream>
using namespace std;
// ABOUT 'this'
// each object gets its own copy of data members and all
// objects share a single copy of member functions 
// so we may use 'this' keyword
// this is an r-value, which means it may appear only at r side, you cannot do this=t
// this isn't available for a static member func



// ABOUT 'static'
class Account {  
   public:  
       int accno; //data member (also instance variable)      
       string name; //data member(also instance variable)  
       static float rateOfInterest;   
       Account(int accno, string name)   
        {    
             this->accno = accno;    
            this->name = name;    
        }    
       void display()    
        {    
            cout<<accno<<" "<<name<< " "<<rateOfInterest<<endl;   
        }    
};  
float Account::rateOfInterest=6.5; // this is a static member
// Unlike instance field which gets memory each time whenever you create object, 
// there is only one copy of static field created in the memory. It is shared to all the objects.





class A
{
    // default and parametarized easy
    int d;
    string name;

public:
    A(int d,string name)
    {
        this->d=d;
        this->name=name;
    }
    A(A &x) // copy constructor (by us) [line1]
    {
        // this->d=x.d;  // commenting gives junk value
        // this->name=x.name;
        this->d=x.d; 
        this->name=x.name;
    }
    void print()
    {
        cout<<"d: "<<d<<" , name: "<<name<<endl;
    }

};
    // Shallow copy: A Shallow copy is defined as the process of creating
    // the copy of an object by copying data of all the member variables as it is.
    // The default copy constructor can only produce the shallow copy
    // A2=A1 // when [line1] isn't defined


class B
{
    public:
    int x,y;
    int *z;
    B()
    {
        z=new int;
    }
    void setData(int x,int y,int z1)
    {
        this->x=x;
        this->y=y;
        (*z)=z1;
    }
    void print()
    {
        cout<<"&x: "<<&x<<endl;
        cout<<"x: "<<x<<endl;
        cout<<"y: "<<y<<endl;
        cout<<"(*z): "<<(*z)<<endl;
        cout<<"z: "<<z<<endl;

    }

};

int main()
{
    A obj1(4,"kunj");

    A obj2=obj1;
    obj1.print();
    obj2.print();
    A obj3(obj1);
    obj3.print();

    B one;
    one.setData(4,5,6);
    B two=one;
    one.print();
    two.print();

    *(one.z)=5;
    one.print();
    two.print(); //updates value of z in two also //shallow copy
    // such a problem is solved by deep copy, make constructor like [line1]
    // Deep copy dynamically allocates the memory for the copy and then copies the actual value,
    // both the source and copy have distinct memory locations. 
    // In this way, both the source and copy are distinct and will not share the same memory location. 
    // Deep copy requires us to write the user-defined constructor.

    Account x(123,"abc");
    Account y(23,"abcdddd");

    x.display();
    y.display();

    return 0;
}