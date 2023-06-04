#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

void check_pointer(void *p)
{
    if (p == NULL)
    {
        printf("Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}

Node *create_node(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    check_pointer(node);

    node->data = data;
    node->next = NULL;

    return node;
}

SinglyLinkedList *create_singly_linked_list()
{
    SinglyLinkedList *singlyLinkedList = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
    check_pointer(singlyLinkedList);
    singlyLinkedList->head = NULL;
    singlyLinkedList->size = 0;

    return singlyLinkedList;
}

int size(SinglyLinkedList *singlyLinkedList)
{
    check_pointer(singlyLinkedList);
    return singlyLinkedList->size;
}

bool empty(SinglyLinkedList *singlyLinkedList)
{
    check_pointer(singlyLinkedList);

    return singlyLinkedList->head == NULL ? true : false;
}

int value_at(SinglyLinkedList *singlyLinkedList, int index)
{
    check_pointer(singlyLinkedList);

    if (index > singlyLinkedList->size - 1)
    {
        return -1;
    }

    int count = 0;
    Node *node = singlyLinkedList->head;
    while (node != NULL)
    {
        if (count == index)
        {
            return node->data;
        }

        count++;

        node = node->next;
    }
}

bool push_front(SinglyLinkedList *singlyLinkedList, int data)
{
    check_pointer(singlyLinkedList);

    if (empty(singlyLinkedList))
    {
        Node *node = create_node(data);
        check_pointer(node);
        singlyLinkedList->head = node;
    }
    else
    {
        Node *node = create_node(data);
        check_pointer(node);
        Node *temp = singlyLinkedList->head;
        singlyLinkedList->head = node;
        node->next = temp;
    }

    singlyLinkedList->size++;
}

int pop_front(SinglyLinkedList *singlyLinkedList)
{
    check_pointer(singlyLinkedList);

    if (empty(singlyLinkedList))
    {
        return -1;
    }

    Node *node = singlyLinkedList->head;

    singlyLinkedList->head = node->next;

    int temp = node->data;
    free(node);
    singlyLinkedList->size--;
    return temp;
}

bool push_back(SinglyLinkedList *singlyLinkedList, int data)
{
    check_pointer(singlyLinkedList);

    if (empty(singlyLinkedList))
    {
        push_front(singlyLinkedList, data);
        return true;
    }

    Node *node = singlyLinkedList->head;

    while (node->next != NULL)
    {
        node = node->next;
    }

    Node *new_node = create_node(data);

    check_pointer(new_node);

    node->next = new_node;
    singlyLinkedList->size++;

    return true;
}

int pop_back(SinglyLinkedList *singlyLinkedList)
{
    check_pointer(singlyLinkedList);

    if (empty(singlyLinkedList))
    {
        return -1;
    }

    Node *prev_node, *node = singlyLinkedList->head;

    while (node->next != NULL)
    {
        prev_node = node;
        node = node->next;
    }

    if (node == singlyLinkedList->head)
    {
        singlyLinkedList->head = node->next;
        int temp = node->data;
        return temp;
    }

    int temp = node->data;

    free(node);

    prev_node->next = NULL;

    singlyLinkedList->size--;

    return temp;
}

int front(SinglyLinkedList *singlyLinkedList)
{
    check_pointer(singlyLinkedList);

    if (empty(singlyLinkedList))
    {
        return -1;
    }

    return singlyLinkedList->head->data;
}

int back(SinglyLinkedList *singlyLinkedList)
{
    check_pointer(singlyLinkedList);

    if (empty(singlyLinkedList))
    {
        return -1;
    }

    Node *node = singlyLinkedList->head;

    while (node->next != NULL)
    {
        node = node->next;
    }

    if (node == NULL)
    {
        return -1;
    }

    return node->data;
}

bool insert(SinglyLinkedList *singlyLinkedList, int index, int data)
{
    check_pointer(singlyLinkedList);

    if (empty(singlyLinkedList))
    {
        push_front(singlyLinkedList, data);
        return true;
    }

    int count = -1;

    Node *prev_node, *node = singlyLinkedList->head;

    while (node->next != NULL)
    {
        count++;
        if (count == index)
        {
            break;
        }

        prev_node = node;
        node = node->next;
    }

    Node *new_node = create_node(data);

    prev_node->next = new_node;
    new_node->next = node;

    singlyLinkedList->size++;
    return true;
}

bool erase(SinglyLinkedList *singlyLinkedList, int index)
{
    check_pointer(singlyLinkedList);

    if (index < 0 || index >= singlyLinkedList->size)
    {
        return false;
    }

    if (empty(singlyLinkedList))
    {
        return false;
    }

    if (singlyLinkedList->size == 1)
    {
        Node *node = singlyLinkedList->head;
        free(node);
        singlyLinkedList->head = NULL;
        singlyLinkedList->size--;
        return true;
    }

    int count = -1;

    Node *prev_node, *node = singlyLinkedList->head;

    while (node->next != NULL)
    {
        count++;
        if (count == index)
        {
            break;
        }

        prev_node = node;
        node = node->next;
    }

    prev_node->next = node->next;
    free(node);
    singlyLinkedList->size--;
    return true;
}

int main()
{
    SinglyLinkedList *singlyLinkedList = create_singly_linked_list();
    push_back(singlyLinkedList, 24);
    push_back(singlyLinkedList, 89);
    push_back(singlyLinkedList, 37);
    push_back(singlyLinkedList, 845);
    push_back(singlyLinkedList, 234);
    push_back(singlyLinkedList, 99);
    push_back(singlyLinkedList, 150);
    insert(singlyLinkedList, 6, 300);

    erase(singlyLinkedList, 3);
    return 0;
}