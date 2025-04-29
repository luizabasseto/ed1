#include "list_doubleCirc.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

CircleDoubleList::CircleDoubleList()
{
  this->head = nullptr;
}

CircleDoubleList::~CircleDoubleList()
{
}

bool CircleDoubleList::push_front(int key)
{
  Node *novo = new Node(key);

  if (!this->head)
  { // Lista vazia
    novo->next = novo;
    novo->prev = novo;
    this->head = novo;
  }
  else
  { // Lista não vazia
    novo->next = this->head;
    novo->prev = this->head->prev;
    this->head->prev->next = novo;
    this->head->prev = novo;
    this->head = novo;
  }

  return true;
}

bool CircleDoubleList::pop_front()
{
  if (!this->head)
  {
    return false; // Lista vazia
  }

  if (this->head->next == this->head)
  {
    // Só existe 1 elemento
    delete this->head;
    this->head = nullptr;
  }
  else
  {
    Node *temp = this->head;
    this->head->prev->next = this->head->next;
    this->head->next->prev = this->head->prev;
    this->head = this->head->next;
    delete temp;
  }

  return true;
}

bool CircleDoubleList::push_back(int key)
{
  Node *novo = new Node(key);

  if (!this->head)
  {
    novo->next = novo;
    novo->prev = novo;
    this->head = novo;
  }
  else
  { // Lista não vazia
    novo->prev = this->head->prev;
    novo->next = this->head;
    this->head->prev->next = novo;
    this->head->prev = novo;
  }
}

bool CircleDoubleList::equals(CircleDoubleList *other)
{
  if (this->size() != other->size())
    return false;
  Node *current1 = this->head;
  Node *current2 = other->head;
  do
  {
    if (current1->key != current2->key)
      return false;
    current1 = current1->next;
    current2 = current2->next;
  } while (current1!=this->head && current2!=this->head);
  return true;
}

int CircleDoubleList::get(int pos)
{
  if (pos == 0)
    return this->head->key;
  int n = 0;
  Node *aux = this->head;
  do
  {
    if (n == pos)
    {
      return aux->key;
    }
    n++;
    aux = aux->next;
  } while (aux != this->head);

  return 0;
}

void CircleDoubleList::print()
{
  Node *aux = this->head;
  if (!aux)
  {
    cout << "Lista vazia" << endl;
    return;
  }
  do
  {
    cout << aux->key << " ";
    aux = aux->next;
  } while (aux != this->head);
  cout << endl;
}

int CircleDoubleList::size()
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

Node *CircleDoubleList::find(int key)
{
  Node *aux = this->head;
  do
  {
    if (aux->key == key)
      return aux;
    aux = aux->next;
  } while (aux != this->head);

  return nullptr;
}

void CircleDoubleList::insert_after(int key, Node *pos)
{
  if (!pos)
    return;

  Node *novo = new Node(key);

  novo->next = pos->next;
  novo->prev = pos;

  pos->next->prev = novo;
  pos->next = novo;

  if (pos == this->head->prev)
  {
    // Atualizar o tail (prev do head)
    this->head->prev = novo;
  }
}

bool CircleDoubleList::remove_after(Node *pos)
{
  Node *aux = pos->next;
  pos->next = aux->next;
  aux->next->prev = pos;
  if (pos == this->head->prev)
  {
    this->head->next->prev = pos;
  }
  delete aux;
  return true;
}

bool CircleDoubleList::insert(int pos, int key)
{
  if (pos < 0 || pos > this->size())
  {
    return false; // posição inválida
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
  Node *novo = new Node{key};
  novo->prev = current; // atualiza o ponteiro prev do novo nó
  novo->next = current->next;
  if (novo->next)
  {
    novo->next->prev = novo; // atualiza o ponteiro prev do próximo nó
  }
  current->next = novo;

  return true;
}

bool CircleDoubleList::remove_at(int pos)
{
  Node *aux = this->head;
  if (pos < 0 || pos > size())
  {
    return false;
  }
  else
  {
    for (int i = 0; i < pos - 1; i++)
    {
      aux = aux->next;
    }
  }

  Node *auxx = aux->next;
  aux->next->next->prev = aux;
  aux->next = aux->next->next;
  delete auxx;

  return true;
}

bool CircleDoubleList::remove(int key)
{
  Node *aux = this->head;

  do
  {
    if (aux->key == key)
    {
      break;
    }
    aux = aux->next;
  } while (aux != this->head);
  if (!aux)
    return false;

  aux->next->prev = aux->prev;
  aux->prev->next = aux->next;
  delete aux;
  return true;
}

bool CircleDoubleList::pop_back()
{
  Node *aux = this->head->prev;
  if (!aux)
    return false;
  aux->prev->next = this->head;
  this->head->prev = aux->prev;
  delete aux;
  return true;
}

bool CircleDoubleList::empty()
{
  if (this->head == nullptr)
    return true;
  return false;
}

bool CircleDoubleList::insert_sorted(int key)
{
  if (!this->head)
  {
    // Lista vazia, cria novo nó sozinho
    Node *novo = new Node(key);
    novo->next = novo;
    novo->prev = novo;
    this->head = novo;
    return true;
  }

  Node *aux = this->head;
  do
  {
    if (key < aux->key)
    {
      break;
    }
    aux = aux->next;
  } while (aux != this->head);

  Node *novo = new Node(key, aux->prev, aux);

  aux->prev->next = novo;
  aux->prev = novo;

  if (aux == this->head && key < this->head->key)
  {
    // Inserimos antes do head, então head precisa ser atualizado
    this->head = novo;
  }

  return true;
}