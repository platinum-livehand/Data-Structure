#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* initList()
{
    Node* node = (Node*)malloc(sizeof(Node));
    
    node->data = 0;
    node->next = node;

    return node; 
}

void headInsert(Node* list, int data)
{
    Node* node = (Node*)malloc(sizeof(Node));

    node->data = data;
    node->next = list->next;

    list->next = node;

    list->data++;
}

void tailInsert(Node* list, int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;

    Node* iterator = list;
    while (iterator->next != list)
    {
        iterator = iterator->next;
    }
    node->next = list;
    iterator->next = node;

    list->data++;
}

int delete(Node* list, int data)
{
    Node* iterator = list->next;
    Node* pre = list;

    while (iterator != list)
    {
        if(iterator->data == data)
        {
            pre->next = iterator->next;
            free(iterator);

            list->data--;

            return TRUE;
        }
        pre = iterator;
        iterator = iterator->next;
    }

    return FALSE;
}

void printList(Node* list)
{
    Node* iterator = list->next;
    while (iterator != list)
    {
        printf("%d->", iterator->data);
        iterator = iterator->next;
    }
    printf("NULL\n");
}

int main()
{
    Node* list = initList();
    headInsert(list, 1);
    headInsert(list, 2);
    headInsert(list, 3);
    headInsert(list, 4);
    headInsert(list, 5);
    printList(list);

    tailInsert(list, 6);
    tailInsert(list, 7);
    printList(list);

    delete(list, 5);
    delete(list, 7);
    printList(list);
    
    return 0;
}