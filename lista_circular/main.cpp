#include <stdio.h>
#include "list.hpp"

int main() {
    List* list1 = new List();

    list1->push_front(3);
    list1->push_front(8);
    list1->push_front(2);
    list1->push_front(5);  // Lista: 5 -> 2 -> 8 -> 3

    printf("Lista inicial:\n");
    list1->print();

    list1->pop_front();  // Remove 5
    printf("Após pop_front:\n");
    list1->print();

    list1->insert(2, 3);  // Insere 2 na posição 3 (depois do 3)
    printf("Após insert(2, 3):\n");
    list1->print();

    list1->pop_back();  // Remove último
    printf("Após pop_back:\n");
    list1->print();

    delete list1;
}