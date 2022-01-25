#include<bits/stdc++.h>
using namespace std;
#define ll long long

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
// Functions to swap the two node without cretaing any copy

void swap(node* &head, int x, int y) {

	//If both x and y are same
	if (x == y) {
		return;
	}

	//search for x
	node* x_prev = NULL;
	node* x_curr = head;

	while (x_curr != NULL and x_curr->data != x) {
		x_prev = x_curr;
		x_curr = x_curr->next;
	}

	//search for y
	node* y_prev = NULL;
	node* y_curr = head;

	while (y_curr != NULL and y_curr->data != y) {
		y_prev = y_curr;
		y_curr = y_curr->next;
	}

	// x and y not present
	if (x_curr == NULL or y_curr == NULL) {
		return;
	}

	//if x is not the head node
	if (x_prev != NULL) {
		x_prev->next = y_curr;
	} else {
		head = y_curr;
	}

	//If y is not the head node
	if (y_prev != NULL) {
		y_prev->next = x_curr;
	} else {
		head = x_curr;
	}

	node*temp = y_curr->next;
	y_curr->next = x_curr->next;
	x_curr->next = temp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



	return 0;
}