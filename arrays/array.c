#include <stdio.h>
#include <stdlib.h>

#include "array.h"

Array *create_array(int capacity)
{
    Array *arr = (Array *)malloc(sizeof(struct array));

    check_pointer(arr);

    arr->data = (int *)malloc(sizeof(int) * capacity);

    arr->size = 0;
    arr->capacity = capacity;

    return arr;
}

void print_array(Array *arr)
{
    printf("\n\n");
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d\n", *(arr->data + i));
    }
}

int size(Array *arr)
{
    check_pointer(arr);

    return arr->size;
}

void check_pointer(void *p)
{
    if (p == NULL)
    {
        printf("Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}

int capacity(Array *arr)
{
    check_pointer(arr);

    return arr->capacity;
}

int is_empty(Array *arr)
{
    check_pointer(arr);
    return arr->size == arr->capacity ? 1 : 0;
}

int at(Array *arr, int index)
{
    if (index < 0 || index > arr->size - 1)
    {
        exit(EXIT_FAILURE);
    }

    return *(arr->data + index);
}

bool push(Array *arr, int item)
{
    check_pointer(arr);

    resize(arr);

    *(arr->data + arr->size) = item;

    ++(arr->size);

    return true;
}

bool insert(Array *arr, int index, int item)
{
    check_pointer(arr);
    resize(arr);
    for (int i = arr->size; i >= index; i--)
    {
        int temp = *(arr->data + i);
        *(arr->data + i + 1) = temp;
    }

    *(arr->data + index) = item;
    ++(arr->size);
    return true;
}

bool prepend(Array *arr, int item)
{
    check_pointer(arr);
    if (insert(arr, 0, item))
    {
        return true;
    }

    return false;
}

bool pop(Array *arr)
{
    check_pointer(arr);
    if (arr->size == 0)
        return false;

    --(arr->size);
    return true;
}

bool delete(Array *arr, int index)
{
    if (index > arr->capacity - 1)
    {
        return false;
    }

    for (int i = index; i < arr->capacity - 1; i++)
    {
        *(arr->data + i) = *(arr->data + i + 1);
    }

    --(arr->size);

    return true;
}

bool remove_arr(Array *arr, int item)
{
    check_pointer(arr);

    if (arr->size == 0)
        return false;

    int k, i = 0;

    while (i < arr->size && *(arr->data + i) != item)
    {
        i++;
    }

    if (i == arr->size)
        return false;

    for (k = i; k < arr->capacity - 1; k++)
    {
        *(arr->data + k) = *(arr->data + k + 1);
    }

    --(arr->size);

    return true;
}

int find_arr(Array *arr, int item)
{
    int i = 0;

    while (i < arr->size && *(arr->data + i) != item)
    {
        i++;
    }

    if (i == arr->size)
        return -1;

    return *(arr->data + i);
}

void resize(Array *arr)
{
    if (arr->size == arr->capacity)
    {
        int *new_array = (int *)malloc(sizeof(int) * (2 * arr->capacity));

        for (int i = 0; i < arr->size; i++)
        {
            *(new_array + i) = *(arr->data + i);
        }

        free(arr->data);
        arr->data = new_array;

        arr->capacity = 2 * arr->capacity;
    }
}

int main()
{
    Array *arr = create_array(2);
    push(arr, 10);
    push(arr, 12);
    push(arr, 2234);
    push(arr, 23);
    push(arr, 453);
    push(arr, 88);
    push(arr, 3434);
    int a = arr->size;
    print_array(arr);

    return 0;
}