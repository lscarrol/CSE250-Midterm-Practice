//
// Created by Liam on 10/24/2017.
//
#include <iostream>
#include "OurList.h"

//this method inserts value AFTER param node
void OurList::insert(Node *node, int value) {
     //checks if nullptr
    if (node == nullptr) {return;}
    else {
        //create new node with value
        Node* addNode = new Node;

        //set value in addNode to param value
        addNode->_value = value;

        //IMPORTANT this will link addNode to the possible node that comes after node
        addNode->_next = node->_next;

        //now links addNode to node
        node->_next = addNode;
    }


}


//this method removes a node after param node
bool OurList::remove(Node *node) {
    //check if node is null
    if (node == nullptr) {return false;}

    //check if node is last node
    if (node->_next == nullptr) {return false;}

    //in order to actually remove without mem leak, must call delete on the node to remove
    Node* delNode = node->_next;

    //link up list without node to be removed
    node->_next = node->_next->_next;

    //delete node to remove
    delete delNode;

    return true;
}


//this method reverses a singly linked list
Node* OurList::reverse(Node* head, Node* prevHead) {
    Node* temp;
    //base case, if head.next = nullptr
    if (head->_next == nullptr) {
        head->_next = prevHead;
        this->head = head;
        return head;
    } else {
        printList(head);
        temp = reverse(head->_next, head);
        head->_next = prevHead;
        return temp;
    }

}


//print list for recursive calls
void OurList::printList(Node* head) {
    Node* curr = head;
    int count = 1;
    std::cout << "\nNew Call Printing list:\n" << std::endl;
    while (curr != nullptr) {
        std::cout << "node" << count << ": " << curr->_value
                  << "\n  ||\n  \\/"
                  << std::endl;
        curr = curr->_next;
        count++;
    }
}
