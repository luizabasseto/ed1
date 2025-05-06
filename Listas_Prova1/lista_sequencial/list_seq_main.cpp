#include <iostream>
#include <algorithm>
#include "list_seq.hpp"

using namespace std;

int main()
{
    ListSeq list(5);

    // Testando a função add
    cout << "Adicionando elementos na lista:" << endl;
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);
    list.add(60); // Não será adicionado pois a lista está cheia
    list.print();

    // Testando a função isFull
    cout << "A lista está cheia? " << (list.isFull() ? "Sim" : "Não") << endl;

    // Testando a função remove
    cout << "Removendo o último elemento:" << endl;
    list.remove();
    list.print();

    // Testando a função removeAt
    cout << "Removendo o elemento na posição 2:" << endl;
    list.removeAt(2);
    list.print();

    // Testando a função find
    cout << "Procurando o elemento 20 na lista: Índice " << list.find(20) << endl;
    cout << "Procurando o elemento 99 na lista: Índice " << list.find(99) << endl;

    // Testando a função insert
    cout << "Inserindo 25 na posição 2:" << endl;
    list.insert(25, 2);
    list.print();

    // Testando a função addSorted
    cout << "Adicionando 35 de forma ordenada:" << endl;
    list.addSorted(35);
    list.print();

    // Testando a função list_get_available
    cout << "Espaço disponível na lista: " << list.list_get_available() << endl;

    // Testando a função list_clear
    cout << "Limpando a lista:" << endl;
    list.list_clear();
    list.print();

    // Testando a função list_add
    int vet[] = {10, 20, 30};
    cout << "Adicionando um vetor de elementos:" << endl;
    list.list_add(3, vet);
    list.print();

    // Testando a função list_is_sorted
    cout << "A lista está ordenada? " << (list.list_is_sorted() ? "Sim" : "Não") << endl;

    // Testando a função list_reverse
    cout << "Invertendo a lista:" << endl;
    list.list_reverse();
    list.print();

    // Testando a função list_equal
    ListSeq list2(5);
    list2.list_add(3, vet);
    list.list_reverse();
    cout << "As duas listas são iguais? " << (list.list_equal(&list2) ? "Sim" : "Não") << endl;

    // Testando a função list_from_vector
    cout << "Criando uma lista a partir de um vetor:" << endl;
    ListSeq* newList = list.list_from_vector(3, vet);
    newList->print();

    // Testando a função list_copy
    cout << "Copiando a lista:" << endl;
    ListSeq* copiedList = list.list_copy();
    copiedList->print();

    // Testando a função list_concat
    int vet2[] = {40, 50, 60};
    ListSeq list3(10);
    list3.list_add(3, vet2);
    cout << "Concatenando a lista 3 à lista original:" << endl;
    list.list_concat(&list3);
    list.print();

    // Limpando a memória dos ponteiros dinâmicos
    delete newList;
    delete copiedList;

    return 0;
}