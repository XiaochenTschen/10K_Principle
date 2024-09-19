#include<iostream>
enum Color
{
    RED,
    BLACK
};

struct Node
{
    int key;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val = 0) : key(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBTree
{
public:

private:
    Node* root;

    Node* findMin(Node* root){
        if(root == nullptr) return nullptr;
        Node* cur = root;
        while(cur->left){
            cur = cur->left;
        }
        return cur;
    }

    Node* findMax(Node* root){
        if(root == nullptr) return nullptr;
        Node* cur = root;
        while(cur->right){
            cur = cur->right;
        }
        return cur;
    }

    Node* contains(Node* root, int val){
        if(root == nullptr) return nullptr;
        if(root->key > val) return contains(root->left, val);
        else if(root->key < val)    return contains(root->right, val);
        else return root;
    }

    void* printInOrder(Node* root){
        if(root == nullptr) return;
        printInOrder(root->left);
        std::cout << root->key << " ";
        printInOrder(root->right);
    }

    Node* insertNode(Node* root, Node* node){
        if(root == nullptr){
            return node;
        }
        if(root->key > node->key){
            root->left = insertNode(root->left, node);
            root->left->parent = root;
        }
        if(root->key < node->key){
            root->right = insertNode(root->right, node);
            root->right->parent = root;
        }
        return root;

    }

    Node* insert(int val){
        Node* newNode = new Node(val);
        newNode->color = RED;
        root = insertNode(root, newNode);

        adjustTree(root);
    }

    Node* remove(int val){}

    Node* leftRotate(Node* node){
        Node* tmp = node->right;

        node->right = tmp->left;
        if(tmp->left)   tmp->left->parent = node;

        tmp->left = node;
        if(node->parent == nullptr)/*if node is root*/
        {
            this->root = tmp;
            tmp->parent = nullptr;
            tmp->color = BLACK;
        }
        else
        {
            if(node == node->parent->left)  node->parent->left = tmp;
            else node->parent->right = tmp;
            tmp->parent = node->parent;
            node->parent = tmp;
        }

        return tmp;
    }

    Node* rightRotate(Node* node){
        Node* tmp = node->left;

        node->left= tmp->right;
        if(tmp->right)  tmp->right->parent = node;

        tmp->right = node;
        tmp->parent = node->parent;
        if(node->parent == nullptr)
        {
            this->root = tmp;
            tmp->color = BLACK;
        }
        else
        {
            if(node = node->parent->left)   node->parent->left = tmp;
            else node->parent->right = tmp;
        }
        node->parent = tmp;

        return tmp;
    }

    void adjustTree(Node* node){
        if(node == root){
            node->color = BLACK;
            return;
        }

        Node* parent = node->parent;
        Node* grandParent = parent->parent;
        Node* uncle = grandParent?(grandParent->left == parent? grandParent->right:grandParent->left):nullptr;
        
        if(parent->color == RED)
        {
            if(uncle && uncle->color == RED){
            /*case1*/
                parent->color = BLACK;
                uncle->color = BLACK;
                grandParent->color = RED;
                adjustTree(grandParent);
            }
            else
            {
                if(parent == grandParent->left)
                {
                    if(node = parent->right)
                    {
                        /*case2: left-right*/
                        leftRotate(parent);
                        adjustTree(parent); /*now parent changed to be child of node*/
                    }
                    else
                    {
                        /*case3: left-left*/
                        rightRotate(grandParent);
                        parent->color = RED;
                        grandParent->color = BLACK;
                    }
                }
                else
                {
                    if(node = parent->left)
                    {
                        /*mirror of case2:right-left*/
                        rightRotate(parent);
                        adjustTree(parent);
                    }
                    else
                    {
                        /*mirror of case3: right-right*/
                        leftRotate(grandParent);
                        parent->color = BLACK;
                        grandParent->color = RED;

                    }
                }
            }
        }
    }

    void makeEmpty(Node* root){
        if(root == nullptr) return;
        makeEmpty(root->left);
        makeEmpty(root->right);
        delete root;
    }
};
