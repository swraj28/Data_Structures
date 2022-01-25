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

	node* n = new node(data);
	n->next = head;
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

	node* n = new node(data);//pointer to the new
	temp->next = n;
}

void deleteAtTail(node *head) { //call by value??

	node* temp = head;

	while (temp->next->next != NULL) {
		temp = temp->next;
	}

	node* toBeDeleted = temp->next;
	temp->next = NULL;
	delete toBeDeleted;
}

void insertAtIndex(node* &head, int data, int position) {

	if (position <= 1 or head == NULL) { //position==0
		insertAtHead(head, data);
		return;
	}

	if (position >= length(head)) {
		insertAtTail(head, data);
		return;
	}

	node* temp = head;

	int steps = 1;

	while (steps < (position - 1)) {
		temp = temp->next;
		steps++;
	}

	node* n = new node(data);

	n->next = temp->next;
	temp->next = n;
}

void deleteAtHead(node* &head) {
	if (head == NULL) {
		return;
	}

	node* toBeDeleted = head;

	head = head->next;

	delete toBeDeleted;
}

void deleteAtAnyIndex(node* &head, int position) {

	if (position == 1) {
		deleteAtHead(head);
		return;
	}

	if (position == length(head)) {
		deleteAtTail(head);
	}

	node* temp = head;
	int steps = 1;

	while (steps < position - 1) {
		temp = temp->next;
		steps++;
	}

	node* toBeDeleted = temp->next;
	temp->next = temp->next->next;
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

bool detectcycle(node* head)  //floyd cycle
{
	node* slow = head;
	node* fast = head;

	while (fast->next != NULL and fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			return true;
		}
	}

	return false;
}

void break_the_cycle(node* head) {
	node*slow = head;
	node*fast = head;

	while (fast->next != NULL and fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;


		if (slow == fast)
		{
			slow = head;

			while (slow->next != fast->next)
			{
				slow = slow->next;
				fast = fast->next;
			}

			fast->next = NULL;
		}
	}

}

void reverseIterative(node* &head) {  //reverse a linked list (iterative)

	node* prev = NULL;
	node* curr = head;

	while (curr != NULL) {
		//save the next node
		node* n = curr->next;

		// make the current node point to previous
		curr->next = prev;

		//just update the previous and current
		prev = curr;
		curr = n;
	}

	head = prev;	//head of the linked list is previous
}

node* reverseRecursive(node* head) {       //reverse the linked list (recursively).the function is returning head pointer so its type will be node*.
	if (head == NULL or head->next == NULL) {
		return head;
	}

	node* newHead = reverseRecursive(head->next);

	node* curr = head;
	curr->next->next = curr;
	curr->next = NULL;
	return newHead;
}

// Insertion Sort in a Linked List

node* insert(node *&h1, node* n1) { //we assume that h1 is a sorted list and we have to insert a node n
	if (h1 == NULL or h1->data >= n1->data) {
		node* n = new node(n1->data);
		n->next = h1;
		h1 = n;
	} else {
		node*curr = h1;
		while (curr->next != NULL and curr->next->data < n1->data) {
			curr = curr->next;
		}
		node* n = new node(n1->data);
		n->next = curr->next;
		curr->next = n;
	}
	return h1;
}

node* insertion_sort(node* head) {//iterative o(n^2)
	if (head == NULL or head->next == NULL)return head;

	node*h1 = NULL; //empty sorted list;
	node *curr = head;
	while (curr != NULL) {
		h1 = insert(h1, curr);
		curr = curr->next;
	}
	return h1;
}

node* merge(node* a, node* b) { //merge two sorted linked list without creating another list
	if (a == NULL) {
		return b;
	}

	if (b == NULL) {
		return a;
	}

	node* c;

	if (a->data <= b->data) {
		c = a;
		c->next = merge(a->next, b);
	} else {
		c = b;
		c->next = merge(a, b->next);
	}

	return c;
}

node* mergeSort(node* head) {            //sorting an unsorted linked list
	if (head == NULL or head->next == NULL) {
		return head;
	}

	node* a = head;

	node* mid = midPoint(head);

	node* b = mid->next;
	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);

	node* c = merge(a, b);
	return c;
}

node* kReverse(node* head, int k) {
	if (head == NULL or head->next == NULL) {
		return head;
	}

	int count = 1;

	node* curr = head;
	node* prev = NULL;

	while (count <= k and curr != NULL) {
		node* n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
		count++;
	}

	head->next = kReverse(curr, k);

	return prev;
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

int main() {

	node* head = NULL; //address of the starting node

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);

	// display(head);

	insertAtTail(head, 5);
	insertAtTail(head, 15);
	insertAtTail(head, 25);

	// display(head);

	// insertAtIndex(head,789,5);

	// display(head);

	// head = kReverse(head, 3);

	display(head);

	// head = mergeSort(head);

	// display(head);

	// deleteAtAnyIndex(head,5);

	// display(head);

	// reverseIterative(head);

	// display(head);

	// head = reverseRecursive(head);

	// display(head);

	// node* mid = midPoint(head);

	// cout<<mid->data<<endl;

	// cout<<length(head)<<endl;
	// cout<<search(head,30)<<endl;
	// cout<<search(head,3)<<endl;

	// node* head1 = NULL;
	// insertAtTail(head1,1);
	// insertAtTail(head1,2);
	// insertAtTail(head1,5);
	// insertAtTail(head1,7);
	// insertAtTail(head1,8);
	// insertAtTail(head1,10);

	// node* head2 = NULL;
	// insertAtTail(head2,3);
	// insertAtTail(head2,4);
	// insertAtTail(head2,6);

	// display(head1);
	// display(head2);

	// node* mergesList = merge(head1,head2);
	// display(mergesList);

	return 0;
}