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
    bool pop_back();
    
    int get(int pos); //feito
    Node* find(int key);
    
    void insert_after(int key, Node* pos);
    bool remove_after(Node* pos);
    
    bool insert(int key, int pos); //feito

    bool remove(int pos);
    bool remove(int key);
    
    bool insert_sorted(int key);

    bool equals(LinkedList* other); //feito
};