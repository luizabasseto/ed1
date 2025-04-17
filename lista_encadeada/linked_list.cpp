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
    if (pos >= siz)
        return -1;

    Node *aux = this->head;
    for (int i = 0; i < pos; i++)
    {
        aux = aux->next;
    }

    return aux ? aux->key : -1;
}

void LinkedList::print()
{
    Node *node = this->head;
    while (node)
    {
        cout << "->" << node->key;
        node = node->next;
    }
    cout << endl;
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

Node* LinkedList::find(int key){
     if (this->head == nullptr) {
        return nullptr;  
    }
    Node *aux = this->head;
    while(aux){
        if (aux->key == key)
        {
            return aux;
        }
        aux = aux->next;
    }
    return nullptr;
}

void LinkedList::insert_after(int key, Node *pos){ // após find
    if (!pos)
        return;
    Node *novo = new Node{key, pos->next};
    pos->next = novo;
}

bool LinkedList::remove_after(Node *pos)
{
    Node *aux = pos->next;
    pos->next = pos->next->next;
    delete aux;

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

bool LinkedList::removePos(int pos)
{
    Node *aux = this->head;
    if (pos == 0)
    {
        pop_front();
        return true;
    }

    int siz = size();
    for (int i = 0; i < pos - 1 && aux; i++)
    {
        aux = aux->next;
    }

    if (!aux || !aux->next)
        return false;

    Node *auxx = aux->next;
    aux->next = aux->next->next;
    delete auxx;

    return true;
}

bool LinkedList::removeKey(int key)
{
    Node *aux = this->head;
    if (this->head->key == key)
    {
        pop_front();
        return true;
    }
    while (aux)
    {
        if (aux->key == key)
        {
            Node *auxx = aux->next;
            aux->next = aux->next->next;
            delete auxx;
            return true;
        }
        aux = aux->next;
    }

    return false;
}

bool LinkedList::pop_back()
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

bool LinkedList::empty()
{
    if (this->head == nullptr)
        return true;

    return false;
}

bool LinkedList::insert_sorted(int key){
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

Node *LinkedList::getPos(int pos)
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

void LinkedList::print_last()
{
    Node *aux = this->head;
    while (aux->next)
    {
        aux = aux->next;
    }

    cout << "Último: " << aux->key << ".";
    cout << endl;
}

bool LinkedList::is_sorted()
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

bool LinkedList::push_backVet(int n, int* vec)
{
    for (int i = 0; i < n; i++)
    {
        push_back(vec[i]);
    }

    return true;
}

LinkedList* LinkedList::deep_copy()
{
    LinkedList *newList = new LinkedList();

    if (this->head == nullptr)
    {
        return newList;
    }

    Node *aux = this->head;
    newList->head = new Node{aux->key, nullptr};
    Node *auxNewList = newList->head;
    aux = aux->next;

    while (aux != nullptr)
    {
        auxNewList->next = new Node{aux->key, nullptr};
        auxNewList = auxNewList->next;
        aux = aux->next;
    }

    return newList;
}

LinkedList* LinkedList::concat(LinkedList *list2)
{
    LinkedList *concatList = new LinkedList();

    Node *auxList2 = list2->head;
    Node *aux = this->head;

    if (this->head == nullptr && list2->head == nullptr)
    {
        return concatList;
    }

    if (aux != nullptr)
    {
        concatList->head = new Node{aux->key, nullptr};
        aux = aux->next;
    }
    else
    {
        concatList->head = new Node{auxList2->key, nullptr};
        auxList2 = auxList2->next;
    }

    Node *auxNewList = concatList->head;

    while (aux != nullptr)
    {
        auxNewList->next = new Node{aux->key, nullptr};
        auxNewList = auxNewList->next;
        aux = aux->next;
    }

    while (auxList2 != nullptr)
    {
        auxNewList->next = new Node{auxList2->key, nullptr};
        auxNewList = auxNewList->next;
        auxList2 = auxList2->next;
    }

    return concatList;
}

LinkedList* LinkedList::merge(LinkedList *list2)
{
    LinkedList *mergeList = new LinkedList();

    Node *auxList2 = list2->head;
    Node *aux = this->head;

    if (this->head == nullptr && list2->head == nullptr)
    {
        return mergeList;
    }

    Node *auxMerge = nullptr;

    if (aux != nullptr && (auxList2 == nullptr || aux->key <= auxList2->key))
    {
        mergeList->head = new Node{aux->key, nullptr};
        aux = aux->next;
    }
    else if (auxList2 != nullptr)
    {
        mergeList->head = new Node{auxList2->key, nullptr};
        auxList2 = auxList2->next;
    }

    auxMerge = mergeList->head;

    while (aux != nullptr && auxList2 != nullptr)
    {
        if (aux->key <= auxList2->key)
        {
            auxMerge->next = new Node{aux->key, nullptr};
            aux = aux->next;
        }
        else
        {
            auxMerge->next = new Node{auxList2->key, nullptr};
            auxList2 = auxList2->next;
        }
        auxMerge = auxMerge->next;
    }

    while (aux != nullptr) {
        auxMerge->next = new Node{aux->key, nullptr};
        auxMerge = auxMerge->next;
        aux = aux->next;
    }

    while (auxList2 != nullptr) {
        auxMerge->next = new Node{auxList2->key, nullptr};
        auxMerge = auxMerge->next;
        auxList2 = auxList2->next;
    }

    return mergeList;
}