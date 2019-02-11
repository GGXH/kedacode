#ifndef SLL_H
#define SLL_H

class node {
 public:
  node(int d) : d_data(d), d_next(nullptr) {}
  ~node() { }
  
  node* next() { return d_next; }
  int data() { return d_data; }
  void setNext(node* nn) { d_next = nn; }

 private:
  int d_data;
  node* d_next;
};

#endif
