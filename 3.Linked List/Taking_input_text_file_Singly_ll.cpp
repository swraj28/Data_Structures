#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* next;  //pointer to the next node.

	//constructor for the node
	node(int newData) {
		this->data = newData;
		this->next = NULL;
	}
};

void display(node*head) {
	// node* temp = head;

	while (head != NULL) {
		cout << head->data << "->";
		head = head->next;
	}

	cout << "NULL" << endl;
}

// Passing the pointer by address

void insertAtHead(node* &head, int data) {

	// We are doing dynamic memory allocation as doing static memory allocation once the function call is over the memory is going to destroy.
	// but we don't want the memory to be destroyed after the function call. The node needs to remain in the memory.
	// That's why are doing dynamic memory allocations.


	// If we want to access the data member of any obejct :-
	// 1.Derefrence the object and use dot operator eg:-(*node).next=null
	// 2. using the arrow operator eg:- node->next=null

	node* n = new node(data);
	n->next = head;
	head = n;
}



//Taking input from a text file
node* take_input() {

	node*head = NULL;
	int d;

	while (cin >> d) {  //When the input buffer will not recieve input it will automatically terminate.
		insertAtHead(head, d);
	}

	return head;
}

int main() {

	node* head = take_input();

	display(head);

	return 0;
}