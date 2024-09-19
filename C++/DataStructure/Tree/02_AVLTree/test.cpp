#include<string>

struct Node
{
    int key;
    Node* left;
    Node* right;
    int height;

    Node(): key(0), left(nullptr), right(nullptr) {}
    Node(int x): key(x), left(nullptr), right(nullptr) {}
};

class AVL
{
public:
    AVL() : root(nullptr) {}
    ~AVL(){
        makeEmpty(root);
    }

    void insert(int val){
        insert(root, val);
    }

    void remove() {}

    bool contains(int val) {
        return contains(root, val);
    }

    int max() {
        Node* cur = root;
        while(cur->right)
        {
            cur = cur->right;
        }
        return cur->key;
    }

    int min() {
        Node* cur = root;
        while(cur->left)
        {
            cur = cur->left;
        }
        return cur->key;
    }


private:
    Node* root;

    void makeEmpty(Node* node){
        if(node != nullptr)
        {
            makeEmpty(node->left);
            makeEmpty(node->right);
            delete node;
        }
        node = nullptr;
    }

    void insert(Node*& root, int val)
    {
        if(root == nullptr)
        {
            root = new Node(val);
        }
        else if(root->key > val)
        {
            insert(root->left, val);
        }
        else if(root->key < val)
        {
            insert(root->right, val);
        }
        else /*No equal keys*/
            return;
        
        /*Update height information*/
        root->height = 1 + std::max(height(root->left), height(root->right));

        /*Get balance factor*/
        int balance = getBalance(root);

        /*4 unbalance cases*/

        /*left-left case*/
        if(balance > 1 && val < root->left->key) {
            rightRotate(root);
        }

        /*left-right case*/
        if(balance > 1 && val > root->left->key) {
            leftRotate(root->left);
            rightRotate(root);
        }

        /*right-left case*/
        if(balance < -1 && val < root->right->key) {
            rightRotate(root->right);
            leftRotate(root);
        }

        /*right-right case*/
        if(balance < -1 && val > root->right->key) {
            leftRotate(root);
        }

    }

    void remove(Node*& node, int val)
    {
        if(node == nullptr) return;
        if(node->key > val) 
            remove(node->left, val);
        else if(node->key < val)
            remove(node->right, val);
        else
        {
            /*node has no or only one child*/
            if(node->left == nullptr || node->right == nullptr)
            {
                Node* tmp = node->left?node->left:node->right;
                if(tmp == nullptr)/*no child*/
                {
                    tmp = node;
                    node = nullptr;
                }
                else /*one child*/
                    *node = *tmp;
                delete tmp;
            }
            /*node has two children*/
            else
            {
                Node* nodeToDelete = findMin(node->right);
                node->key = nodeToDelete->key;
                remove(node->right, nodeToDelete->key);
            }
        }

        if(node == nullptr) return;
        /*update height information*/
        node->height = 1 + std::max(height(node->left),height(node->right));
        /*get balance factor*/
        int balance = getBalance(node);
        /*4 unblanced condition*/
        /*left-left*/
        if(balance > 1 && getBalance(root->left) > 0)
            rightRotate(node);
        /*left-right*/
        if(balance > 1 && getBalance(root->left) < 0)
        {
            leftRotate(node->left);
            rightRotate(node);
        }
        /*right-right*/
        if(balance < -1 && getBalance(root->right) < 0)
            leftRotate(node);
        /*right-left*/
        if(balance < -1 && getBalance(root->right) > 0)
        {
            rightRotate(node->right);
            leftRotate(node);
        }
    }

    Node* findMin(Node* root)
    {
        if(root == nullptr) return nullptr;
        Node* cur = root;
        while(cur->left)
        {
            cur = cur->left;
        }
        return cur;
    }

    Node* findMax(Node* root)
    {
        if(root == nullptr) return nullptr;
        Node* cur = root;
        while(cur->right)
        {
            cur = cur->right;
        }
        return cur;
    }

    int height(Node* node)
    {
        if(node == nullptr) return 0;
        return node->height;
    }

    int getBalance(Node* node)
    {
        if(node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    void rightRotate(Node*& x)
    {
        Node* y = x->left;
        Node* T2 = y->right;

        /*Rotation*/
        y->right = x;
        x->left = T2;

        /*Update height information*/
        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        /*Update reference*/
        x = y;
    }

    void leftRotate(Node*& x)
    {
        Node* y = x->right;
        Node* T1 = y->left;

        /*Rotation*/
        y->left = x;
        x->right = T1;

        /*Update height information*/
        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        /*Update reference*/
        x = y;
    }

    bool contains(Node* node, int val)
    {
        if(node == nullptr)     return false;
        if(node->key == val)    return true;
        else if(node->key > val)   return contains(node->left, val);
        else    return(node->right, val);
    }
};