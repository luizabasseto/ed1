#include "double_list.h"
#include <stdio.h>
#include <iostream>

using namespace std;

DoubleList::DoubleList() {
  this->head = nullptr;
  this->tail = nullptr;
}

DoubleList::~DoubleList() {

}  

bool DoubleList::push_front(int key){
  Node* newNode = new Node{key, this->tail, nullptr};
  if (!newNode)
    return false;
  newNode->next = this->head;
  this->head = newNode;
  if (newNode->next)
    newNode->next->prev = newNode;
  else
    this->tail = newNode;
  return true;
}

bool DoubleList::pop_front() {
  if (this->head) {
    Node* aux = this->head;
    this->head = aux->next;
    if (!this->head)
      this->tail = nullptr;
    delete aux;
    return true;
  } else
    return false;
}

bool DoubleList::push_back(int key) {
    if (this->tail)
    {
        Node* novo = new Node{key,this->tail,nullptr};
        this->tail = novo;
        this->tail->prev->next= this->tail;
    } else{

    }
    
  return true;
}

bool DoubleList::equals(DoubleList* other) {
  if (this->size() != other->size())
    return false;
  Node* current1 = this->head;
  Node* current2 = other->head;
  while (current1 && current2) {
    if (current1->key != current2->key)
      return false;
    current1 = current1->next;
    current2 = current2->next;
  }
  return true;
}

int DoubleList::get(int pos) {
  return 0;
}

void DoubleList::print() {
  Node* current = this->head;
  while (current) {
    cout << current->key << " ";
    current = current->next;
  }
  printf("\n");
}

int DoubleList::size() {
  int n = 0;
  Node* aux = this->head;
  while (aux) {
    aux = aux->next;
    n++;
  }
  return n;
}

Node* DoubleList::find(int key) {
  return nullptr;
}

void DoubleList::insert_after(int key, Node* pos) {
  Node* novo = new Node{key, pos->next};
  pos->next = novo;
}

bool DoubleList::remove_after(Node* pos) {
  return true;
}

bool DoubleList::insert(int pos, int key) {
  if (pos == 0)
    return this->push_front(key);
  Node* aux = this->head;
  for (int i = 0; i < pos - 1 && aux; i++)
    aux = aux->next;
  if (!aux)
    return this->push_back(key);
  Node* novo = new Node{key, aux->next};
  aux->next = novo;
  aux->next->prev = novo;
  
  return true;
}

bool DoubleList::remove_at(int pos) {
  return true;
}

bool DoubleList::remove(int key) {
  return true;
}

bool DoubleList::pop_back() {
  return true;
}

bool DoubleList::empty() {
  return true;
}
