#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* next;

	node(int newData) { //constructor
		this->data = newData;
	}
};

void insert(node* &head, int data) //insert at head
{
	node* n = new node(data);
	node*temp = head;
	n->next = head;

	if (head != NULL)
	{
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = n;
	}
	else
	{
		n->next = n;
	}

	head = n;
}

void print(node* head) {

	node* temp = head;

	while (temp->next != head)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << " ";
}

node* get_node(node* &head, int data) {
	node* temp = head;

	while (temp->next != head) {
		if (temp->data == data) return temp;
		temp = temp->next;
	}

	if (temp->data == data) return temp;
	else return NULL;
}

void delete_node(node* &head, int data) {

	node* tobedeleted = get_node(head, data);

	if (tobedeleted == NULL)
	{
		cout << "node_is_not present with this value" << endl;
		return;
	}

	if (head == tobedeleted) {

		head = tobedeleted->next;
	}

	node* temp = head;
	while (temp->next != tobedeleted) {
		temp = temp->next;
	}
	temp->next = tobedeleted->next;

	delete tobedeleted;
}


int main()
{


	node*head = NULL;

	insert(head, 10);
	insert(head, 20);
	insert(head, 30);
	insert(head, 40);
	insert(head, 50);

	print(head);

	cout << endl;

	delete_node(head, 30);
	print(head);

	cout << endl;

	return 0;
}
