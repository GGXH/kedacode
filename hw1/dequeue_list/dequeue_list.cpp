#include "dequeue_list.h"

#include <iostream>
#include <vector>

void dequeue_list::clear() {
  node* nd = d_head;
  while (nd) {
    node* nd_a = nd->next();
    delete nd;
    nd = nd_a;
  }
  d_head = 0;
  d_tail = 0;
  d_size = 0;
}

bool dequeue_list::isEmpty() {
  return d_size == 0;
}

bool dequeue_list::insertFirst(const int& data) {
  if ( !isEmpty() ) {
    return false;
  }
  
  node* nd = new node(data);
  
  d_head = nd;
  d_tail = nd;
  d_size = 1;
  return true;
}

bool dequeue_list::insertFront(const int& data) {
  if ( isEmpty() ) {
    return insertFirst(data);
  }
  node* nd = new node(data);
  nd->setNext(d_head);
  d_head = nd;
  ++d_size;
  return true;
}


int dequeue_list::removeFront() {
  if ( isEmpty() ) {
    throw "dequeue is empty";
  }
  
  node* nd = d_head;
  d_head = nd->next();
  --d_size;
  
  if ( isEmpty() ) {
    d_tail = nullptr;
  }
  
  
  int data = nd->data();
  delete nd;
  return data;
}



bool dequeue_list::insertLast(const int& data) {
  if ( isEmpty() ) {
    return insertFirst(data);
  }
  node* nd = new node(data);
  d_tail->setNext(nd);
  d_tail = nd;
  ++d_size;
  return true;
}


int dequeue_list::removeLast() {
  if ( isEmpty() ) {
    throw "dequeue is empty";
  }
  
  if ( d_size == 1 ) {
    int data = d_tail->data();
    delete d_head;
    d_head = nullptr;
    delete d_tail;
    d_tail = nullptr;
    --d_size;
    return data;
  }
  
  node* nd = d_head;
  while ( nd->next() != d_tail ) {
    nd = nd->next();
  }
  
  int data = nd->next()->data();
  delete d_tail;
  d_tail = nd;
  --d_size;
  return data;
}


int dequeue_list::peekFront() {
  if ( isEmpty() ) {
    throw "dequeue is empty";
  }
  
  return d_head->data();
}

int dequeue_list::peekLast() {
  if ( isEmpty() ) {
    throw "dequeue is empty";
  }
  
  return d_tail->data();
}


void dequeue_list::showDequeue() {
  std::cout << "Dequeu: ";
  node* nd = d_head;
  while (nd) {
    std::cout << nd->data() << " ";
    nd = nd->next();
  }
  std::cout << std::endl;
}

