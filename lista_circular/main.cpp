#include <stdio.h>
#include <iostream>
#include "list_circ.hpp"

using namespace std;

int main() {
    CircleList list;
    
    std::cout << "Inserindo elementos no início..." << std::endl;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.print(); // Esperado: 30 20 10
    
    std::cout << "Tamanho da lista: " << list.size() << std::endl; // Esperado: 3
    std::cout << "A lista está vazia? " << (list.empty() ? "Sim" : "Não") << std::endl; // Esperado: Não

    std::cout << "Removendo o primeiro elemento..." << std::endl;
    list.pop_front();
    list.print(); // Esperado: 20 10

    std::cout << "Inserindo elementos no final..." << std::endl;
    list.push_back(40);
    list.push_back(50);
    list.print(); // Esperado: 20 10 40 50

    std::cout << "Removendo o último elemento..." << std::endl;
    list.pop_back();
    list.print(); // Esperado: 20 10 40

    std::cout << "Obter elemento na posição 1: " << list.get(1) << std::endl; // Esperado: 10

    std::cout << "Procurando o nó com chave 40..." << std::endl;
    Node* node = list.find(20);
    if (node) {
        std::cout << "Nó encontrado com chave: " << node->key << std::endl; // Esperado: 40
    } else {
        std::cout << "Nó não encontrado." << std::endl;
    }

    std::cout << "Inserindo após o nó com chave 20..." << std::endl;
    list.insert_after(25, node); // Inserir 25 após o nó com chave 20
    list.print(); // Esperado: 20 25 10 40

    std::cout << "Removendo o nó após o nó com chave 20..." << std::endl;
    list.remove_after(node); // Remove o nó após o nó com chave 20 (nó com chave 25)
    list.print(); // Esperado: 20 10 40

    std::cout << "Inserindo na posição 1..." << std::endl;
    list.insert(1, 15);
    list.print(); // Esperado: 20 15 10 40

    std::cout << "Removendo o nó na posição 2..." << std::endl;
    list.remove_at(2); // Remove o nó na posição 2 (nó com chave 10)
    list.print(); // Esperado: 20 15 40

    std::cout << "Removendo o nó com chave 15..." << std::endl;
    list.remove(15);
    list.print(); // Esperado: 20 40

    std::cout << "Inserindo elementos de forma ordenada..." << std::endl;
    list.insert_sorted(30);
    list.insert_sorted(10);
    list.print(); // Esperado: 10 20 30 40

    std::cout << "Comparando listas..." << std::endl;
    CircleList otherList;
    otherList.push_back(10);
    otherList.push_back(20);
    otherList.push_back(30);
    otherList.push_back(40);    
    
    std::cout << "As listas são iguais? " << (list.equals(&otherList) ? "Sim" : "Não") << std::endl; // Esperado: Sim

    return 0;
}