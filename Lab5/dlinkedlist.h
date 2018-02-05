#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

using namespace std;

struct Node {
   int data;
   Node* next;
   Node* tail;
   Node* prev;
   Node(int d=0, Node* p=0, Node* n =0) : data(d), next(p), prev(n) {}
   Node* insert_after(int value);
   void delete_after();
   void display_list();
   void display_backwards();
};
Node* Node::insert_after(int value) {
   Node *p = new Node(value);
   Node *temp = p;
   p->next = next;
   p->prev = this;  
   next = p;
   return p;
}

void Node::delete_after(){
   Node *p = next;
   if (p != 0) {
      next = p->next;
      delete p;
   }
}

void Node::display_list() {
   Node *head = this;
   while(head != 0) {
      cout << head->data << " ";
      head = head->next;
   }
   cout << '\n';
}

void Node::display_backwards() {
   Node *tail = this;
   while(tail != 0) {
      cout << tail->data << " ";
      tail = tail->prev;
   }
   cout << '\n';
}
#endif