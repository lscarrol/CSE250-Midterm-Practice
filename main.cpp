#include <iostream>


void x(int a) {
    int* poi = new int(a);
    //some other code with no call to delete
}

int main() {

    //basic pointer example
    std::cout << "POINTER EXAMPLE 1\n-----------------" << std::endl;
    int a = 5; //store a number somewhere in mem, a = 5
    int* b = &a; //pointer to a
    std::cout << "a = " << a << '\n' << "*b = &a\n" << "b = " <<  b << '\n' << "*b = " << *b << std::endl;

    //arithmetic with pointers dereference
    std::cout << "\n\nPOINTER EXAMPLE 2\n-----------------" << std::endl;
    a = 10;
    b = &a;
    std::cout << "a = " << a << '\n' << "b = " <<  b << '\n' << "*b = " << *b << std::endl;
    a = *b + 5;
    std::cout << "a = *b + 5\na = " << a << std::endl;
    *b = *b + 5;
    std::cout << "*b = *b + 5\na = " << a << std::endl;

    //pointer arithmetic
    std::cout << "\n\nPOINTER EXAMPLE 3\n-----------------" << std::endl;
    a = 5;
    b = &a;
    std::cout << "a = " << a << '\n' << "b = " <<  b << '\n' << "*b = " << *b << std::endl;
    b = b + 1;
    std::cout << "b = b + 1\nb = " << b << "\n*b = " << *b << std::endl;

    //dynamic mem example
    std::cout << "\n\nDYNAMIC MEMORY EXAMPLE 1\n-------------------------" << std::endl;
    int* p = new int;
    std::cout << "int* p = new int\np = " << p << "\n*p = " << *p
              << "\n*p is a random number because it hasnt been initialized yet" << std::endl;

    //initializing dynamic mem
    std::cout << "\n\nDYNAMIC MEMORY EXAMPLE 2\n-------------------------" << std::endl;
    std::cout << "*p = " << *p << std::endl;
    *p = 5;
    std::cout << "set *p = 5\n" << "p = " << p << "\n*p = " << *p << std::endl;

    //bad memory management example
    std::cout << "\n\nDYNAMIC MEMORY EXAMPLE 3\n-------------------------" << std::endl;
    std::cout << "p = " << p <<"\n*p = " << *p
              << "\np points to address on heap that has value 5\nnow set p = new int(10)"
              << std::endl;
    int oldAdd = *p;
    p = new int(10);
    std::cout << "p = " << p << "\n*p = " << *p << "\nthis makes p point to new address on heap with value 10\nseems fine, but address: "
              << &oldAdd << " still holds value: " << oldAdd << " and is lost\n" << std::endl;

   //good mem management
    std::cout << "\nDYNAMIC MEMORY EXAMPLE 3\n-------------------------" << std::endl;
    std::cout << "p = " << p <<"\n*p = " << *p
              << "\np points to address on heap that has value 10\nnow set p = new int(20), but first call delete p"
              << std::endl;
    delete p;
    p = new int(20);
    std::cout << "p = " << p << "\n*p = " << *p << "\nnow p points at new/same address on heap with no memory leaks" << std::endl;
    std::cout << "\n*NOTE: if you delete p and you dont have anything to reassign p to, p = NULL to avoid a dangling pointer" << std::endl;

    //common mistakes that cause mem leaks
    std::cout << "\n\nDYNAMIC MEMORY EXAMPLE 4\n-------------------------" << std::endl;
    x(5);
    std::cout << "call to function x(5) will store a value on the heap with value 5 with no way to access it creating garbage" << std::endl;
    
};