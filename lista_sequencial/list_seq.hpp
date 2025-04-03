#include <iostream>

using namespace std;

class ListSeq
{

public:
    int size = 0;
    int capacity;
    int *data;

    ListSeq(int _capacity);

    void destroy(); //feito

    bool resize(); //feito

    bool print(); //feito

    int find(int elem); //feito

    int get(int pos); //feito

    bool isEmpty(); //feito

    bool isFull(); //feito

    bool add(int elem); //feito

    void remove(); //feito

    void insert(int elem, int pos);

    void removeAt(int pos);

    bool addSorted(int elem);

};