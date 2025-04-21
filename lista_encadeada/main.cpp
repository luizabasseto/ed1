#include <stdio.h>
#include <iostream>
#include "linked_list.hpp"

using namespace std;

int main() {
    LinkedList list1;
    LinkedList list2;
    LinkedList list3;

    // Testando push_front
    cout << "Testando push_front:" << endl;
    list1.push_front(10);
    list1.push_front(20);
    list1.push_front(30);
    list1.print();  // Esperado: ->30->20->10

    // Testando push_back
    cout << "Testando push_back:" << endl;
    list2.push_back(100);
    list2.push_back(200);
    list2.push_back(300);
    list2.print();  // Esperado: ->100->200->300

    // Testando pop_front
    cout << "Testando pop_front:" << endl;
    list1.pop_front();
    list1.print();  // Esperado: ->20->10

    // Testando pop_back
    cout << "Testando pop_back:" << endl;
    list2.pop_back();
    list2.print();  // Esperado: ->100->200

    // Testando equals
    cout << "Testando equals:" << endl;
    LinkedList list4;
    list4.push_back(100);
    list4.push_back(300);
    cout << "List2 é igual a list4? " << (list2.equals(&list4) ? "Sim" : "Não") << endl;

    // Testando get
    cout << "Testando get:" << endl;
    cout << "Elemento na posição 1 de list1: " << list1.get(1) << endl;  // Esperado: 10

    // Testando size
    cout << "Testando size:" << endl;
    cout << "Tamanho de list1: " << list1.size() << endl;  // Esperado: 2

    // Testando find
    cout << "Testando find:" << endl;
    Node* node = list1.find(10);
    if (node) {
        cout << "Elemento 10 encontrado!" << endl;  // Esperado: "Elemento 10 encontrado!"
    } else {
        cout << "Elemento 10 não encontrado!" << endl;
    }

    // Testando insert_after
    cout << "Testando insert_after:" << endl;
    Node* node2 = list1.find(10);
    list1.insert_after(15, node2);
    list1.print();  // Esperado: ->20->10->15

    // Testando remove_after
    cout << "Testando remove_after:" << endl;
    list1.remove_after(node2);
    list1.print();  // Esperado: ->20->10

    // Testando insert
    cout << "Testando insert:" << endl;
    list1.insert(25, 1);
    list1.print();  // Esperado: ->20->25->10

    // Testando removePos
    cout << "Testando removePos:" << endl;
    list1.removePos(1);
    list1.print();  // Esperado: ->20->10

    // Testando removeKey
    cout << "Testando removeKey:" << endl;
    list1.removeKey(20);
    list1.print();  // Esperado: ->10

    // Testando empty
    cout << "Testando empty:" << endl;
    cout << "list1 está vazio? " << (list1.empty() ? "Sim" : "Não") << endl;  // Esperado: Não

    // Testando insert_sorted
    cout << "Testando insert_sorted:" << endl;
    list1.insert_sorted(5);
    list1.insert_sorted(15);
    list1.print();  // Esperado: ->5->10->15

    // Testando print_last
    cout << "Testando print_last:" << endl;
    list1.print_last();  // Esperado: Último: 15.

    // Testando is_sorted
    cout << "Testando is_sorted:" << endl;
    cout << "list1 está ordenada? " << (list1.is_sorted() ? "Sim" : "Não") << endl;  // Esperado: Sim

    // Testando push_backVet
    cout << "Testando push_backVet:" << endl;
    int arr[] = {1, 2, 3};
    list2.push_backVet(3, arr);
    list2.print();  // Esperado: ->100->200->1->2->3

    // Testando deep_copy
    cout << "Testando deep_copy:" << endl;
    LinkedList* listCopy = list2.deep_copy();
    listCopy->print();  // Esperado: ->100->200->1->2->3

    // Testando concat
    cout << "Testando concat:" << endl;
    LinkedList* listConcat = list1.concat(&list2);
    listConcat->print();  // Esperado: ->5->10->15->100->200->1->2->3

    // Testando merge
    cout << "Testando merge:" << endl;
    list1.sorted();
    list2.sorted();
    LinkedList* listMerge = list1.merge(&list2);
    listMerge->print();  // Esperado: ->5->10->15->1->2->3->100->200

    return 0;
}