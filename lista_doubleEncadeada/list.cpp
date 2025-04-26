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

    Node* novo = new Node{key, this->tail, nullptr};
    if (!novo)
        return false;

    this->tail->next = novo;
    this->tail = novo;


    return true;
}

bool List::equals(List *other)
{
    Node* auxOther = other->this->head;
    Node* aux = this->head;
    while (aux && auxOther)
    {
        if(aux->key!=auxOther->key){
            return false;
        }
        aux=aux->next;
        auxOther=auxOther->next;
    }

    return true;
    
}

int List::get(int pos)
{
    if (pos==0)
    {
        return this->head->key;
    } 
    Node* aux = this->head;
    int n=0;
    while (aux)
    {
        if(n==pos){
            return aux->key;
        }

        aux=aux->next;
        n++;
    }
    return -1;
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
    if (!this->tail)
        return false;
    Node* aux = this->tail;
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
