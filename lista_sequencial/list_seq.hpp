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

    void insert(int elem, int pos); //feito

    void removeAt(int pos); //feito

    bool addSorted(int elem); //feito

    int list_get_available(); //feito

    void list_clear(); //feito

    void list_remove_last(int n); //feito

    void list_print_reverse(); //feito

    void list_add(int n, int* vet); //feito

    bool list_is_sorted(); //feito

    void list_reverse(); //feito

    bool list_equal(ListSeq* outra); //feito

    ListSeq* list_from_vector(int n, int* vet); //feito

    ListSeq* list_copy(); //feito

    int list_concat(ListSeq* list2); //feito

};

