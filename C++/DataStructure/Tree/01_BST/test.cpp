#include<iostream>

struct node
{
    int data;
    node* left;
    node* right;
    node* parent;

    node() : data(0), left(nullptr), right(nullptr), parent(nullptr) {}
    node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BST
{
public:
    BST() : root(nullptr) {}
    ~BST(){
        makeEmpty(root);
    }

    void insert(int val){
        root = insert(root, val);
    }

    void remove(int val){
        root = remove(root, val);
    }

    void display(){
        inorder(root);
    }

private:
    node* root;
    node* insert(node* n, int val){
        if(n == nullptr)
        {
            root = new node(val);
        }
        else if(n->data > val)
        {
            root->left = insert(root->left, val);
            root->left->parent = root;
        }
        else
        {
            root->right = insert(root->right, val);
            root->right->parent = root;
        }
        return root;
    }
    node* find(node* n, int val) {}
    node* remove(node* n, int val) {}
    node* findMin(node* n) {
        
    }
    node* findMax(node* n){}
    node* makeEmpty(node* n){}
    void inorder(node* n){}
};
