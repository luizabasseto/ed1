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
  Node *novo = new Node{key, this->head, this->head->next};
  if (!this->head)
  {
    this->head = novo;
    this->head->prev = novo;
  }
  else
  {
    this->head->prev->next = novo;
  }

  return true;
}

bool CircleDoubleList::pop_front()
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
    this->head->prev = nullptr; // lista fica vazia
  }
  else
  {
    this->head->prev->next = this->head; // mantendo a propriedade circular
  }
  return true;
}

bool CircleDoubleList::push_back(int key)
{
  Node *novo = new Node(key, this->head->prev, this->head);
  this->head->prev = novo;
  novo->next = this->head;
  if (!novo)
    return false;

  return true;
}

bool CircleDoubleList::equals(CircleDoubleList *other)
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
  {
    return;
  }
  Node *novo = new Node{key, pos->next};
  pos->next = novo;
  if (novo->next == this->head)
  {
    this->head->prev = novo; // atualiza o tail se necessário
  }
  novo->prev = pos; // atualiza o ponteiro prev do novo nó
  pos->next = novo; // atualiza o ponteiro next do nó anterior
}

bool CircleDoubleList::remove_after(Node *pos)
{
  Node aux = pos->next;
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
  Node *novo = new Node{key, current->next};
  current->next = novo;
  novo->prev = current; // atualiza o ponteiro prev do novo nó
  if (novo->next)
  {
    novo->next->prev = novo; // atualiza o ponteiro prev do próximo nó
  }
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

  Node* auxx = aux->next;
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

bool CircleDoubleList::insert_sorted(int key){
  Node* aux = this->head;
  do{
    if(key<aux->key){
      break;
    }
    aux= aux->next;
  } while(aux!=this->head);

  Node* novo = new Node(key, aux->prev, aux);
  if(!novo) return false;
  aux->prev->next = novo;
  aux->prev = novo;
  return true;
}