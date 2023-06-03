#include <stdbool.h>

typedef struct array
{
    int size;
    int capacity;
    int *data;
} Array;

Array *create_array(int capacity);
void print_array(Array *arr);
int size(Array *arr);
void check_pointer(void *p);
int capacity(Array *arr);
int is_empty(Array *arr);
int at(Array *arr, int index);
bool push(Array *arr, int item);
bool insert(Array *arr, int index, int item);
bool prepend(Array *arr, int item);
bool pop(Array *arr);
bool delete(Array *arr, int index);
bool remove_arr(Array *arr, int item);
int find_arr(Array *arr, int item);
void resize(Array *arr);

