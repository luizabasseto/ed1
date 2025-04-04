#include "linked_list.hpp"
#include <stdio.h>

LinkedList::LinkedList() {
    this-> head = nullptr;
}

LinkedList::~LinkedList() {}  

bool LinkedList::push_front(int key){
    Node* node = new Node{key, nullptr};
    if (!node) return false;

    node-> next = this-> head;
    this-> head = node;
    return true;
}

bool LinkedList::pop_front() {
    return true;
}

bool LinkedList::push_back(int key) {
    return true;
}

bool LinkedList::equals(LinkedList* other) {
    return false;
}

int LinkedList::get(int pos) {
    return 0;
}

void LinkedList::print() {
    
}

int LinkedList::size() {
    return 0;
}

Node* LinkedList::find(int key) {
    return nullptr;
}

bool LinkedList::insert_after(int key, Node* pos) { //após find
    return true;
}

bool LinkedList::remove_after(Node* pos) {
    return true;
}

bool LinkedList::insert(int pos) {
    return true;
}

bool LinkedList::remove(int pos) {
    return true;
}

bool LinkedList::remove(int key) {
    return true;
}

bool LinkedList::pop_back() {
    if(empty) return false;
    
    return true;
}

bool LinkedList::empty() {
    return true;
}