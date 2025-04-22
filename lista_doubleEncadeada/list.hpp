#pragma once

// Definicao do TAD Lista Duplamente Encadeada

class Node {
public:
    int key;
    Node* next;
    Node* prev;
};


class List {
private:
    Node* head;
    Node* tail;

public:
    List();
    ~List();
    
    bool push_front(int key); //feito
    bool pop_front(); //feito
    
    void print(); 
    int size(); 
    bool empty(); //feito
    
    bool push_back(int key); //feito
    bool pop_back(); //feito
    
    int get(int pos); //feito
    Node* find(int key); 
    
    void insert_after(int key, Node* pos); 
    bool remove_after(Node* pos); 
    
    bool insert(int key, int pos); 

    bool removePos(int pos); 
    bool removeKey(int key); 
    
    bool insert_sorted(int key); 

    bool equals(LinkedList* other); //feito

    void print_last(); 

    bool is_sorted(); 

    bool push_backVet(int n, int vec*);
};