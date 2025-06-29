#include<stdio.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct ListNode{
    struct ListNode* next;
    int value;
} Node;

/*Here, the sorted list will be used*/
int insert_value(Node** head, int val)
{
    if(head == NULL)    return FALSE;
    Node* current = *head;
    Node* previous = NULL;
    Node* newNode = NULL;

    while(current != NULL && current->value < val)
    {
        previous = current;
        current = current->next;
    }

    newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) return FALSE;
    newNode->value = val;
    newNode->next = current;

    if(previous == NULL)
        *head = newNode;
    else
        previous->next = newNode;

    return TRUE;
}

int remove_value(Node** head, int val)
{
    Node* current = *head;
    Node* previous = NULL;
    while(current != NULL && current->value != val)
    {
        previous = current;
        current = current->next;
    }
    if(current == NULL) /*val not found*/
        return FALSE;
    else
    {
        if(previous == NULL)
        {
            *head = current->next;
            free(current);
        }
        else
        {
            previous->next = current->next;
            free(current);
        }
    }
    return TRUE;
}

void print_list(Node* root)
{
    Node* current = root;
    while(current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node* root = (Node*)malloc(sizeof(Node));
    root->value = 9;
    root->next = NULL;

    int arr[5] = {13, 7, 15, 8, 6};
    for(int i = 0; i < 5; ++i)
    {
        insert_value(&root, arr[i]);
    }
    printf("List: ");
    print_list(root);

    /*insert value inside list*/
    insert_value(&root, 12);
    printf("List after first insert: ");
    print_list(root);

    /*insert value at the end*/
    insert_value(&root, 20);
    printf("List after second insert: ");
    print_list(root);

    /*insert value before head*/
    insert_value(&root, 5);
    printf("List after second insert: ");
    print_list(root);

    /*remove value inside link*/
    remove_value(&root, 13);
    printf("List after first remove: ");
    print_list(root);

    /*remove value at end of link*/
    remove_value(&root, 20);
    printf("List after second remove: ");
    print_list(root);

    /*remove value at beginning of link*/
    remove_value(&root, 5);
    printf("List after third remove: ");
    print_list(root);

    /*remove value not inside link*/
    remove_value(&root, 3);
    printf("List after forth remove: ");
    print_list(root);

    return 0;
}