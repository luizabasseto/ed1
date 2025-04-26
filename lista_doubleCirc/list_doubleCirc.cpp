#include "circle_double_list.h"
#include <stdio.h>
#include <iostream>

using namespace std;

CircleDoubleList::CircleDoubleList() {
  this->head = nullptr;
  this->tail = nullptr;
}

CircleDoubleList::~CircleDoubleList() {

}  

bool CircleDoubleList::push_front(int key){
  Node* novo = new Node{key, this->head};
  if (!this->head) {
    this->head = novo;
    this->tail = novo;
  } else {
    this->tail->next = novo;
  }
  this->tail = novo;
  return true;
}

bool CircleDoubleList::pop_front() {
  if (!this->head) {
    return false; // List is empty
  }
  Node* temp = this->head;
  this->head = this->head->next;
  delete temp;
  if (!this->head) {
    this->tail = nullptr; // lista fica vazia
  } else {
    this->tail->next = this->head; // mantendo a propriedade circular
  }
  return true;
}

bool CircleDoubleList::push_back(int key) {
  return true;
}

bool CircleDoubleList::equals(CircleDoubleList* other) {
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

int CircleDoubleList::get(int pos) {
  return 0;
}

void CircleDoubleList::print() {
  Node* aux = this->head;
  if (!aux) {
    cout << "Lista vazia" << endl;
    return;
  }
  do {
    cout << aux->key << " ";
    aux = aux->next;
  } while (aux != this->head);
  cout << endl;
}

int CircleDoubleList::size() {
  if (!this->head) {
    return 0;
  }
  int count = 0;
  Node* aux = this->head;
  do {
    count++;
    aux = aux->next;
  } while (aux != this->head);
  return count;
}

Node* CircleDoubleList::find(int key) {
  return nullptr;
}

void CircleDoubleList::insert_after(int key, Node* pos) {
  if (!pos) {
    return;
  }
  Node* novo = new Node{key, pos->next};
  pos->next = novo;
  if (novo->next == this->head) {
    this->tail = novo; // atualiza o tail se necessário
  }
  novo->prev = pos; // atualiza o ponteiro prev do novo nó
  pos->next = novo; // atualiza o ponteiro next do nó anterior
}

bool CircleDoubleList::remove_after(Node* pos) {
  return true;
}

bool CircleDoubleList::insert(int pos, int key) {
  if (pos < 0 || pos > this->size()) {
    return false; // posição inválida
  }
  if (pos == 0) {
    return this->push_front(key);
  }
  Node* current = this->head;
  for (int i = 0; i < pos - 1; i++) {
    current = current->next;
  }
  Node* novo = new Node{key, current->next};
  current->next = novo;
  novo->prev = current; // atualiza o ponteiro prev do novo nó
  if (novo->next) {
    novo->next->prev = novo; // atualiza o ponteiro prev do próximo nó
  } else {
    this->tail = novo; // atualiza o tail se necessário
  }
  return true;
}

bool CircleDoubleList::remove_at(int pos) {
  return true;
}

bool CircleDoubleList::remove(int key) {
  return true;
}

bool CircleDoubleList::pop_back() {
  return true;
}

bool CircleDoubleList::empty() {
  return true;
}
