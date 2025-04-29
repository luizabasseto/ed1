#include <iostream>
#include "list_doubleCirc.hpp"

using namespace std;

int main() {
    CircleDoubleList list;

    cout << "Inserindo elementos no início..." << endl;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.print(); // Esperado: 30 20 10

    cout << "Tamanho da lista: " << list.size() << endl; // Esperado: 3
    cout << "A lista está vazia? " << (list.empty() ? "Sim" : "Não") << endl; // Esperado: Não

    cout << "\nRemovendo o primeiro elemento..." << endl;
    list.pop_front();
    list.print(); // Esperado: 20 10

    cout << "\nInserindo elementos no final..." << endl;
    list.push_back(40);
    list.push_back(50);
    list.print(); // Esperado: 20 10 40 50

    cout << "\nRemovendo o último elemento..." << endl;
    list.pop_back();
    list.print(); // Esperado: 20 10 40

    cout << "\nObter elemento na posição 1: " << list.get(1) << endl; // Esperado: 10

    cout << "\nProcurando o nó com chave 20..." << endl;
    Node* node = list.find(20);
    if (node) {
        cout << "Nó encontrado com chave: " << node->key << endl; // Esperado: 20
    } else {
        cout << "Nó não encontrado." << endl;
    }

    cout << "\nInserindo após o nó com chave 20..." << endl;
    list.insert_after(25, node);
    list.print(); // Esperado: 20 25 10 40

    cout << "\nRemovendo o nó após o nó com chave 20..." << endl;
    list.remove_after(node); // Remove o 25
    list.print(); // Esperado: 20 10 40

    cout << "\nInserindo na posição 1..." << endl;
    list.insert(1, 15);
    list.print(); // Esperado: 20 15 10 40

    cout << "\nRemovendo o nó na posição 2..." << endl;
    list.remove_at(2); // Remove 10
    list.print(); // Esperado: 20 15 40

    cout << "\nRemovendo o nó com chave 15..." << endl;
    list.remove(15);
    list.print(); // Esperado: 20 40

    cout << "\nInserindo elementos de forma ordenada..." << endl;
    list.insert_sorted(30);
    list.insert_sorted(10);
    list.print(); // Esperado: 10 20 30 40

    cout << "\nComparando listas..." << endl;
    CircleDoubleList otherList;
    otherList.push_back(10);
    otherList.push_back(20);
    otherList.push_back(30);
    otherList.push_back(40);
    cout << "As listas são iguais? " << (list.equals(&otherList) ? "Sim" : "Não") << endl; // Esperado: Sim

    return 0;
}
