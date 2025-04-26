#include "list.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

List::List()
{
    this->head = nullptr;
    this->tail = nullptr;
}

List::~List()
{
    Node *aux = this->head;
}

bool List::push_front(int key)
{
    Node *novo = new Node{key, nullptr, nullptr};
    if (!novo)
        return false;

    novo->next = this->head;
    this->head = novo;
    if (novo->next)
    {
        novo->next->prev = novo;
    }
    else
    {
        this->tail = novo;
    }
    return true;
}

bool List::pop_front()
{
    if (this->head)
    {
        Node *aux = this->head;
        this->head = aux->next;
        if (!this->head)
        {
            this->tail = nullptr;
        }
        delete aux;
        return true;
    }
    else
    {
        return false;
    }
}

bool List::push_back(int key)
{
    Node *aux = this->tail;
    if (!aux)
    {
        return push_front(key);
    }

    Node *novo = new Node{key, this->tail, nullptr};
    if (!novo)
        return false;

    this->tail->next = novo;
    this->tail = novo;

    return true;
}

bool List::equals(List *other)
{
    Node *auxOther = other->head;
    Node *aux = this->head;
    while (aux && auxOther)
    {
        if (aux->key != auxOther->key)
        {
            return false;
        }
        aux = aux->next;
        auxOther = auxOther->next;
    }
    return true;
}

int List::get(int pos)
{
    Node *aux = this->head;
    int n = 0;
    while (aux)
    {
        if (n == pos)
        {
            return aux->key;
        }
        aux = aux->next;
        n++;
    }
    return -1;
}

void List::print()
{
    Node *aux = this->head;
    while (aux)
    {
        cout << "->" << aux->key;
        aux = aux->next;
    }
    cout << endl;
}

int List::size()
{
    int n = 0;
    Node *aux = this->head;
    while (aux)
    {
        n++;
        aux = aux->next;
    }
    return n;
}

Node *List::find(int key)
{
    Node *aux = this->head;
    while (aux)
    {
        if (aux->key == key)
        {
            return aux;
        }
        aux = aux->next;
    }
    return nullptr;
}

void List::insert_after(int key, Node *pos)
{
    Node *aux = this->head;
    int n = 0;
    while (aux)
    {
        if (aux->key == pos->key)
        {
            insert(key, n + 1);
            break;
        }
        n++;
        aux = aux->next;
    }
}

bool List::remove_after(Node *pos)
{
    Node *aux = this->head;
    int n = 0;
    while (aux)
    {
        if (aux->key == pos->key)
        {
            return removePos(n + 1);
        }
        n++;
        aux = aux->next;
    }

    return false;
}

bool List::insert(int key, int pos)
{
    Node *novo = new Node();

    if (pos == 0)
    {
        push_front(key);
    }

    int n = 0;
    Node *aux = this->head;
    while (aux)
    {
        if (n == pos)
        {
            break;
        }
        n++;
        aux = aux->next;
    }
    novo->key = key;
    novo->prev = aux->prev;
    novo->next = aux;
    if (aux->prev)
        aux->prev->next = novo;
    aux->prev = novo;
    if (aux->next)
        aux->next->prev = novo;
    return true;
}

bool List::removePos(int pos)
{
    if (!this->head)
        return false; // Lista vazia

    Node *aux = this->head;

    // Percorre até o nó desejado
    for (int i = 0; aux && i < pos; i++)
    {
        aux = aux->next;
    }

    if (!aux)
        return false; // Caso a posição seja inválida

    // Se o nó a ser removido for o único nó
    if (aux->prev == nullptr && aux->next == nullptr)
    {
        this->head = nullptr; // A lista fica vazia
    }
    // Se o nó a ser removido for o primeiro
    else if (aux->prev == nullptr)
    {
        this->head = aux->next;
        aux->next->prev = nullptr;
    }
    // Se o nó a ser removido for o último
    else if (aux->next == nullptr)
    {
        aux->prev->next = nullptr;
    }
    // Se o nó estiver no meio
    else
    {
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
    }

    delete aux; // Libera a memória do nó removido
    return true;
}

bool List::removeKey(int key)
{
    if (!this->head)
        return false; // Lista vazia

    Node *aux = this->head;

    // Percorre a lista até encontrar o nó com a chave
    while (aux && aux->key != key)
    {
        aux = aux->next;
    }

    if (!aux)
        return false; // Se não encontrar a chave

    // Se o nó a ser removido for o único nó
    if (aux->prev == nullptr && aux->next == nullptr)
    {
        this->head = nullptr; // A lista fica vazia
    }
    // Se o nó a ser removido for o primeiro
    else if (aux->prev == nullptr)
    {
        this->head = aux->next;
        aux->next->prev = nullptr;
    }
    // Se o nó a ser removido for o último
    else if (aux->next == nullptr)
    {
        aux->prev->next = nullptr;
    }
    // Se o nó estiver no meio
    else
    {
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
    }

    delete aux; // Libera a memória do nó removido
    return true;
}

bool List::pop_back()
{
    if (!this->tail)
        return false;
    Node *aux = this->tail;
    this->tail = this->tail->prev;

    if (this->tail)
        this->tail->next = nullptr;
    else
        this->head = nullptr;

    delete aux;
    return true;
}

bool List::empty()
{
    if (this->head == nullptr)
        return true;
    return false;
}

bool List::insert_sorted(int key)
{
    if (empty())
        return push_front(key);
    Node *aux = this->head;
    int n = 0;
    while (aux)
    {
        if (aux->key < key)
        {
            insert(key, n);
            return true;
        }
        aux = aux->next;
        n++;
    }
    return false;
}

Node *List::getPos(int pos)
{
    if (pos < 0)
        return nullptr;

    Node *aux = this->head;
    for (int i = 0; i < pos; i++)
    {
        aux = aux->next;
    }

    return aux;
}

void List::print_last()
{
    Node *aux = this->head;
    while (aux->next)
    {
        aux = aux->next;
    }

    cout << "Último: " << aux->key << ".";
    cout << endl;
}

bool List::is_sorted()
{
    Node *aux = this->head;
    while (aux)
    {
        if (aux->key > aux->next->key)
        {
            return false;
        }
        aux = aux->next;
    }

    return true;
}

bool List::push_backVet(int n, int *vec)
{
    for (int i = 0; i < n; i++)
    {
        push_back(vec[i]);
    }

    return true;
}
