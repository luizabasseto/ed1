#include "list.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

List::List()
{
    this->head = nullptr;
    this->tail = nullptr;
}

List::~List() {
    Node* aux = this->head;

    
}

bool List::push_front(int key)
{
    Node *novo = new Node{key, nullptr,nullptr};
    if (!node)
        return false;

    novo->next = this->head;
    this->head = novo;
    if (novo->next)
    {
        novo->next->prev = novo;
    } else{
        this->tail = node;
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
     Node *aux = this->head;
    if (!aux)
    {
        return push_front(key);
    }
    while (aux->next)
    {
        aux = aux->next;
    }

    Node *novo = new Node{key, nullptr};
    if (!novo)
        return false;

    aux->next = novo;

    return true;
}

bool List::equals(List *other)
{
}

int List::get(int pos)
{
}

void List::print()
{
}

int List::size()
{
}

Node *List::find(int key)
{
}

void List::insert_after(int key, Node *pos)
{ // após find
}

bool List::remove_after(Node *pos)
{
}

bool List::insert(int key, int pos)
{
}

bool List::removePos(int pos)
{
}

bool List::removeKey(int key)
{
}

bool List::pop_back()
{
    if (!this->head)
        return false;
    if (!this->head->next)
    {
        delete this->head;
        this->head = nullptr;
        return true;
    }
    Node *prev = nullptr;
    Node *curr = this->head;
    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
    }
    delete curr;
    prev->next = nullptr;
    return true;
}

bool List::empty()
{
    if (this->head == nullptr)
        return true;
}

bool List::insert_sorted(int key)
{
    if (empty())
        push_front(key);
    Node *aux = this->head;
    int n = 0;
    while (aux)
    {
        if (aux->key > key)
        {
            insert(key, n - 1);
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
        aux = aux->next
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
