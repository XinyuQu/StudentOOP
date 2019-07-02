//
//  templ_ll.h
//  cs2124
//
//  Created by Xinyu Qu on 2019/6/26.
//  Copyright © 2019 Xinyu Qu. All rights reserved.
//

#ifndef templ_ll_h
#define templ_ll_h

#include <iostream>

/*
 * The struct `Node`, which is the building block of our linked list code.
 * */
template <typename DATA>

class Node {
public:
    Node(DATA d, Node* n=nullptr) : data(d), next(n) {}
    DATA data;
    Node* next;
};


/*
 * The various functions that can operate on our linked lists:
 * */
template <typename DATA>
std::ostream& operator<<(std::ostream& os, const Node<DATA>* nd){
    if(!nd) os << "nullprt";
    else{
        os << "data: " << nd->data;
    }
    return os;
}

/*
 * Add a node to the end of a list.
 * */
template <typename DATA>
void add_at_end(Node<DATA>*& head, DATA d) {
    if (!head) {
        head = new Node<DATA>(d, nullptr);
    }else{
        add_at_end(head->next, d);
    }
}

template <typename DATA>

void print_list(ostream& os, const Node<DATA>* curr) {
    if (curr) {
        os << curr << " ";
        print_list(os, curr->next);
    }
    else{
        os << "\n";
    }
}
//void print_list(std::ostream& os, const Node* curr);
//Node* last(Node* head);
//void add_at_front(Node*& head, int d);
//
///*
// * These are coming:
// */
//
///*
// * Delete the first node and attach head to the 2nd node:
// * */
//bool del_head(Node*& head);
//
///*
// * Delete the last node and set prev->next to nullptr:
// * */
//bool del_tail(Node*& curr);
//
///*
// * Duplicate the entire list -- you must not share memory!
// * */
////void duplicate_helper(Node* old_node, Node*& new_node);
//Node* duplicate(Node* head);
//
///*
// * Reverse the list: return a brand new list with everything reversed.
// * */
//Node* reverse(Node* curr, Node* new_next=nullptr);
//
///*
// * Join two lists: tack list 2 onto the end of list 1:
// * Use existing memory.
// * */
//Node* join(Node*& list1, Node* list2);

#endif /* templ_ll_h */
