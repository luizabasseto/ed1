#include "linked_list.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
    this->head = nullptr;
}

LinkedList::~LinkedList() {}

bool LinkedList::push_front(int key)
{
    Node *node = new Node{key, nullptr};
    if (!node)
        return false;

    node->next = this->head;
    this->head = node;
    return true;
}

bool LinkedList::pop_front()
{
    if (this->head)
    {
        Node *aux = this->head;
        this->head = aux->next;
        delete aux;
        return true;
    }
    else
    {
        return false;
    }
}

bool LinkedList::push_back(int key)
{
    Node *aux = this->head;
    int siz = size();
    for (int i = 0; i < siz - 1; i++)
    {
        aux = aux->next;
    }
    Node *novo = new Node{key, aux->next};
    if(!novo) return false;

    aux->next = novo;
    novo->next = nullptr;
    return true;
}

bool LinkedList::equals(LinkedList *other)
{
    Node *a1 = this->head;
    Node *a2 = other->head;
    while (a1 && a2)
    {
        if (a1->key == a2->key)
        {
            a1 = a1->next;
            a2 = a2->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int LinkedList::get(int pos)
{
    int siz = size();
    if (pos == siz - 1)
        return 0;
    Node* aux = this-> head;
    for (int i = 0; i < siz; i++)
    {
        aux = aux->next;
        if(i==pos){
            break;
        }
    }

    if(!aux) return -1;

    return aux->key;
}

void LinkedList::print()
{
    Node *node = this->head;
    while (node)
    {
        cout << "->" << node->key;
        node = node->next;
    }
}

int LinkedList::size()
{
    int n = 0;
    Node *aux = this->head;
    while (aux)
    {
        aux = aux->next;
        n++;
    }

    return n;
}

Node *LinkedList::find(int key)
{
    int siz =size();
    Node* aux= this->head;
    for (int i = 0; i < siz; i++)
    {
        aux=aux->next;
        if(aux->key == key){
            return aux;
        }
    }
    
    if(!aux)return nullptr;
}

void LinkedList::insert_after(int key, Node *pos)
{ // após find
    Node *novo = new Node{key, pos->next};
    pos->next = novo;
}

bool LinkedList::remove_after(Node *pos)
{
    return true;
}

bool LinkedList::insert(int key, int pos)
{
    if (pos == 0)
        return this->push_front(key);
    Node *aux = this->head;
    for (int i = 0; i < pos - 1 && aux; i++)
    {
        aux = aux->next;
    }
    if (!aux)
        return false;

    Node *novo = new Node{key, aux->next};
    aux->next = novo;
    return true;
}

bool LinkedList::remove(int pos)
{
    return true;
}

bool LinkedList::remove(int key)
{
    return true;
}

bool LinkedList::pop_back()
{
    if (empty)
        return false;

    return true;
}

bool LinkedList::empty()
{
    if (this->head = nullptr)
        return true;
}