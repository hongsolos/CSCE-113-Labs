//------------------------------------------------------
//*  Doubly Linked List     By Han Hong      Lab 5     |        
//*  CSCE 113 - 501                                    |
//*  UIN: 824000237                                    |                                          
//------------------------------------------------------

#include <iostream>

using namespace std;
//Redefined Node for double linked list
struct Node {
   int data;
   Node* next;
   Node* tail;
   Node* prev;
   Node(int d=0, Node* p=0, Node* n =0) : data(d), next(p), prev(n) {}
   Node* insert_after(int value);
   Node* insert_before(int value1);
   void delete_f();
   void display_list() ;
   void display_backwards();
};

//Redefined for prev pointer
Node* Node::insert_after(int value) {
   Node *p = new Node(value);
   Node *temp = p;
   p->next = next;
   p->prev = this;  
   next = p;
   return p;
}
//Redefined delete function
void Node::delete_f(){
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

int size(Node *current, int n){
	if (current == NULL){
		return n;
	}
	n++;
	size(current->next, n);
}

int main(){
   Node *head= new Node(10);
   Node *p = head->insert_after(20);
   p = p->insert_after(30);
   p->insert_after(40);
   head->display_list();
   
   Node *tail = p->insert_after(40);
   tail->display_backwards();
   

   
 //Question 1 and 2
	cout << "Question 1 and 2: " << endl;
	Node *listh = new Node(1);
	Node *x = listh->insert_after(2);
	x = x->insert_after(3);
	x = x-> insert_after(4);
	x = x-> insert_after(5);
	x = x-> insert_after(6);
	x = x-> insert_after(7);
	x-> insert_after(8);
	listh-> display_list();
	
	Node *listt = x->insert_after(8);
	listt-> display_backwards();
	cout << size(listh,0);
}