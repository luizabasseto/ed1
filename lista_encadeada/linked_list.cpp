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
    return true;
}

bool LinkedList::equals(LinkedList *other)
{
    Node* a1 = this-> head;
    Node* a2 = other-> head;
    while(a1 && a2){
        if(a1->key == a2->key){
            a1 = a1->next;
            a2 = a2->next;
        } else{
            return false;
        }
    }
    return true;
}

int LinkedList::get(int pos)
{
    return 0;
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
    return nullptr;
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
    if (pos <= this->size())
    {
        Node *aux = new Node{key, nullptr};
        for (int i = 0; i <= pos; i++)
        {
            aux = aux->next;
        }

        Node *novo = new Node{key, aux->next};
        aux->next = novo;
        return true;
    }
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
    return true;
}