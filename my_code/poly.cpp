//
//  poly.cpp
//  hw3
//
//  Created by Xinyu Qu on 2019/7/2.
//  Copyright © 2019 Xinyu Qu. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class A{
public:
    A(int a0):a(a0){ cout << "Constructing A \n";}
    ~A(){cout << "Destructing A; a ==" << a << "\n";}
//    virtual int my_int(){return a;}
    
    //copy constructor
    A(const A& other){
        cout << "In A's copy constructor. \n";
        a = other.a;
    }
private:
    int a;
};

class B : public A{
public:
    B():A(2),b(4){ cout << "Constructing A \n";}
    ~B(){cout << "Destructing B\n";}
//    virtual int my_int(){return b;}
    
    //copy constructor
    B(const B& other):A(other){
        cout << "In B's copy constructor. \n";
        b = other.b;
    }
private:
    int b;
    
};

class C : public B{
public:
    C():c(8){ cout << "Constructing A \n";}
    ~C(){cout << "Destructing C\n";}
//    virtual int my_int(){return c;}
    
    //copy constructor
    C(const C& other) : B(other){
        cout << "In C's copy constructor. \n";
        c = other.c;
    }
private:
    int c;
};


//int main(){
//    A a = A(2);
//    B b = B();
//    C c = C();
//
//    cout << "A size = " << sizeof(A) << endl;
//    cout << "B size = " << sizeof(B) << endl;
//    cout << "C size = " << sizeof(C) << endl;
//
//    C c2 = c;
//
//    A a2 = c;
//    cout << "a2 size = " << sizeof(a2) << endl;
//
//    vector<A*> v;
//    v.push_back(&a);
//    v.push_back(&b);
//    v.push_back(&c);
//
////    for(auto aptr : v){
////        cout << "int: " << aptr->my_int()<<endl;
////
////        }
//
//}
