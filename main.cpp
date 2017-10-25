#include <iostream>
#include <algorithm>
#include "OurList.h"

void x(int a) {
    int* poi = new int(a);
    //some other code with no call to delete
}

//1(d) method
void another_swap(int*& lhs, int*& rhs) {
    int* temp = lhs; lhs = rhs; rhs = temp;
}

int main() {

    //basic pointer example
    std::cout << "POINTER EXAMPLE 1\n-----------------" << std::endl;
    int a = 5; //store a number somewhere in mem, a = 5
    int* b = &a; //pointer to a
    std::cout << "a = " << a << "\n*b = &a\n"
              << "b = " <<  b << "\n*b = " << *b
              << std::endl;

    //arithmetic with pointers dereference
    std::cout << "\n\nPOINTER EXAMPLE 2\n-----------------" << std::endl;
    a = 10;
    b = &a;
    std::cout << "a = " << a
              << "\nb = " <<  b
              << "\n*b = " << *b
              << std::endl;
    a = *b + 5;
    std::cout << "a = *b + 5\na = " << a << std::endl;
    *b = *b + 5;
    std::cout << "*b = *b + 5\na = " << a << std::endl;

    //pointer arithmetic
    std::cout << "\n\nPOINTER EXAMPLE 3\n-----------------" << std::endl;
    a = 5;
    b = &a;
    std::cout << "a = " << a
              << "\nb = " <<  b
              << "\n*b = " << *b
              << std::endl;
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




    //Midterm Questions
    std::cout << "\n\n///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"
            "\n\nMIDTERM QUESTION 1(d)\n---------------------" << std::endl;
    //1(d) this is a pass by reference question

    int x = 5, y = 10;
    int *A = &x, *B = &y;
    int **j = &A, **k = &B;
    std::cout << "x = " << x << ", y = " << y
              << "\na = " << A << ", b = " << B
              << "\n*a = " << *A << ", *b = " << *B
              << "\nj = " << j << ", k = " << k
              << "\n*j = " << *j << ", *k = " << *k
              << "\n**j = " << **j << ", **k = " << **k
              << "\nAs we can see, a is a pointer to x and j is a pointer to a which points to x"
              << std::endl;

    std:: cout << "\nCall another_swap(a, b) and lets look at values now" << std::endl;
    another_swap(A, B);

    std::cout << "x = " << x << ", y = " << y
              << "\n*a = " << *A << ", *b = " << *B
              << "\n**j = " << **j << ", **k = " << **k
              << "\nAs you can see, all values but x and y swapped."
              << "\n\nLets look at the pointers as well"
              << "\na = " << A << ", b = " << B
              << "\nj = " << j << ", k = " << k
              << "\n*j = " << *j << ", *k = " << *k
              << "\nComparing to the original value of the pointers, we can see a and b swapped, *j and *k swapped but nothing else"
              << "\n\nSo what swapped? Looking closely, we can see all that swapped is the address stored in a and b"
              <<"\nANSWER: B"
              << std::endl;


    //1(e) tests knowledge of pointers and kinda <algorithm>
    std::cout << "\n\nMIDTERM QUESTION 1(e)\n----------------------" << std::endl;
    int X = 10;
    int *Y = &X;
    int *z = new int;
    z[0] = 20;
    std::cout << "x = " << X << "\ny = " << Y << "\nz = " << z << "\nz[0] = " << z[0]
              << "\nWe can see y = address of x, z is an address on the heap"
              << "\nLets call std::swap(y, z) and see what happens"
              << std::endl;
    std::swap(Y, z);

    std::cout << "\nstd::swap(y, z)"
              << "\nx = " << X << "\ny = " << Y << "\nz = " << z << "\nz[0] = " << z[0]
              << "\nWe can see that x is unchanged, but the the address stored in y swapped with z but z[0] = 10 (x) now"
              << "\nreturn " << x << "\nANSWER: C" << std::endl;



    //2(a) tests knowledge of singly linked list
    std::cout << "\n\nMIDTERM QUESTION 2\n----------------------" << std::endl;
    OurList* theList = new OurList();
    std::cout << "Printing list:\nnode1: " << theList->head->_value
              << "\n  ||\n  \\/\nnode2: "<< theList->head->_next->_value
              << "\n  ||\n  \\/\nnode3: " << theList->head->_next->_next->_value
              << "\n\nNow lets test our functions:"
              << std::endl;

    //insert node after node2 with value 12
    theList->insert(theList->insertNode, 12);

    std::cout << "\nPrinting list after insert(node2, 12):\n\nnode1: " << theList->head->_value
              << "\n  ||\n  \\/\nnode2: "<< theList->head->_next->_value
              << "\n  ||\n  \\/\nnode3: " << theList->head->_next->_next->_value
              << "\n  ||\n  \\/\nnode4: " << theList->head->_next->_next->_next->_value
              << std::endl;

    //remove node after node3
    theList->remove(theList->head->_next->_next);

    std::cout << "\nPrinting list after remove(node2):\n\nnode1: " << theList->head->_value
              << "\n  ||\n  \\/\nnode2: "<< theList->head->_next->_value
              << "\n  ||\n  \\/\nnode3: " << theList->head->_next->_next->_value
              << std::endl;


    //3() tests ability to write recursive function
    theList->insert(theList->head, 22);
    std::cout << "\n\nMIDTERM QUESTION 3\n----------------------" << std::endl;
    std::cout << "\n*USING LIST FROM LAST QUESTION*\nPrinting current list:\n\nnode1: " << theList->head->_value
              << "\n  ||\n  \\/\nnode2: "<< theList->head->_next->_value
              << "\n  ||\n  \\/\nnode3: " << theList->head->_next->_next->_value
              << "\n  ||\n  \\/\nnode4: " << theList->head->_next->_next->_next->_value
              << "\n" << std::endl;

    theList->reverse(theList->head, nullptr);

    std::cout << "\nPrinting current list after fully reversed:\n\nnode1: " << theList->head->_value
              << "\n  ||\n  \\/\nnode2: "<< theList->head->_next->_value
              << "\n  ||\n  \\/\nnode3: " << theList->head->_next->_next->_value
              << "\n  ||\n  \\/\nnode4: " << theList->head->_next->_next->_next->_value
              << "\n\nLooking at how our list changes on each call to reverse, we can see that it takes param head, sets\n"
                      "next to param prevHead, until it reaches base case of reaching the last node, where it\n"
                      "links it and returns it"
              << std::endl;







};