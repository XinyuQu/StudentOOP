#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
    if(!nd) os << "nullprt";
    else{
        os << "data: " << nd->data;
    }
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
    if (!head) {
        head = new Node(d, nullptr);
    }else{
        add_at_end(head->next, d);
    }
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
    if (curr) {
        os << curr << " ";
        print_list(os, curr->next);
    }
    else{
        os << "\n";
    }
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
    head = new Node(d, head);
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
    if(!head)
        return nullptr;
    else if(!head->next)
        return head;
    else
        return last(head->next);
}

bool del_head(Node*& head){
    if(!head) return false;
    else{
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
}

bool del_tail(Node*& curr){
    if(!curr) return false;
    else{
        if(curr->next == nullptr){
            delete curr;
            curr = nullptr;
            return true;
        }
        else{
            return del_tail(curr->next);
        }
    }
}

Node* duplicate(Node* head){
    if(!head) return nullptr;
    else{
        Node* new_node = new Node(head->data, duplicate(head->next));
        return new_node;
    }
}

Node* reverse(Node* curr, Node* new_next){
    if (!curr) return new_next;
    else{
        return reverse(curr->next, new Node(curr->data, new_next));
    }
}

Node* join(Node*& list1, Node* list2){
    if(!list1) return list2;
    else if (!list2) return list1;
    else{
        Node* lst1_last_node = last(list1);
        lst1_last_node->next = list2;
        return list1;
    }
}




