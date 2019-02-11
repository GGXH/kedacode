#include "dequeue_array.h"

#include <iostream>
#include <vector>

size_t dequeue_array::indexBefore(size_t indx) {
  if ( indx == 0 ) {
    return d_capability - 1;
  }
    
  return indx - 1;
}
  
size_t dequeue_array::indexAfter(size_t indx) {
  if ( indx == d_capability - 1) {
    return 0;
  }
    
  return indx + 1;
}
  
bool dequeue_array::isFull() {
  return d_size == d_capability;
}


bool dequeue_array::isEmpty() {
  return d_size == 0;
}

void dequeue_array::doubleSize() {
  std::vector<int>* tmp = new std::vector<int>(2 * d_capability);
   
  size_t indx = d_start;
  size_t i = 0;
  tmp->at(i) = d_data->at(indx);
  while ( indx != d_end ) {
    indx = indexAfter(indx);
    ++i;
    tmp->at(i) = d_data->at(indx);
  }
  d_start = 0;
  d_end = d_size - 1;
  d_capability *= 2;
  delete d_data;
  d_data = tmp;
}


void dequeue_array::clear() {
  d_size = 0;
  d_start = 0;
  d_end = 0;
}

bool dequeue_array::insertFront(const int& data) {
  if ( isFull() ) {
    doubleSize();
  }
  
  size_t new_start;
  if ( isEmpty() ) {
    new_start = 0;
    d_start = 0;
    d_end = 0;
  } else {
    new_start = indexBefore(d_start);
  }
  d_data->at(new_start) = data;
  d_start = new_start;
  ++d_size;
}


int dequeue_array::removeFront() {
  if ( isEmpty() ) {
    throw "dequeue is empty";
  }
  
  size_t new_start = indexAfter(d_start);
  int data = d_data->at(d_start);
  d_start = new_start;
  --d_size;
  return data;
}



bool dequeue_array::insertLast(const int& data) {
  if ( isFull() ) {
    doubleSize();
  }
  
  size_t new_end;
  if (isEmpty() ) {
    new_end = 0;
    d_start = 0;
    d_end = 0;
  } else {
    new_end = indexAfter(d_end);
  }
  d_data->at(new_end) = data;
  d_end = new_end;
  ++d_size;
}


int dequeue_array::removeLast() {
  if ( isEmpty() ) {
    throw "dequeue is empty";
  }
  
  size_t new_end = indexBefore(d_end);
  int data = d_data->at(d_end);
  d_end = new_end;
  --d_size;
  return data;
}


int dequeue_array::peekFront() {
  if ( isEmpty() ) {
    throw "dequeue is empty";
  }
  
  return d_data->at(d_start);
}

int dequeue_array::peekLast() {
  if ( isEmpty() ) {
    throw "dequeue is empty";
  }
  
  return d_data->at(d_end);
}


void dequeue_array::showDequeue() {
  size_t indx = d_start;
  size_t i = 0;
  std::cout << "Dequeu: ";
  if ( !isEmpty() ) {
    std::cout << d_data->at(indx) << " ";
    while ( indx != d_end ) {
      indx = indexAfter(indx);
      std::cout << d_data->at(indx) << " ";
    }
  }
  std::cout << std::endl;
}

void dequeue_array::showData() {
  std::vector<int>::const_iterator it = d_data->begin();
   
  std::cout << "Data: ";
  if ( !isEmpty() ) {
    for(; it != d_data->end(); ++it) {
      std::cout << *it << " ";
    }
  }
  std::cout << std::endl;
}

