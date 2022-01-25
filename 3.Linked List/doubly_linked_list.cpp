#include<bits/stdc++.h>
using namespace std;

class node {
public:

	int data;
	node*next;
	node*prev;

	node(int newData) {
		this->data = newData;
		this->next = NULL;
		this->prev = NULL;
	}
};

void display(node *head) { // Since here we are passing the head pointer by value so we don't need to create any temp variable

	while (head != NULL) {
		cout << head->data << "->";
		head = head->next;
	}

	cout << "NULL" << endl;
}

int length(node *head) {

	int len = 0;

	node* temp = head;

	while (temp != NULL) {
		len++;
		temp = temp->next;
	}

	return len;
}

bool search(node *head, int item) {

	node* temp = head;

	while (temp != NULL) {
		if (item == temp->data) {
			return true;
		}
		temp = temp->next;
	}

	return false;
}

// Passing the pointer by address

void insertAtHead(node* &head, int data) {

	// We are doing dynamic memory allocation as doing static memory allocation once the function call is over the memory is going to destroy.
	// but we don't want the memory to be destroyed after the function call. The node needs to remain in the memory.
	// That's why are doing dynamic memory allocations.


	// If we want to access the data member of any obejct :-
	// 1.Derefrence the object and use dot operator eg:-(*node).next=null
	// 2. using the arrow operator eg:- node->next=null

	if (head == NULL) {
		node* n = new node(data);
		head = n;
		return;
	}

	node* n = new node(data);
	n->next = head;
	head->prev = n;
	head = n;
}

void insertAtTail(node* &head, int data) { //it is similar to the push_back() functionality of vector

	if (head == NULL) {          //(head==null)signifies that the linked list is not created and in that case inserting at head or tail will have same significance
		insertAtHead(head, data);
		return;
	}

	node* temp = head;   //the address of head is being stored in temp.

	while (temp->next != NULL) {
		temp = temp->next;
	}

	node* n = new node(data); //pointer to the new node
	temp->next = n;
	n->prev = temp;
}

void deleteAtTail(node *head) { //call by value??

	node* temp = head;

	while (temp->next->next != NULL) {
		temp = temp->next;
	}

	node* toBeDeleted = temp->next;
	temp->next = NULL;
	toBeDeleted->prev = NULL;

	delete toBeDeleted;
}

void insertAtIndex(node* &head, int data, int position) {  // 0 based indexing

	if (position < 1 or head == NULL) { //position==0
		insertAtHead(head, data);
		return;
	}

	if (position == length(head)) {
		insertAtTail(head, data);
		return;
	}

	node* temp = head;

	while (position > 1) {
		temp = temp->next;
		position--;
	}

	node* n = new node(data);

	n->next = temp->next;
	temp->next->prev = n;
	temp->next = n;
	n->prev = temp;
}

void deleteAtHead(node* &head) {
	if (head == NULL) {
		return;
	}

	node* toBeDeleted = head;

	head = head->next;

	head->prev = NULL;
	toBeDeleted->next = NULL;

	delete toBeDeleted;
}

void deleteAtAnyIndex(node* &head, int position) {  // 0 based indexing

	if (position == 0) {
		deleteAtHead(head);
		return;
	}

	if (position == (length(head) - 1)) {
		deleteAtTail(head);
	}

	node* temp = head;

	while (position > 1) {
		temp = temp->next;
		position--;
	}

	node* toBeDeleted = temp->next;

	temp->next = temp->next->next;
	temp->next->next->prev = temp;

	// Removing the pointers of the node to be deleted.
	toBeDeleted->next = NULL;
	toBeDeleted->prev = NULL;

	delete toBeDeleted;
}

node* midPoint(node* head) { //to find the midpoint of the linkelist (runners technique)

	node* slow = head;
	node* fast = head;

	while (fast->next != NULL and fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}


bool detectAndRemoveLoopInDLL(node* head) {

	node* last = NULL;

	while (head) {

		if (last && last != head->prev) {

			cout << "Loop found at: " << head->data << endl;
			last->next = NULL;
			return true;
		}

		last = head;
		head = head->next;
	}

	cout << "No loop found" << endl;
	return false;
}

void reverseIterative(node* &head) {  //reverse a linked list (iterative)

}

node* reverseRecursive(node* head) {

}



// Cascading of Operator
// cout is an object of ostream class
ostream& operator<<(ostream &os, node *head) {  // Overloading the << operator
	display(head);
	return os;
}

node* take_input() {

	int d;
	cin >> d;

	node* head = NULL;

	while (d != -1) {
		insertAtHead(head, d);

		cin >> d;
	}

	return head;
}

//Overaloading the >> operator
// cin is an object of istram class.

istream& operator>>(istream &is, node* &head) {
	head = take_input();
	return is;
}


int main() {



	return 0;
}