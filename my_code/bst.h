#include <iostream>

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
    friend void print_bst(const Bst<T>& bst, int level=0) {
        indent(level);
        level++;
        
        std::cout << "data: " << bst.data << std::endl;
        indent(level + 1);
        std::cout << "left: ";
        
        if (!bst.left) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.left, level);
        }
        indent(level + 1);
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.right, level);
        }
        std::cout << std::endl;
    }
    
public:
    Bst(T d, Bst* p=nullptr, Bst* l=nullptr, Bst* r=nullptr)
    : data(d), parent(p), left(l), right(r) {}
    
    Bst<T>* insert(const T d) {
        if(data == d) return nullptr;
        else if (d < data){
            if(!left){
                left = new Bst(d, this);
                return left;
            }else{
                return left->insert(d);
            }
        }
        else{
            if(!right){
                right = new Bst(d, this);
                return right;
            }else{
                return right->insert(d);
            }
        }
    }
    
    T get_val() const {
        return data;
    }
    
    Bst<T>* get_left() const{
        return left;
    }
    
    Bst<T>* get_right() const{
        return right;
    }
    
    Bst<T>* search(T val){
        if(data == val) return this;
        else if(val < data){
            if(!left) return nullptr;
            else return left->search(val);
        }else{
            if(!right) return nullptr;
            else return right->search(val);
        }
    }
private:
    T data;
    Bst<T>* parent;
    Bst<T>* left;
    Bst<T>* right;
};

template <typename T>
T min(const Bst<T>* node){
    if(!node->get_left()) return node->get_val();
    else return min(node->get_left());
}

template <typename T>
T max(const Bst<T>* node){
    if(!node->get_right()) return node->get_val();
    else return max(node->get_right());
}



