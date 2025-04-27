#include "list_circ.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

CircleList::CircleList()
{
  this->head = nullptr;
  this->tail = nullptr;
}

CircleList::~CircleList()
{
  Node *current = this->head;
  while (current)
  {
    Node *next = current->next;
    delete current;
    current = next;
  }
  this->head = nullptr;
  this->tail = nullptr;
}

bool CircleList::push_front(int key)
{
  Node *novo = new Node{key, this->head};
  if (!this->head)
  {
    this->head = novo;
    this->tail = novo;
  }
  else
  {
    this->tail->next = novo;
    this->tail = novo;
  }
  return true;
}

bool CircleList::pop_front()
{
  if (!this->head)
  {
    return false; // List is empty
  }
  Node *temp = this->head;
  this->head = this->head->next;
  delete temp;
  if (!this->head)
  {
    this->tail = nullptr; // lista fica vazia
  }
  else
  {
    this->tail->next = this->head; // mantendo a propriedade circular
  }
  return true;
}

bool CircleList::push_back(int key)
{
  Node *novo = new Node{key, this->tail};
  this->tail = novo;
  this->tail->next = this->head;

  return true;
}

bool CircleList::equals(CircleList *other)
{
  if (this->size() != other->size())
    return false;
  Node *current1 = this->head;
  Node *current2 = other->head;
  while (current1 && current2)
  {
    if (current1->key != current2->key)
      return false;
    current1 = current1->next;
    current2 = current2->next;
  }
  return true;
}

int CircleList::get(int pos)
{
  Node *aux = this->head;
  int n = 0;
  while (aux != this->head)
  {
    if (n == pos)
      return aux->key;
    aux = aux->next;
    n++;
  }

  return 0;
}

void CircleList::print()
{
  if (!this->head)
  {
    cout << "Lista vazia" << endl;
    return;
  }
  Node *aux = this->head;
  do
  {
    cout << aux->key << " ";
    aux = aux->next;
  } while (aux != this->head);
  cout << endl;
}

int CircleList::size()
{
  if (!this->head)
  {
    return 0;
  }
  int count = 0;
  Node *aux = this->head;
  do
  {
    count++;
    aux = aux->next;
  } while (aux != this->head);
  return count;
}

Node *CircleList::find(int key)
{
  Node *aux = this->head;
  while (aux != this->head)
  {
    if (aux->key == key)
    {
      return aux;
    }
    aux = aux->next;
  }
  return nullptr;
}

void CircleList::insert_after(int key, Node *pos)
{
  if (!pos)
  {
    return;
  }
  Node *novo = new Node{key, pos->next};
  pos->next = novo;
  if (pos == this->tail)
  {
    this->tail = novo; // Atualiza o tail se o nó inserido for o último
  }
}

bool CircleList::remove_after(Node *pos)
{
  if (!pos)
  {
    return false;
  }
  Node *aux = pos->next;
  pos->next = aux->next;
  if (pos == this->tail)
  {
    this->tail = this->head;
  }
  delete aux;
  return true;
}

bool CircleList::insert(int pos, int key)
{
  if (pos < 0 || pos > this->size()) // fazer para inserir da mesma forma mesmo que seja inválido
  {
    return false; // Posição inválida
  }
  if (pos == 0)
  {
    return this->push_front(key);
  }
  Node *current = this->head;
  for (int i = 0; i < pos - 1; i++)
  {
    current = current->next;
  }
  Node *novo = new Node{key, current->next};
  current->next = novo;
  if (current == this->tail)
  {
    this->tail = novo; // Atualiza o tail se o nó inserido for o último
  }
  return true;
}

bool CircleList::remove_at(int pos)
{
  int n = 0;
  Node *aux = this->head;
  if (pos == 0)
  {
    pop_front();
    return true;
  }
  for (int i = 0; i < pos - 1 && aux; i++)
  {
    aux = aux->next;
  }

  if (!aux || !aux->next)
    return false;

  Node *auxx = aux->next;
  aux->next = aux->next->next;
  if (aux->next == this->tail) // se o último nó for removido, tail aponta para o anterior a ele.
  {
    this->tail = aux;
  }

  delete auxx;

  return true;
}

bool CircleList::remove(int key)
{
  Node *aux = this->head;
  while (aux != this->head)
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

bool CircleList::pop_back()
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
  this->tail= prev;
  prev->next = this->head;
  return true;
}

bool CircleList::empty()
{
  if (this->head==nullptr)
    return true;
  
    return false;
}
