#include<iostream>
#include<cassert>
#include<string>
#include<vector>

struct node
{
    int data;
    node* left;
    node* right;

    node() : data(0), left(nullptr), right(nullptr) {}
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST
{
public:
    BST() : root(nullptr) {}
    ~BST(){
        makeEmpty(root);
    }

    void insert(int val){
    /* if the element should be uniq, then find method should be used */
        if(find(root, val) == nullptr)
            insert(root, val);
    }

    bool remove(int val){
        return remove(root, val);
    }

    void display(){
        inorder(root);
        std::cout << '\n';
    }

    bool find(int val)
    {
        if(find(root, val) == nullptr)
            return false;
        else
            return true;
    }

    int findMax()
    {
        return findMax(root)->data;
    }

    int findMin()
    {
        return findMin(root)->data;
    }

private:
    node* root;
    void insert(node*& n, int val){
        if(n == nullptr)
        {
            n = new node(val);
        }
        else if(n->data > val)
        {
            insert(n->left, val);
        }
        else
        {
            insert(n->right, val);
        }
    }
    node* find(node* n, int val) {
        if(n == nullptr)    return nullptr;
        else if(n->data == val)
        {
            return n;
        }
        else if(n->data > val)
        {
            return find(n->left, val);
        }
        else
        {
            return find(n->right, val);
        }
    }
    bool remove(node*& n, int val) {
        if(n == nullptr) return false;
        if(n->data > val)
            return remove(n->left, val);
        else if(n->data < val)
            return remove(n->right, val);
        else
        {
            if(n->right == nullptr || n->left == nullptr)
            {
                node* tmp = n->left?n->left:n->right;
                if(tmp == nullptr)
                {
                    tmp = n;
                    n = nullptr;
                }
                else
                {
                    *n = *tmp;
                }
                delete tmp;
                return true;
            }
            else
            {
                int minVal = findMin(n->right)->data;
                n->data = minVal;
                return remove(n->right, minVal);
            }
        }
    }
    node* findMin(node* n) {
        assert(n != nullptr);
        node* cur = n;
        while(cur->left)
        {
            cur = cur->left;
        }
        return cur;
    }
    node* findMax(node* n){
        assert(n != nullptr);
        node* cur = n;
        while(cur->right)
        {
            cur = cur->right;
        }
        return cur;
    }
    void makeEmpty(node* n){
        if(n == nullptr)    return;
        else
        {
            makeEmpty(n->left);
            makeEmpty(n->right);
            delete n;
        }
    }
    void inorder(node* n){
        if(n == nullptr)    return;
        inorder(n->left);
        std::cout<<n->data<<" ";
        inorder(n->right);
    }
};

int main()
{
    std::vector<int> nums{1,6,4,2,9,7,5,99,44,678,333,444,555,123,67,34,56,89,79,91,24,56,777,12,12,28};
    BST bst;
    for(int num:nums)
    {
        bst.insert(num);
    }

    std::cout << "max: " << bst.findMax() << '\n';
    std::cout << "min: " << bst.findMin() << '\n';
    bst.display();

    if(bst.remove(12))
    {
        std::cout << "12 is removed: \n";
        bst.display();
    }  
    else std::cout<< "val is not found in bst" << '\n';

    if(bst.remove(122))
    {
        std::cout << "122 is removed: \n";
        bst.display();
    }  
    else std::cout<< "val is not found in bst" << '\n';

    return 0;
}
