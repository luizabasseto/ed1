#include <stdio.h>
#include <iostream>
#include "list.hpp"

using namespace std;

int main() {
    List list;

    cout << "Inserindo no início (push_front):\n";
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.print();

    cout << "\nInserindo no final (push_back):\n";
    list.push_back(5);
    list.push_back(0);
    list.print();

    cout << "\nRemovendo do início (pop_front):\n";
    list.pop_front();
    list.print();

    cout << "\nRemovendo do final (pop_back):\n";
    list.pop_back();
    list.print();

    cout << "\nInserindo ordenado (insert_sorted):\n";
    list.insert_sorted(15);
    list.insert_sorted(25);
    list.print();

    cout << "\nRemovendo posição 1 (removePos(1)):\n";
    list.removePos(1);
    list.print();

    cout << "\nRemovendo pela chave (removeKey(15)):\n";
    list.removeKey(15);
    list.print();

  /*  cout << "\nInserindo depois do primeiro nó (insert_after):\n";
    Node* first = list.getPos(0);
    list.insert_after(35, first);
    list.print();

    cout << "\nRemovendo depois do primeiro nó (remove_after):\n";
    list.remove_after(first);
    list.print();

    cout << "\nTestando se a lista está ordenada (is_sorted): ";
    cout << (list.is_sorted() ? "Sim" : "Não") << endl;

    cout << "\nPrint do último elemento (print_last):\n";
    list.print_last();

    cout << "\nInserindo vários elementos de um vetor (push_backVet):\n";
    int v[] = {100, 200, 300};
    list.push_backVet(3, v);
    list.print();

    cout << "\nLimpando lista com destrutor (fim do main)\n";*/
}