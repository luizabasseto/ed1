#pragma once

class Node
{
public:
    int key;
    Node *next;

    Node(int k, Node *n = nullptr) : key(k), next(n) {}
};

class CircleList
{
private:
    Node *head;
    Node *tail;

public:
    CircleList();
    ~CircleList();

    bool push_front(int key); // feito
    bool pop_front();         // feito

    void print(); // feito
    int size();   // feito
    bool empty(); // feito

    bool push_back(int key); // feito
    bool pop_back();         // feito

    int get(int pos);    // feito
    Node *find(int key); // feito

    void insert_after(int key, Node *pos); // feito
    bool remove_after(Node *pos);          // feito

    bool insert(int pos, int key);
    bool remove_at(int pos); // feito
    bool remove(int key);    // feito

    bool insert_sorted(int key);

    bool equals(CircleList *other); // feito
};