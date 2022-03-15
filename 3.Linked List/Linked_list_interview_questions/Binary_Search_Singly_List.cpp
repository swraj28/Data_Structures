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

int length(node*head) {

	int len = 0;

	node* temp = head;

	while (temp != NULL) {
		len++;
		temp = temp->next;
	}

	return len;
}


void insertAtHead(node* &head, int data) {
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

//Given a sorted List Mimic the Binary Search Operation to find a given key
//If the key is present then Print "Found" otherwise Print "Not Found".

//Link:-https://www.geeksforgeeks.org/binary-search-on-singly-linked-list/

//t.c:-O(nodes)

//At every time we are decreasing our serch space by half but the midpoint function iterates over all the
//nodes in the range

//t.c=1+2+4+.....+n/4+n/2+n (Gp haing no of terms log2(n))+1.  ----> After solving the G.P, T.c:- O(n)

// A Better appraoch also exist by using skip list  (A Linked List with self Balancing BST Like Prop) in O(root(n))

node*midpoint(node*start, node*last) {
	if (start == NULL) {
		return NULL;
	}

	node*slow = start;
	node*fast = start;

	while ((fast->next != last) and (fast->next->next != last)) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

node*Binary_search(node*head, int data) {

	if (head == NULL) {
		return NULL;
	}

	node*start = head;
	node*end = NULL;

	while (end == NULL or start != end) {

		node*mid = midpoint(start, end);

		if (mid == NULL) {
			return NULL;
		}

		if (mid->data == data) {
			return mid;
		}

		if (mid->data < data) {
			start = mid->next;
		} else {
			end = mid;
		}
	}

	return NULL;
}

int main() {

	node* head = NULL;
	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	insertAtTail(head, 6);

	display(head);
	// cout << length(head) << endl;

	if (Binary_search(head, 6)) {
		cout << "Found" << endl;
	} else {
		cout << "Not Found" << endl;
	}

	return 0;
}