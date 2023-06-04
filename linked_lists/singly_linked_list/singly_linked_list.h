#include <stdbool.h>


struct node
{
    int data;
    struct node *next;
};


typedef struct node Node;

struct singlyLinkedList
{
    int size;
    Node *head;
};

typedef struct singlyLinkedList SinglyLinkedList;

void check_pointer(void *p);
Node *create_node(int data);
SinglyLinkedList* create_singly_linked_list();
int size(SinglyLinkedList* singlyLinkedList);
bool empty(SinglyLinkedList* singlyLinkedList);
int value_at(SinglyLinkedList* singlyLinkedList, int index);
bool push_front(SinglyLinkedList* singlyLinkedList, int data);
int pop_front(SinglyLinkedList* singlyLinkedList);
bool push_back(SinglyLinkedList* singlyLinkedList, int data);
int pop_back(SinglyLinkedList* singlyLinkedList);
int front(SinglyLinkedList* singlyLinkedList);
int back(SinglyLinkedList* singlyLinkedList);
bool insert(SinglyLinkedList* singlyLinkedList, int index, int data);
bool erase(SinglyLinkedList* singlyLinkedList, int index);