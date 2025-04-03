#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

using namespace std;

ListSeq ::ListSeq(int _capacity)
{
    data = new int[_capacity]; // new aloca na heap sempre (pilha)
    capacity = _capacity;
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
    if (pos >= 0 && pos < size) return data[pos];
    
    return -1;
}

void ListSeq::insert(int elem, int pos)
{
    if (isFull()) resize();
    for (int i = size; i> pos; i--)
    {
        data[i] = data[i - 1];
    }
    data[pos]=elem;
    size++;
}

bool ListSeq::addSorted(int elem){
    if (isFull()) resize();
    for (int i = 0; i < size; i++)
    {
        if (data[i]>elem)
        {
            insert(elem,i-1);
            return true;
        }
        
    }
    return false;
}