#pragma once

// Definicao do TAD Lista Encadeada

class Node {
public:
    int key;
    Node* next;
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();
    
    bool push_front(int key); //feito
    bool pop_front(); //feito
    
    void print(); //feito
    int size(); //feito
    bool empty(); //feito
    
    bool push_back(int key); //feito
    bool pop_back(); //feito
    
    int get(int pos); //feito
    Node* find(int key); //feito
    
    void insert_after(int key, Node* pos); //feito
    bool remove_after(Node* pos); //feito
    
    bool insert(int key, int pos); //feito

    bool removePos(int pos); //feito
    bool removeKey(int key); //feito
    
    bool insert_sorted(int key);

    bool equals(LinkedList* other); //feito
};