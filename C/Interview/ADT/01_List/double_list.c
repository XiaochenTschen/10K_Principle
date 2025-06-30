#include<stdio.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE  1

typedef struct ListNode{
    int value;
    struct ListNode* previous;
    struct ListNode* next;
}Node;

/*
 * root node:
 * root.next is head node
 * root.previous is tail node
 */
int insert_value(Node* root, int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
        return FALSE;
    newNode->value = val;

    /*If list is empty*/
    if(root->next == NULL && root->previous == NULL)
    {
        root->next = newNode;
        root->previous = newNode;
        newNode->next = NULL;
        newNode->previous = NULL;
    }
    else /*list is not empty*/
    {
        Node* current = root->next;
        /*val is the smallest*/
        if(current->value > val)
        {
            root->next = newNode;
            newNode->next = current;
            newNode->previous = NULL;
            current->previous = newNode;
        }
        else
        {
            Node* previous = NULL;
            while(current->value < val && current->next != NULL)
            {
                previous = current;
                current = current->next;
            }
            /*if val is the biggest*/
            if(current->next == NULL)
            {
                current->next = newNode;
                newNode->previous = current;
                newNode->next = NULL;
                root->previous = newNode;
            }
            else /*val is inside the list*/
            {
                current->previous = newNode;
                previous->next = newNode;
                newNode->next = current;
                newNode->previous = previous;
            }
        }
    }
    return TRUE;
}

void print_list_forward(Node* root)
{
    Node* current = root->next;
    while(current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void print_list_backword(Node* root)
{
    Node* current = root->previous;
    while(current != NULL)
    {
        printf("%d ", current->value);
        current = current->previous;
    }
    printf("\n");
}

int main()
{
    Node* root = (Node*)malloc(sizeof(Node));
    root->next = NULL;
    root->previous = NULL;

    int arr[5] = {7, 13, 4, 17, 9};
    for(int i = 0; i < 5; ++i)
    {
        insert_value(root, arr[i]);
    }

    print_list_forward(root);
    print_list_backword(root);
    
    return 0;
}