#include <iostream>

using namespace std;

class ListSeq
{

public:
    int size = 0;
    int capacity;
    int *data;

    ListSeq(int _capacity);
    void destroy();

    bool resize();

    bool print();

    int find(int elem);

    int get(int pos);

    bool isEmpty();

    bool isFull();

    bool add(int elem);

    bool remove();

    void insert(int elem, int pos);

    bool removeAt(int pos);

    bool addSorted(int elem);
};