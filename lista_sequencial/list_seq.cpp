#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

using namespace std;

ListSeq ::ListSeq(int _capacity)
{
    data = new int[_capacity]; // new aloca na heap sempre (pilha)
    capacity = _capacity;
    size = 0;
};

bool ListSeq ::add(int elem)
{
    if (size < capacity)
    {
        data[size++] = elem;
        return true;
    }
    else
    {
        return false;
    }
};

bool ListSeq ::isEmpty()
{
    return size == 0;
}
bool ListSeq ::isFull()
{
    return size == capacity;
}

void ListSeq::destroy()
{
    delete[] data;
}

bool ListSeq ::resize()
{
    int *_data = new int[++capacity];
    for (int i = 0; i < size; i++)
    {
        _data[i] = data[i];
    }

    destroy();
    data = _data;

    return true;
}

bool ListSeq ::print()
{

    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}

void ListSeq::remove()
{
    if (!isEmpty())
    {
        size--;
    }
}

void ListSeq::removeAt(int pos)
{
    if (pos < size)
    {
        for (int i = pos; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }
}

int ListSeq::find(int elem)
{
    for (int i = 0; i < size; i++)
    {
        if (elem == data[i])
        {
            return i;
        }
    }
    return -1;
}

int ListSeq::get(int pos)
{
    if (pos >= 0 && pos < size)
        return data[pos];

    return -1;
}

void ListSeq::insert(int elem, int pos)
{
    if (isFull())
        resize();
    for (int i = size; i > pos; i--)
    {
        data[i] = data[i - 1];
    }
    data[pos] = elem;
    size++;
}

bool ListSeq::addSorted(int elem)
{
    if (isFull())
        resize();
    for (int i = 0; i < size; i++)
    {
        if (data[i] > elem)
        {
            insert(elem, i);
            return true;
        }
    }
    return false;
}

int ListSeq::list_get_available()
{
    if (isFull())
        return 0;
    if (isEmpty())
        return capacity;

    return capacity - size;
}

void ListSeq::list_clear()
{
    while (!isEmpty())
    {
        removeAt(0);
    }
}

void ListSeq::list_remove_last(int n)
{
    if (n <= size - 1)
    {
        for (int i = 0; i < n; i++)
        {
            remove();
        }
    }
}

void ListSeq::list_print_reverse()
{
    for (int i = size - 1; i >= 0; i--)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

void ListSeq::list_add(int n, int *vet)
{
    for (int i = 0; i < n; i++)
    {
        if (isFull())
            break;
        add(vet[i]);
    }
}

bool ListSeq::list_is_sorted()
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] > data[i + 1])
            return false;
    }
    return true;
}

void ListSeq::list_reverse()
{
    ListSeq *aux = new ListSeq(capacity);
    for (int i = size - 1; i >= 0; i--)
    {
        aux->add(data[i]);
    }
    for (int i = 0; i < size; i++)
    {
        data[i] = aux->data[i];
    }
    aux->destroy();
}

bool ListSeq::list_equal(ListSeq *outra)
{

    if (outra->capacity != capacity)
        return false;
    if (outra->size != size)
        return false;
    for (int i = 0; i < size; i++)
    {
        if (outra->data[i] != data[i])
        {
            return false;
        }
    }
    return true;
}

ListSeq* ListSeq::list_from_vector(int n, int *vet)
{
    ListSeq* newList = new ListSeq(n * 2);

    for (int i = 0; i < n; i++)
    {
        newList->add(vet[i]);
    }

    return newList;
}

ListSeq* ListSeq::list_copy()
{
    ListSeq* newList = new ListSeq (capacity);
    for (int i = 0; i < size; i++)
    {
        newList->add(data[i]);
    }

    return newList;
}

int ListSeq::list_concat(ListSeq *list2)
{
    int n = 0;
    if (isFull())
        return n;

    for (int i = 0; i < list2->size; i++)
    {
        if (isFull())
            break;
        data[size++] = list2->data[i];
        n++;
    }

    return n;
}