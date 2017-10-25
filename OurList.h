//
// Created by Liam on 10/24/2017.
//

#ifndef MIDTERMTESTS_OURLIST_H
#define MIDTERMTESTS_OURLIST_H


//Node class as defined in lecture
class Node {
public:
    int _value;
    Node* _next;
};

class OurList {
public:

    //functionality for testing
    Node* head;
    Node* insertNode;


    void insert(Node* node, int value);
    bool remove(Node* node);


    //adding functionality for testing
    OurList() {
        head = new Node;
        head->_value = 5;

        Node* node1 = new Node;
        node1->_value = 10;
        head->_next = node1;

        Node* node2 = new Node;
        node2->_value = 20;
        node1->_next = node2;

        insertNode = node1;
    }
};

#endif //MIDTERMTESTS_OURLIST_H
